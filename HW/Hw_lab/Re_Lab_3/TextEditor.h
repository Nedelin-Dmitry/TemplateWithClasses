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
#define KEY_ARROW_UP 72 // ??
#define KEY_ARROW_DOWN 80 // ??

#include<iostream>
#include<string>
#include <windows.h>
#include <conio.h>

class TextEditor
{
private:
	COORD text_pos;
	int text_len;
	char* text;
public:
	//������������ � ����������
	TextEditor();
	TextEditor(short int x, short int y, int len);
	TextEditor(TextEditor& copy);
	~TextEditor();

	// �������
	 COORD get_pos();
	 int get_len();
	 char* get_text();

	 //�������
	 friend void hide_editor();
	 friend void show_editor();
	 friend void on_text_editor(HANDLE _hStdOut, TextEditor& EditorWork);
	 friend void off_editor();

};