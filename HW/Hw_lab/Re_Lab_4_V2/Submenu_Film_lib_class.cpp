#include <iostream>
using namespace std;

#include"Submenu_Film_lib.h"
#include"Menu_Film_lib.h"
#include"Console_Film_lib.h"
#include"Film_lib_2.h"
 // ����-��� �� ������������
void SubMenu_work(HANDLE _hStdOut, Film_library& ZERO)
{
	setlocale(LC_CTYPE, "Russian");	// ��� �����-������ ������� ����

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
		clrscr();
		switch (itemPos)
		{
		case 1:

			break;
		case 2:
			
			break;
		case 3: 

			break;
		case 4:
			break;
		case 5:

			break;
		}

	} while (itemPos != 0);

}

void SubMenu2_work(HANDLE _hStdOut, Film_library& ZERO)
{
	setlocale(LC_CTYPE, "Russian");	// ��� �����-������ ������� ����

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