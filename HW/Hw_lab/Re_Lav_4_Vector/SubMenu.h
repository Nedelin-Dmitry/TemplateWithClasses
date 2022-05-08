#pragma once
#include <iostream>
using namespace std;

#include"SubMenu.h"
#include"Menu.h"
#include"Consoler.h"
#include"Film_lib_vecrtor.h"

void SubMenu_work(HANDLE _hStdOut, Film_library& ZERO)
{
	setlocale(LC_CTYPE, "Russian");	// Для ввода-вывода русских букв

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
		clrscr();
		switch (itemPos)
		{
		case 1:
			cout << "Введите Режисёра: ";

			break;
		case 2:

			break;
		case 3:

			break;
		case 4:
			//SubMenu2_work(_hStdOut, ZERO);
			break;
		case 5:

			break;
		}

	} while (itemPos != 0);

}

void SubMenu2_work(HANDLE _hStdOut, Film_library& ZERO)
{
	setlocale(LC_CTYPE, "Russian");	// Для ввода-вывода русских букв

	Menu0 menu0("SubMenu2.txt");
	int itemPos;
	do
	{
		clrscr();
		itemPos = menu0.selectItem();
		clrscr();
		switch (itemPos)
		{
		case 1:

			break;
		case 2:

			break;
		case 3:

			break;
		}

	} while (itemPos != 0);
}