#pragma once
/*
Однострочный текстовый редактор
Разработать класс TextEditor.
Класс должен предоставлять возможность разместить в выбранной позиции окна консоли поле заданной длины для
ввода с клавиатуры последовательности символов. В минимальном варианте длина последовательности не должна
превышать длину поля ввода.
Класс должен содержать необходимые служебные методы (конструкторы, деструктор и пр.).
Класс должен предоставлять следующие операции:
1) конструктор инициализатор с параметрами: начальная позиция поля ввода (x, y) в окне консоли. длина поля
ввода;
2) показать текстовый редактор, убрать с экрана текстовый редактор;
3) обеспечить ввод пользователем строки с длиной не больше длины поля ввода;
4) выдать введенную пользователем строку.
Программа должна иметь простейшее меню:
- Введите положение и размер окна
- Показать редактор
- Убрать редактор
- Введите и отредактируйте текст
- Завершить работу
Работа с консолью - См. http://www.c-cpp.ru/funkcii/conioh
*/
// размер и положение окна window(a,b,c,d) не роббит ?
// показать / убрать редактор ?

#define _CRT_SECURE_NO_WARNINGS 

#define KEY_EXIT 27
#define ARROW_KEY 224
#define KEY_SPACE 0
#define KEY_ENTER 13
#define KEY_BACKSPACE 8
#define KEY_H 72



#define KEY_ARROW_RIGHT 77
#define KEY_ARROW_LEFT 75
#define KEY_ARROW_UP 72 
#define KEY_ARROW_DOWN 80 

/*
 1)Проверка на ввод размера окна -
 2)Поставить ограничение на длину строки +
 3)Проверка на размер ввода строки -
 4)Убрать из функций ненужный TextEditor & -
*/

#include<iostream>
#include<string>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>

class TextEditor
{
private:
    COORD text_pos; // Положение текста по X, Y
    int text_len;   // Длина текста
    char* text;		// Массив текста
public:
    //конструкторы и деструктор
    TextEditor();
    TextEditor(short int x, short int y, int len);
    TextEditor(const TextEditor& copy);
    ~TextEditor();

    // геттеры
    COORD get_pos();
    int get_len();
    char* get_text();

    // сеттеры
    void set_pos(COORD _new_pos, TextEditor& ZERO) { ZERO.text_pos = _new_pos; };
    void set_len(int _len, TextEditor& ZERO) { ZERO.text_len = _len; };

    //функции
    friend void window_position(HANDLE _hStdOut, short int _x_pos_win, short int _y_pos_win, short int _weight_win, short int _height_win, TextEditor& ZERO);
    friend void window_size(HANDLE _hStdOut, short int _x_pos_win, short int _y_pos_win, short int _weight_win, short int _height_win, TextEditor& ZERO);
    friend void hide_show_editor(TextEditor& ZERO); // Как не передавать аргумент ?? -Написать Деду -- Не видит определния но работает ;3
    friend void on_text_editor(HANDLE _hStdOut, TextEditor& EditorWork);
    friend void off_editor(HANDLE _hStdOut, TextEditor& EditorOff);

};
