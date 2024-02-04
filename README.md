# calendar

<p align="center">
    <img src="/promo/promo.gif">
</p>

Школьный проект; календарь с минимальным функционалом. Умеет только рисовать сетку из дней в выбранном году и отображать, прописанные в коде события (такие как Новый год, день святого Валентина, день программиста и тд).

Написано все на C++ с использованием библиотек [SFML](https://github.com/SFML/SFML), [ImGui](https://github.com/ocornut/imgui) и [ImGui-SFML](https://github.com/SFML/imgui-sfml).

### Сборка и запуск
Рекомендую использовать новейшие версии Visual Studio: не знаю как все будет работать в других системах(((

Для начала клонируем репозиторий 
```
git clone https://github.com/Shpana/text-editor
```
а потом запускаем premake5 для генерации vs-решения или make-файлов
```
vendor/premake5/premake5.exe {gmake, vs2019, vs2022...}
```

