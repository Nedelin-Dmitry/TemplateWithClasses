#include <iostream>
#include"Film_lib_2.h"
#include"Menu_Film_lib.h"
#include"Console_Film_lib.h"
#include"Submenu_Film_lib.h"

int int_data1 = 0, int_data2 = 0, int_data3 = 0;
string str_data1, str_data2;
Film_library output_lib_size1 = Film_library(1); // ��� ��� ������� ����� ���� ������� 1-� ���������� �����
Film_library output_lib_size10 = Film_library(10); // ������ �������� ���������


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
        case 1: // �������� ����� !
        {
            int max_check = Lib.get_lib_size();
            if (max_check == LIB_SIZE)
            {
                cout << "���������� ��� ���������" << endl;
            }
            else 
            {
                Add_film(Lib);
                cout << "����� ��������" << endl;
            }        
        }
            break;
        case 2: // �������� ������ ������ ���������� �� �������� !
        {
            string input_title;
            cout << "������� �������� ������, ������� ������� ��������: ";
            cin >> input_title;
            int _user_choose;
            cout << "1)�������� �������� ������ \n 2)�������� ������� ������ \n 3)�������� ���������� ������ \n 4)�������� ����������� ������ \n 5)�������� ���� \n 6)�������� ����� ������\n";
            cin >> _user_choose;
            Film_redactor(Lib, input_title, _user_choose);
            cout << "������ ���������" << endl;
        }
            break;
        case 3: //����� ����� �� �������� � ���� !
            cout << "������� �������� ������: ";
            cin >> str_data1;
            cout << "������ ��� ������:";
            cin >> int_data1;
            output_lib_size1 = title_year_search(Lib, str_data1, int_data1);
            Write_lib(output_lib_size1);
            break;
        case 4: // ������ ��� ������ ��������� ��������� !
            cout << "������� ������� ������: ";
            cin >> str_data1;
            output_lib_size10 = screenwriter_year_search(Lib, str_data1);
            Write_lib(output_lib_size10);
            break;
        case 5: //������ ��� ������, �������� � ������ � ��������� ���� !
            cout << "������� ���: ";
            cin >> int_data1;
            output_lib_size10 = year_search(Lib, int_data1);
            Write_lib(output_lib_size10);
            break;
        case 6: //������ �������� ����� ������� � ����������� ������� !
        {
            cout << "������� ������� ������� �� ������ �������: ";
            cin >> int_data1;
            int Lib_size = Lib.get_lib_size();
            while (int_data1 > Lib_size || int_data1 < 0)
            {
                cout << "������ ����������: " << Lib_size << endl;
                cout << "������ �����, ���������� ��� ���" << endl;
            }
            output_lib_size10 = film_gross_search(Lib, int_data1, 0);
            Write_lib(output_lib_size10);
        }
            break;
        case 7: //������ �������� ����� ������� � ����������� ������� � ��������� ����
        {
            int int_year; // ���������� �������� �� ���� 
            cout << "������� ������ ������ ���� �� ������ �������:";
            cin >> int_year;
            cout << "������� � ������� ����� ��� � ����������" << endl;
            cout << "������� ������� ������� �� ������ �������: ";
            cin >> int_data1;
            int Lib_size = Lib.get_lib_size();
            while (int_data1 > Lib_size || int_data1 < 0)
            {
                cout << "������ ����������: " << Lib_size << endl;
                cout << "������ �����, ���������� ��� ���" << endl;
            }
            output_lib_size10 = film_gross_search(Lib, int_data1, 0);
            Write_lib(output_lib_size10);
        }
            break;
        case 8: // ������ ������� ����� �������
        {
            int now_lib_size = get_films_count(Lib);
            cout << "������� ���-�� �������: " << now_lib_size << endl;
        }
            break;
        case 9: // ������� ����� �� ��������
        {

            string _title;
            cout << "������� �������� ������: ";
            cin >> _title;
            delete_film(Lib, _title);
        }
            break;
        case 10: // ��������� ���������� 
            Lib_save(Lib);
            break;
        case 11: // ��������� ���������� - ����������
            break;
        }

    } while (1);

	return 0;
}