#include <iostream>
#include"Menu.h"
#include"Film_lib_vecrtor.h"
#include"Consoler.h"
#include"SubMenu.h"



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

    Film_library �urrent_lib = Film_library();
    int itemPos; // ������� � ���� - ����������� �������� Int �� string �.� ��� ����� �������� ���� ��������
    do {
        clrscr();
        itemPos = menu0.selectItem();
        clrscr();
        switch (itemPos)
        {
        case Add_film_lib: // ��������
            Add_film(�urrent_lib);
            break;
        case Change_film: // ��������
        {
            if (�urrent_lib.get_num_of_films() == 0)
            {
                cout << "The library is empty" << endl;
                system("pause");
                break;
            }
            string input_title;
            int _user_choose;
            cout << "������� �������� ������, ������� ������� ��������: ";
            cin >> input_title;
            do {
                cout << "1)�������� �������� ������\n2)�������� ������� ������\n3)�������� ���������� ������\n4)�������� ����������� ������\n5)�������� ���� ������\n";
                cout << "6)�������� ����� ������\n7)�������� �����\n8)�������� ����� ������\n";
                cin >> _user_choose;
                Film_redactor(�urrent_lib, input_title, _user_choose);
            } while (_user_choose != 0);
        }
            break;
        case Find_title_year:
            break;
        case Films_director:
            break;
        case Find_film_year:
            break;
        case Film_gross_num: // ��������� ���� ������ ���������� ������ ���-�� �������� ������� ��� ������ ������ - 
            break;
        case Film_gross_num_year: // ����������, ��� �������� ������� ������� ���������� try catch - ��������� ��������� � �������� ��������� search
            break;
        case Lib_size: // ��������
            get_films_count(�urrent_lib);
            break;
        case Delete_film:
            break;
        case Save_lib: // ��������
            Lib_save(�urrent_lib);
            break;
        case Download_Film: // ��������
            Lib_load(�urrent_lib);
            break;
        }
    } while (itemPos != 0);

    cout << "��������� ���������" << endl;

    return 0;
}