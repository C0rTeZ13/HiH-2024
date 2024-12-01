# Руководство по настройке и использованию

## Содержание

- [Руководство по настройке и использованию](#руководство-по-настройке-и-использованию)
  - [Содержание](#содержание)
  - [Клиентская часть](#клиентская-часть)
  - [Серверная часть](#серверная-часть)

## Клиентская часть

Пользовательское приложение распространяется в виде собранного Qt проекта (архив с .exe файлом). 
Ссылка на диск: [Яндекс.Диск](https://disk.yandex.ru/d/WxdX_FwFQdTang) (архив - build.rar)

Внешний вид приложения:

![](/_image/ui.pg.jpg)

Пользовательский интерфейс визуально разделен на три региона (зоны либо области): 
* В области загрузки
  * Выбирается изображение для обработки
  * Указываются параметры
* В области изображения отображается исходное изображение до отправки и обработанное после.
* В области вывода показываются найденные и расчитаные значения.

## Серверная часть

В рамках проведения хакатона и на время защиты серверная часть проекта будет развернута на нашем сервере. Доступ к которому осуществляется по адресу: (http://v2684079.hosted-by-vdsina.ru:5086/swagger/index.html)

В дальнейшем для использования нужно будет настроить сервер.

> [!WARNING]
> Порядок действий для настройки сервера и установки всех необходимых инструментов и библиотек на данный момент не определен.
> Сервер и так с трудом двигается. Спасибо ему.