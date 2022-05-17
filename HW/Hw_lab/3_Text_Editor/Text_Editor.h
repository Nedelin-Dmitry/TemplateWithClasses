#pragma once
// Copyright 2022 Nedelin-Dmitry
/*
Single-line text editor
Develop a Text Editor class.
The class should provide an opportunity to place a field of a specified length in the selected position of the console window for
keyboard input of a sequence of characters. In the minimum version, the length of the sequence should not
exceed the length of the input field.
The class must contain the necessary utility methods (constructors, destructor, etc.).
The class must provide the following operations:
1) initializer constructor with parameters: the initial position of the input field (x, y) in the console window. length
of the input field;
2) show the text editor, remove the text editor from the screen;
3) ensure that the user enters a string with a length no longer than the length of the input field;
4) output the string entered by the user.
The program should have a simple menu:
- Enter the position and size of the window
- Show editor
- Remove the editor
- Enter and edit the text
- Complete the work
Working with the console -  http://www.c-cpp.ru/funkcii/conioh
*/
// the size and position of the window window(a,b,c,d) is not robbing ?
// show / remove the editor ?
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

#include<iostream>
#include<string>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>

class TextEditor{
 private:
    COORD text_pos;  // The position of the text in X, Y
    int text_len;  // Text length
    char* text;  // Array of text
  public:
    // constructors and destructor
    TextEditor();
    TextEditor(short int x, short int y, int len);
    TextEditor(const TextEditor& copy);
    ~TextEditor();
    // getters
    COORD get_pos();
    int get_len();
    char* get_text();
    // setters
    void set_pos(COORD _new_pos, TextEditor& ZERO) { ZERO.text_pos = _new_pos; }
    void set_len(int _len, TextEditor& ZERO) { ZERO.text_len = _len; }
    // functions
    friend void window_position(HANDLE _hStdOut, short int _x_pos_win, short int _y_pos_win, short int _weight_win, short int _height_win, TextEditor& ZERO);
    friend void window_size(HANDLE _hStdOut, short int _x_pos_win, short int _y_pos_win, short int _weight_win, short int _height_win, TextEditor& ZERO);
    friend void hide_show_editor(TextEditor& ZERO);
    friend void on_text_editor(HANDLE _hStdOut, TextEditor& EditorWork);
    friend void off_editor(HANDLE _hStdOut, TextEditor& EditorOff);
};
