### Смысл
Когда хочешь дополнительную настраиваемую клавиатуру, а в распоряжении только дешёвая цифровая панель
### Настройка
* Заменить TARGET_ID и TARGETD_VID, TRARGET_PID на валидные данные устройства (можно узнать например через interception\samples\x86\hardwareid.exe, находится в архиве с interception, в этом репозитории такого нет)
* Программа делалась для работы с внешним нумпадом, как следствие для других устройств её, возможно, придётся донастраивать (также программа не считывает нажатия enter и divide у любых нумпадов)
* Собрать проект
* Переместить в папку с exe файлом interception.dll
* Запустить
