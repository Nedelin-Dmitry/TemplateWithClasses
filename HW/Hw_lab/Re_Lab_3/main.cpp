#include <iostream>
#include"TextEditor.h"

int main()
{

    // ����� �������� ����������� ����
    system("title My Application");

    // �������� ���������� ���� ��� ��������� � �������
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    // ������������� �������������� � �������� �������
    SetConsoleCP(1251);         // ��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);   // ��������� ������� �������� win-cp 1251 � ����� ������
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