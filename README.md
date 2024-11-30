# Описание
Проект выполнен командой «Kizil» в рамках хакатона [Hack in Home 2024](https://stankinhacks.ru/hih2024) по треку «IT».

Вся детальная информация разбита по блокам и расположена в директории [Документации](/_doc/):

* [Описание архитектурного решения](/_doc/architecture_guide.md)
* [Руководство по настройке и использованию](/_doc/setup_guide.md)
* [Алгоритм обнаружения и рассчета площадей деталей](/_doc/algorithm_guide.md)
* [Руководство для программистов](/_doc/programming_guide.md)

# Структура репозитория:

    ./_doc/ -- здесь хранится документация и другие материалы
        ./algorithm_guide.md
        ./architecture_guide.md
        ./programming_guide.md
        ./setup_guide.md
    ./_image/ -- папка для хранения изображений 
    
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
        ./... - TBD
        ./... - TBD
