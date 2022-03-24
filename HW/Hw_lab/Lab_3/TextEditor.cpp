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

void menu() // отрисовка меню и работа с ним?
{


}

void c_move(HANDLE hStdOut, COORD cursorPos, CONSOLE_SCREEN_BUFFER_INFO& cbsi, int num)
{
	GetConsoleScreenBufferInfo(hStdOut, &cbsi);       // извлекает информацию о заданном экранном буфере консоли
	cursorPos.X = cbsi.dwCursorPosition.X + num;        // смещаем текущее положение курсора на символ назад
	SetConsoleCursorPosition(hStdOut, cursorPos);
}

void text_line(HANDLE& hStdOut, COORD cursorPos, TextEditor& t_e)
{
	cursorPos = t_e.get_pos();
	int len = t_e.get_len();
	SetConsoleCursorPosition(hStdOut, cursorPos);
	DWORD cWrittenChars;
	FillConsoleOutputCharacter(hStdOut, (TCHAR)'_', len, cursorPos, &cWrittenChars);  // записывает символ в экранном буфере консоли заданное число раз
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