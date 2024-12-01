# Руководство по настройке и использованию

## Содержание

- [Руководство по настройке и использованию](#руководство-по-настройке-и-использованию)
  - [Содержание](#содержание)
  - [Клиентская часть](#клиентская-часть)
  - [Серверная часть](#серверная-часть)

## Клиентская часть

Пользовательское приложение распространяется в виде собранного Qt проекта (архив с .exe файлом). 
> Ссылка на диск: [Яндекс.Диск](https://disk.yandex.ru/d/WxdX_FwFQdTang) (архив - build.rar)

Взаимодействие с пользовательским интерфейсом:
1. TBD
2. TBD

TODO: Добавить скриншот с интерфейсом

## Серверная часть

В рамках проведения хакатона и на время защиты серверная часть проекта будет развернута на нашем сервере. Доступ к которому осуществляется по адресу: __<адрес>__

В дальнейшем для использования нужно настроить сервер. Должны быть установлены:
  * dotnet
  * PostgreSQL
  * Python библиотеки

1. Настроить appsettings.Development.json
2. Выполнить запуск используя **dotnet run**