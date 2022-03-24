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

	TextEditor()
	{
		text_pos = { 0, 0 };
		text_len = 10;
		text = new char[text_len];
	}

	TextEditor(short x, short y, int len)
	{
		text_pos = { x, y };
		text_len = len;
		text = new char[text_len];
	}

	TextEditor(TextEditor& copy)
	{
		text_pos = copy.text_pos;
		text_len = copy.text_len;
	}

	COORD get_pos() { return text_pos; };
	int get_len() { return text_len; };
	char* get_text() { return text; };

};

void menu() // ��������� ���� � ������ � ���?
{


}

void c_move(HANDLE hStdOut, COORD cursorPos, CONSOLE_SCREEN_BUFFER_INFO& cbsi, int num)
{
	GetConsoleScreenBufferInfo(hStdOut, &cbsi);       // ��������� ���������� � �������� �������� ������ �������
	cursorPos.X = cbsi.dwCursorPosition.X + num;        // ������� ������� ��������� ������� �� ������ �����
	SetConsoleCursorPosition(hStdOut, cursorPos);
}

void text_line(HANDLE& hStdOut, COORD cursorPos, TextEditor& t_e)
{
	cursorPos = t_e.get_pos();
	int len = t_e.get_len();
	SetConsoleCursorPosition(hStdOut, cursorPos);
	DWORD cWrittenChars;
	FillConsoleOutputCharacter(hStdOut, (TCHAR)'_', len, cursorPos, &cWrittenChars);  // ���������� ������ � �������� ������ ������� �������� ����� ���
	SetConsoleCursorPosition(hStdOut, cursorPos);

	int iKey = 67;
	CONSOLE_SCREEN_BUFFER_INFO cbsi;

	while (iKey != KEY_EXIT && len > 0) {
		switch (iKey)
		{
		case KEY_ARROW_LEFT:
			c_move(hStdOut, cursorPos, cbsi, -1);
			len++;
			break;
		case KEY_ARROW_RIGHT:
			c_move(hStdOut, cursorPos, cbsi, 1);
			len--;
			break;
		case KEY_BACKSPACE:
			c_move(hStdOut, cursorPos, cbsi, -1);
			std::cout << '_';
			c_move(hStdOut, cursorPos, cbsi, -1);
			len++;
			break;
		case KEY_EXIT:
			break; // ???
			break;
		default:
			iKey = _getch();
			std::cout << (char)iKey;
			len--;
			break;
		}
	}
	wchar_t* input_char = new wchar_t[len]; // ??
	DWORD lpNumberOfCharsRead;
	ReadConsoleOutputCharacter(hStdOut, input_char, len, cursorPos, &lpNumberOfCharsRead);
	system("CLS");
	std::wcout << "Input text is:" << input_char << std::endl;
	system("pause");

}

int main()
{
	system("title TextEditor");
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCP(1251);


	return 0;
}