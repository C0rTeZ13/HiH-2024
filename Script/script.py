import csv
import cv2
import numpy as np
from ultralytics import YOLO
import os
import argparse

# Загрузка модели YOLOv8
model = YOLO('parts.pt')

colors = [
    (255, 0, 0), (255, 255, 0), (255, 0, 255), (0, 255, 0), (0, 255, 255),
    (0, 0, 255), (0, 128, 255), (192, 0, 128)
]


def get_extreme_points(mask):
    """Получение крайних точек маски (верхний левый, верхний правый, нижний левый, нижний правый)."""
    points = np.column_stack(np.where(mask > 0))  # Находим все пиксели маски
    top_left = points.min(axis=0)
    bottom_right = points.max(axis=0)
    top_right = [bottom_right[0], top_left[1]]
    bottom_left = [top_left[0], bottom_right[1]]
    return np.array([top_left, top_right, bottom_right, bottom_left], dtype=np.float32)


def perspective_correction_for_mask(image, src_points, target_size=(640, 640)):
    """Применение перспективной коррекции для маски объекта."""
    # Получаем точку назначения для коррекции
    dst_points = np.array(
        [[0, 0], [target_size[0] - 1, 0], [target_size[0] - 1, target_size[1] - 1], [0, target_size[1] - 1]],
        dtype=np.float32)
    # Получаем матрицу перспективы
    matrix = cv2.getPerspectiveTransform(src_points, dst_points)
    # Применяем перспективное преобразование
    corrected_mask = cv2.warpPerspective(image, matrix, target_size)
    return corrected_mask


def process_image(image_path, standard_type, standard_mm, output_dir):
    """Основная функция обработки изображения."""
    image = cv2.imread(image_path)
    if image is None:
        print(f"Error: The image '{image_path}' could not be loaded.")
        return None, None

    image_orig = image.copy()
    h_or, w_or = image.shape[:2]
    image_resized = cv2.resize(image, (640, 640))
    results = model(image_resized)[0]

    classes = results.boxes.cls.cpu().numpy()
    masks = results.masks.data.cpu().numpy()

    area_px = {}
    area_mm = {}
    for i in range(len(classes)):
        class_id = int(classes[i])
        mask = masks[i]
        extreme_points = get_extreme_points(mask)  # Находим крайние точки маски

        # Если объект типа 3 или 4 и эталон тоже 3, корректируем перспективу
        if class_id == 3 and (standard_type == 3 or standard_type == 4):
            mask = perspective_correction_for_mask(mask, extreme_points)

        size_px = np.sum(mask)  # Быстрый подсчёт активных пикселей в маске
        if class_id in area_px:
            area_px[class_id] = max(area_px[class_id], size_px)  # Обновление максимального значения
        else:
            area_px[class_id] = size_px

    # Получаем эталонную площадь и вычисляем коэффициент масштаба
    standard_px = area_px.get(standard_type, None)
    scale = standard_mm / standard_px if standard_px is not None else 1
    for key, value_px in area_px.items():
        area_mm[key] = value_px * scale  # Преобразуем площадь из пикселей в миллиметры

    # Наложение масок на изображение
    for i, mask in enumerate(masks):
        color = colors[int(classes[i]) % len(colors)]
        mask_resized = cv2.resize(mask, (w_or, h_or))  # Маска в оригинальном размере
        color_mask = np.zeros((h_or, w_or, 3), dtype=np.uint8)
        color_mask[mask_resized > 0] = color
        image_orig = cv2.addWeighted(image_orig, 1.0, color_mask, 0.5, 0)

    new_image_path = os.path.join(output_dir, os.path.splitext(os.path.basename(image_path))[0] + '_segmented' +
                                  os.path.splitext(image_path)[1])
    cv2.imwrite(new_image_path, image_orig)
    return new_image_path, area_mm


def main():
    parser = argparse.ArgumentParser(description="Usage: python script.py /path/to/file.jpg 42 100 output_dir")
    parser.add_argument("input_path", type=str, help="Path to the input file")
    parser.add_argument("type", type=int, help="Standard type")
    parser.add_argument("area", type=int, help="Standard area in mm²")
    parser.add_argument("output_dir", type=str, help="Directory to save results")
    args = parser.parse_args()

    file_path = args.input_path
    standard_type = args.type
    standard_area = args.area
    output_dir = args.output_dir

    if not os.path.exists(file_path):
        print(f"Error: The file '{file_path}' does not exist.")
        return

    # Обработка изображения и сохранение результата
    output_path, result = process_image(file_path, standard_type, standard_area, output_dir)

    if output_path:
        # Сохранение словаря размеров в CSV файл
        output_file = os.path.join(output_dir, os.path.splitext(os.path.basename(file_path))[0] + "_sizes.csv")
        with open(output_file, mode='w', newline='', encoding='utf-8') as file:
            writer = csv.writer(file)
            writer.writerow(["Class ID", "Size (mm²)"])  # Заголовки столбцов

            # Записываем данные
            for class_id, size_mm in result.items():
                writer.writerow([class_id, size_mm])


if __name__ == "__main__":
    main()
