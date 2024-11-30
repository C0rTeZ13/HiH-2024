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


def process_image(image_path, standard_type, standard_mm, output_dir):
    # Загрузка изображения
    image = cv2.imread(image_path)
    image_orig = image.copy()
    h_or, w_or = image.shape[:2]
    image = cv2.resize(image, (640, 640))
    results = model(image)[0]

    classes_names = results.names
    print(classes_names)
    classes = results.boxes.cls.cpu().numpy()
    np.save("classes", classes)
    masks = results.masks.data.cpu().numpy()
    np.save("masks", masks)

    area_px = {}
    area_mm = {}
    for i in range(len(classes)):
        class_id = int(classes[i])
        size_px = np.sum(masks[i])  # Быстрый подсчёт активных пикселей в маске
        if class_id in area_px:
            area_px[class_id] = max(area_px[class_id], size_px)  # Обновление максимального значения
        else:
            area_px[class_id] = size_px

    standard_px = area_px.get(standard_type, None)
    scale = standard_mm / standard_px
    for key, value_px in area_px.items():
        area_mm[key] = value_px * scale

    # Наложение масок на изображение
    for i, mask in enumerate(masks):
        color = colors[int(classes[i]) % len(colors)]
        mask_resized = cv2.resize(mask, (w_or, h_or))
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

    # Сохранение словаря размеров в CSV файл
    output_file = os.path.join(output_dir, "object_sizes.csv")
    with open(output_file, mode='w', newline='', encoding='utf-8') as file:
        writer = csv.writer(file)
        writer.writerow(["Class ID", "Size (mm²)"])  # Заголовки столбцов

        # Записываем данные
        for class_id, size_mm in result.items():
            writer.writerow([class_id, size_mm])


if __name__ == "__main__":
    main()
