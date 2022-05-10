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
	//setlocale(LC_CTYPE, "Russian");	// ��� �����-������ ������� ����

	Menu0 menu0("SubMenu.txt");
	/*
	* ���������											- ���������
	3													- ���-�� ��������� ������(�� ������ ������)
	�������� ��������� ��������� ����				    - ����� ���������
	�������� ������ ����
	�������� ��������� ��������� ������
	�������� ����� ������

	*/
	int itemPos;
	do
	{
		clrscr();
		itemPos = menu0.selectItem();
		cout << "������� " << itemPos << " +++++++++++++++++++++++++++" << endl;
		clrscr();
		switch (itemPos)
		{
		case 1:
			GetConsoleScreenBufferInfo(_hStdOut, &screen_buffer_info);
			cout << "������� ��������� ���� �� X:" << endl;
			cin >> x;
			cout << "������� ��������� ���� �� Y:" << endl;
			cin >> y;
			{
				int _weight = weight;
				int _height = height;
				window_position(_hStdOut, x, y, _weight, _height, ZERO);
			}
			break;
		case 2:
			GetConsoleScreenBufferInfo(_hStdOut, &screen_buffer_info);
			cout << "������� ������ ���� �� ����������� " << screen_buffer_info.dwMaximumWindowSize.X << ":" << endl;
			cin >> weight;
			cout << "������� ������ ���� �� ����������� " << screen_buffer_info.dwMaximumWindowSize.Y << ":" << endl;
			cin >> height;
			window_size(_hStdOut, x, y, weight, height, ZERO);
			break;
		case 3: // ������
			GetConsoleScreenBufferInfo(_hStdOut, &screen_buffer_info);
			{
				int for_control_len = ZERO.get_len();
				do
				{
					cout << "������� ��������� ������ �� X �� ����������� " << screen_buffer_info.dwSize.X - for_control_len << ":" << endl;
					cin >> For_set_positio.X;
					if (For_set_positio.X < 0 || For_set_positio.X > screen_buffer_info.dwSize.X - for_control_len)
					{
						cout << "������ �����, ���������� ���!" << endl;
					}
				} while (For_set_positio.X < 0 || For_set_positio.X > screen_buffer_info.dwSize.X - for_control_len);
				do
				{
					cout << "������� ��������� ������ �� Y �� �����������:" << screen_buffer_info.dwSize.Y << endl;
					cin >> For_set_positio.Y;
					if ((For_set_positio.Y < 0 || For_set_positio.X > screen_buffer_info.dwSize.Y))
					{
						cout << "������ �����, ���������� ���!" << endl;
					}
				} while (For_set_positio.Y < 0 || For_set_positio.X > screen_buffer_info.dwSize.Y);
				//For_copy.set_pos(For_set_positio, ZERO);
				TextEditor().set_pos(For_set_positio, ZERO); // �������� ���������� �������� ��� ������ 
			}
			//TextEditor::set_pos(For_set_positio, ZERO); - ��� static �� ��������, �� static �� ������ - ����� - ��������� ������ ������
			break;
		case 4: // ������-�� �� �������� - ��������
			GetConsoleScreenBufferInfo(_hStdOut, &screen_buffer_info);
			COORD for_control_x_pos = ZERO.get_pos();
			cout << "������� ����� ������ ������ 0 � �� ����������� " << screen_buffer_info.dwSize.X - for_control_x_pos.X << ":" << endl;
			do
			{
				cin >> new_len;
				if (new_len <= 0 || new_len > screen_buffer_info.dwSize.X)
				{
					cout << "������ �����, ���������� ���!" << endl;
				}
			} while (new_len <= 0 || new_len > (screen_buffer_info.dwSize.X - for_control_x_pos.X));
			//For_copy.set_len(new_len, ZERO); 
			TextEditor().set_len(new_len, ZERO);
			//TextEditor::set_len(new_len, ZERO);
			break;
		}

	} while (itemPos != 0);

}