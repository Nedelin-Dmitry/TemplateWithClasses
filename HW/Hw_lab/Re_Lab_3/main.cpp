#include <iostream>
#include"TextEditor.h"

int main()
{

    // задаём название консольного окна
    system("title My Application");

    // получаем дескриптор окна для обращения к консоли
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    // устанавливаем взаимодействие с русскими буквами
    SetConsoleCP(1251);         // установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);   // установка кодовой страницы win-cp 1251 в поток вывода
    COORD cursorPos;
    cursorPos.X = 5;
    cursorPos.Y = 2;
    SetConsoleCursorPosition(hStdOut, cursorPos);
    int _x_ = 1;
    int _y_ = 1;
    int _len_ = 20;
    TextEditor start = TextEditor(_x_, _y_, _len_);
    on_text_editor(hStdOut, start);

	return 0;

}