#include <iostream>
#include"Film_lib_2.h"
#include"Menu_Film_lib.h"
#include"Console_Film_lib.h"
#include"Submenu_Film_lib.h"

int int_data1 = 0, int_data2 = 0, int_data3 = 0;
string str_data1, str_data2;


int main()
{
    // ����� �������� ����������� ����
    system("title TextEditor");

    // �������� ���������� ���� ��� ��������� � �������
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    // ������������� �������������� � �������� �������
    SetConsoleCP(1251);         // ��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);   // ��������� ������� �������� win-cp 1251 � ����� ������

    setlocale(LC_CTYPE, "Russian");	// ��� �����-������ ������� ����

    Menu0 menu0("MainMenu.txt");

    Film_library Lib = Film_library(10);
    Film_library Lib2 = Film_library(10);
    int itemPos; // ������� � ���� - ����������� �������� Int �� string �.� ��� ����� �������� ���� ��������
    do
    {
        clrscr();
        itemPos = menu0.selectItem();
        clrscr();
        switch (itemPos)
        { 
        case 0: // �����
            cout << "��������� ���������" << endl;
            return 0;
        case 1: // �������� �����
            Add_film(Lib);
            cout << "����� ��������" << endl;
            break;
        case 2: // �������� ������ ������ ���������� �� ��������(�� ��������)
            //SubMenu_work(hStdOut, Lib);
            system("pause");
            break;
        case 3: //����� ����� �� �������� � ����
            cout << "������� �������� ������: ";
            cin >> str_data1;
            cout << "������ ��� ������:";
            cin >> int_data1;
            title_year_search(Lib, str_data1, int_data1);
            Write_film(Lib);
            break;
        case 4: // ������ ��� ������ ��������� ���������
            cout << "������� ������� ������: ";
            cin >> str_data1;
            screenwriter_year_search(Lib, str_data1);
            Write_film(Lib);
            break;
        case 5: //������ ��� ������, �������� � ������ � ��������� ����
            cout << "������� ���: ";
            cin >> int_data1;
            year_search(Lib, int_data1);
            Write_film(Lib);
            break;
        case 6: //������ �������� ����� ������� � ����������� �������
            cout << "������� ������� ������� �� ������ �������: ";
            cin >> int_data1;
            film_gross_search(Lib, int_data1, 0);
            Write_film(Lib2);
            break;
        case 7: //������ �������� ����� ������� � ����������� ������� � ��������� ����
            break;
        case 8: // ������ ������� ����� �������
            break;
        case 9: // ������� ����� �� ��������
            break;
        case 10: // ��������� ���������� 
            break;
        case 11: // ��������� ����������(�� ��������)
            break;
        }

    } while (1);
	return 0;
}