#include <iostream>
#include"Menu.h"
#include"Film_lib_vecrtor.h"
#include"Consoler.h"
#include"SubMenu.h"


/*
������� ������������ �������� �� ����
*/
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
        case Find_title_year: // ��������
            if (�urrent_lib.get_num_of_films() == 0)
            {
                cout << "The library is empty" << endl;
                system("pause");
            }
            else
            {
                string _title;
                cout << "Input the title of the film: " << endl;
                cin >> _title;
                int _year;
                cout << "Input the year of the film: " << endl;
                cin >> _year;
                Film_library A = Film_library(title_year_search(�urrent_lib, _title, _year));
                Write_Film(A);
            }
            break;
        case Films_director: // ��������
            if (�urrent_lib.get_num_of_films() == 0)
            {
                cout << "The library is empty" << endl;
                system("pause");
            }
            else
            {
                string _director;
                cout << "Input the director of the film: " << endl;
                cin >> _director;
                Film_library A = Film_library(screenwriter_year_search(�urrent_lib, _director));
                if (A.get_num_of_films() == 0)
                {

                }
                else {
                    Write_lib(A);
                }
            }
            break;
        case Find_film_year: // ��������
            if (�urrent_lib.get_num_of_films() == 0)
            {
                cout << "The library is empty" << endl;
                system("pause");
            }
            else
            {
                int _year;
                cout << "Input the year of the film: " << endl;
                cin >> _year;
                Film_library A = Film_library(year_search(�urrent_lib, _year));
                if (A.get_num_of_films() == 0)
                {

                }
                else {
                    Write_lib(A);
                }
            }
            break;
        case Film_gross_num: // ��������� ���� ������ ���������� ������ ���-�� �������� ������� ��� ������ ������ - 
            if (�urrent_lib.get_num_of_films() == 0) // ����� � ����������, ����� ���� �� ��������
            {
                cout << "The library is empty" << endl;
                system("pause");
            }
            else
            {
                int _num;
                cout << "How many movies do you want to output" << endl;
                cin >> _num;
                Film_library A = Film_library(film_gross_search(�urrent_lib, _num, 0));
                if (A.get_num_of_films() == 0)
                {
                    cout << "Ruined" << endl;
                    system("pause");
                }
                else {
                    Write_lib(A);
                }
            }
            break;
        case Film_gross_num_year: // ����������, ��� �������� ������� ������� ���������� try catch - ��������� ��������� � �������� ��������� search
            if (�urrent_lib.get_num_of_films() == 0)
            {
                cout << "The library is empty" << endl;
                system("pause");
            }
            else
            {
                int _year;
                cout << "Input the year of the film: " << endl;
                cin >> _year;
                int _num;
                cout << "How many movies do you want to output" << endl;
                cin >> _num;
                Film_library A = Film_library(year_maxn_gross_search(�urrent_lib, _num, 0,  _year));
                if (A.get_num_of_films() == 0)
                {
                    cout << "Ruined" << endl;
                    system("pause");
                }
                else {
                    Write_lib(A);
                }
            }
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
        case Write_Library: // ��������
            Write_lib(�urrent_lib);
        }
    } while (itemPos != 0);

    cout << "��������� ���������" << endl;

    return 0;
}