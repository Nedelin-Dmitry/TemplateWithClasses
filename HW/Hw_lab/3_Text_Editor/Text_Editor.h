#pragma once
/*
������������ ��������� ��������
����������� ����� TextEditor.
����� ������ ������������� ����������� ���������� � ��������� ������� ���� ������� ���� �������� ����� ���
����� � ���������� ������������������ ��������. � ����������� �������� ����� ������������������ �� ������
��������� ����� ���� �����.
����� ������ ��������� ����������� ��������� ������ (������������, ���������� � ��.).
����� ������ ������������� ��������� ��������:
1) ����������� ������������� � �����������: ��������� ������� ���� ����� (x, y) � ���� �������. ����� ����
�����;
2) �������� ��������� ��������, ������ � ������ ��������� ��������;
3) ���������� ���� ������������� ������ � ������ �� ������ ����� ���� �����;
4) ������ ��������� ������������� ������.
��������� ������ ����� ���������� ����:
- ������� ��������� � ������ ����
- �������� ��������
- ������ ��������
- ������� � �������������� �����
- ��������� ������
������ � �������� - ��. http://www.c-cpp.ru/funkcii/conioh
*/
// ������ � ��������� ���� window(a,b,c,d) �� ������ ?
// �������� / ������ �������� ?

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
 1)�������� �� ���� ������� ���� -
 2)��������� ����������� �� ����� ������ +
 3)�������� �� ������ ����� ������ -
 4)������ �� ������� �������� TextEditor & -
*/

#include<iostream>
#include<string>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>

class TextEditor
{
private:
    COORD text_pos; // ��������� ������ �� X, Y
    int text_len;   // ����� ������
    char* text;		// ������ ������
public:
    //������������ � ����������
    TextEditor();
    TextEditor(short int x, short int y, int len);
    TextEditor(const TextEditor& copy);
    ~TextEditor();

    // �������
    COORD get_pos();
    int get_len();
    char* get_text();

    // �������
    void set_pos(COORD _new_pos, TextEditor& ZERO) { ZERO.text_pos = _new_pos; };
    void set_len(int _len, TextEditor& ZERO) { ZERO.text_len = _len; };

    //�������
    friend void window_position(HANDLE _hStdOut, short int _x_pos_win, short int _y_pos_win, short int _weight_win, short int _height_win, TextEditor& ZERO);
    friend void window_size(HANDLE _hStdOut, short int _x_pos_win, short int _y_pos_win, short int _weight_win, short int _height_win, TextEditor& ZERO);
    friend void hide_show_editor(TextEditor& ZERO); // ��� �� ���������� �������� ?? -�������� ���� -- �� ����� ���������� �� �������� ;3
    friend void on_text_editor(HANDLE _hStdOut, TextEditor& EditorWork);
    friend void off_editor(HANDLE _hStdOut, TextEditor& EditorOff);

};
