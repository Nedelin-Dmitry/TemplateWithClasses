#include <iostream>
using namespace std;

#include"SubMenu.h"
#include"Menu.h"
#include"Console.h"
#include"Text_Editor.h"

int x = 0, y = 0;
short int weight = 600;
short int height = 600;

int width_buffer;


COORD For_set_positio = { 0, 0 };

CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;


int new_len = 10;

TextEditor For_copy;

void SubMenu_work(HANDLE _hStdOut, TextEditor& ZERO)
{
	For_copy = TextEditor(ZERO);
	//setlocale(LC_CTYPE, "Russian");	// Для ввода-вывода русских букв

	Menu0 menu0("SubMenu.txt");
	/*
	* Параметры											- заголовок
	3													- кол-во вариантов выбора(не считая выхода)
	Изменить начальное положение окна				    - Имена вариантов
	Изменить размер окна
	Изменить начальное положение строки
	Изменить длину строки

	*/
	int itemPos;
	do
	{
		clrscr();
		itemPos = menu0.selectItem();
		cout << "Выбрано " << itemPos << " +++++++++++++++++++++++++++" << endl;
		clrscr();
		switch (itemPos)
		{
		case 1:
			GetConsoleScreenBufferInfo(_hStdOut, &screen_buffer_info);
			cout << "Введите положение окна по X:" << endl;
			cin >> x;
			cout << "Введите положение окна по Y:" << endl;
			cin >> y;
			{
				int _weight = weight;
				int _height = height;
				window_position(_hStdOut, x, y, _weight, _height, ZERO);
			}
			break;
		case 2:
			GetConsoleScreenBufferInfo(_hStdOut, &screen_buffer_info);
			cout << "Введите ширину окна не превышающую " << screen_buffer_info.dwMaximumWindowSize.X << ":" << endl;
			cin >> weight;
			cout << "Введите высоту окна не превышающую " << screen_buffer_info.dwMaximumWindowSize.Y << ":" << endl;
			cin >> height;
			window_size(_hStdOut, x, y, weight, height, ZERO);
			break;
		case 3: // роббит
			GetConsoleScreenBufferInfo(_hStdOut, &screen_buffer_info);
			{
				int for_control_len = ZERO.get_len();
				do
				{
					cout << "Введите положение строки по X не превышающую " << screen_buffer_info.dwSize.X - for_control_len << ":" << endl;
					cin >> For_set_positio.X;
					if (For_set_positio.X < 0 || For_set_positio.X > screen_buffer_info.dwSize.X - for_control_len)
					{
						cout << "Ошибка ввода, попробуйте ещё!" << endl;
					}
				} while (For_set_positio.X < 0 || For_set_positio.X > screen_buffer_info.dwSize.X - for_control_len);
				do
				{
					cout << "Введите положение строки по Y не превышающую:" << screen_buffer_info.dwSize.Y << endl;
					cin >> For_set_positio.Y;
					if ((For_set_positio.Y < 0 || For_set_positio.X > screen_buffer_info.dwSize.Y))
					{
						cout << "Ошибка ввода, попробуйте ещё!" << endl;
					}
				} while (For_set_positio.Y < 0 || For_set_positio.X > screen_buffer_info.dwSize.Y);
				//For_copy.set_pos(For_set_positio, ZERO);
				TextEditor().set_pos(For_set_positio, ZERO); // создание временного объектра для работы 
			}
			//TextEditor::set_pos(For_set_positio, ZERO); - без static не работает, но static всё ломает - выход - временный объект класса
			break;
		case 4: // Почему-то не работает - спросить
			GetConsoleScreenBufferInfo(_hStdOut, &screen_buffer_info);
			COORD for_control_x_pos = ZERO.get_pos();
			cout << "Введите длину строки больше 0 и не превышающую " << screen_buffer_info.dwSize.X - for_control_x_pos.X << ":" << endl;
			do
			{
				cin >> new_len;
				if (new_len <= 0 || new_len > screen_buffer_info.dwSize.X)
				{
					cout << "Ошибка ввода, попробуйте ещё!" << endl;
				}
			} while (new_len <= 0 || new_len > (screen_buffer_info.dwSize.X - for_control_x_pos.X));
			//For_copy.set_len(new_len, ZERO); 
			TextEditor().set_len(new_len, ZERO);
			//TextEditor::set_len(new_len, ZERO);
			break;
		}

	} while (itemPos != 0);

}