# Описание

![ ](/_image/sticker.gif)

Проект выполнен командой «Kizil» в рамках хакатона [Hack in Home 2024](https://stankinhacks.ru/hih2024) по треку «IT».

Задание включало в себя расчет трудовых и материальных затрат на операции по окраске элементов сложных объектов.

Вся детальная информация разбита по блокам и расположена в директории [Документации](/_doc/):

* [Обзор архитектурного решения](/_doc/architecture_guide.md)
* [Руководство по настройке и использованию](/_doc/setup_guide.md)
* [Алгоритм обнаружения и рассчета площадей деталей](/_doc/algorithm_guide.md)

Ссылка на спецификацию API - [swagger](http://v2684079.hosted-by-vdsina.ru:5086/swagger/index.html)

Ссылка на диск с файлами, которые не были добавлены в git-репозиторий - 
[Яндекс.Диск](https://disk.yandex.ru/d/WxdX_FwFQdTang):
* best.pt - обученная модель
* build.rar - архив с собранным проектом
* <> - записаное видео обращение

# Структура репозитория:

    ./_doc/ -- здесь хранится документация и другие материалы
        ./algorithm_guide.md
        ./architecture_guide.md
        ./setup_guide.md
    ./_image/ -- папка для хранения изображений документации (там есть steamhappy)
    
    ./Frontend/ -- клиентская часть
        ./Qt/ - проект Qt5 (C++)
            ./resources/
            ./src/
            ./ui/
        ./build/ - (не включено в git) локально создаваемая сборка
    ./Backend/ -- серверная часть
        ./API/ - проект MS Visual Studio (C#)
            ./API/
            ./DataLayer/
            ./ServiceLayer/ 
    ./Script/ -- Обработка изображения в Python через OpenCV + YOLOv8
        ./script.py
