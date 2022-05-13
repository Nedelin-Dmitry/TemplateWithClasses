#include <iostream>
#include"Text_Editor.h"
#include"Menu.h"
#include"Console.h"
#include"SubMenu.h"

using namespace std;

int main() {
    // задаём название консольного окна
    system("title TextEditor");

    // получаем дескриптор окна для обращения к консоли
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    // устанавливаем взаимодействие с русскими буквами
    SetConsoleCP(1251);         // установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);   // установка кодовой страницы win-cp 1251 в поток вывода

    setlocale(LC_CTYPE, "Russian");  // Для ввода-вывода русских букв

    Menu0 menu0("MainMenu.txt");

    TextEditor Editor = TextEditor();
    int itemPos;  // позиция в меню - Попробывать передать Int по string т.к при вводе символов меню крашится
    do {
        clrscr();
        itemPos = menu0.selectItem();
        cout << "Выбрано " << itemPos << " +++++++++++++++++++++++++++" << endl;
        clrscr();
        switch (itemPos) {
        case 0: // выход из текстового редактора
            off_editor(hStdOut, Editor);
            break; // нужен ли break? всё работает и без него
        case 1: // работа тектового редактора
            on_text_editor(hStdOut, Editor);
            break;
        case 2:
            SubMenu_work(hStdOut, Editor);
            system("pause");
            break;
        case 3:
            cout << "Для того, чтобы вернуть редактор - нажмите любую кнопку" << endl;
            system("pause");
            hide_show_editor(Editor);
        }

    } while (1);

    return 0;

}