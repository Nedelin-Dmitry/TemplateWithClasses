#include <fstream>
#include <iostream>
using namespace std;

#include"Menu_TextEditor.h"

Menu0::Menu0(const char* menuFileName)
{
	fstream is; // поток для чтения
	is.open(menuFileName, ios::in); // файл для чтения
	if (!is)
	{
		cout << "Can't open file " << menuFileName << endl;
		system("pause");
		exit(3);
	}

	is.getline(Title, 80);
	is >> ItemsCount;
	Items = new char* [ItemsCount];

	is.ignore();   // !!!!!!!!!!!!!!!!!!!!!!

	for (int i = 0; i < ItemsCount; ++i)
	{
		Items[i] = new char[80];
		is.getline(Items[i], 80);
	}

	is.close();

}

Menu0::~Menu0(void)
{
	if (ItemsCount > 0)
	{
		for (int i = 0; i < ItemsCount; ++i)
			delete[] Items[i];
		delete[] Items;
		ItemsCount = 0;
	}
}

void Menu0::showMenu0()
{

}

int Menu0::selectItem()
{
	int itemPos = -1;
	cout << Title << endl;
	cout << "0 - выход" << endl;
	for (int i = 1; i <= ItemsCount; ++i)
		cout << i << " - " << Items[i - 1] << endl;
	do
	{
		cout << "Введите номер позиции меню: ";
		cin >> itemPos;
		if (itemPos < 0 || itemPos > ItemsCount)
		{
			cout << "Неверный номер позиции" << endl;
			itemPos = -1;
		}

	} while (itemPos == -1);

	return itemPos;
}
