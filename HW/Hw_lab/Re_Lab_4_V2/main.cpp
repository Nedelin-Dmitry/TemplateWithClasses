#include <iostream>
#include"Film_lib_2.h"
#include"Menu_Film_lib.h"
#include"Console_Film_lib.h"
#include"Submenu_Film_lib.h"

int int_data1 = 0, int_data2 = 0, int_data3 = 0;
string str_data1, str_data2;
Film_library output_lib_size1 = Film_library(1); // для тех случаев когда надо вывести 1-н конкретный фильм
Film_library output_lib_size10 = Film_library(10); // нельзя вставить константу


int main()
{

    // задаём название консольного окна
    system("title TextEditor");

    // получаем дескриптор окна для обращения к консоли
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    // устанавливаем взаимодействие с русскими буквами
    SetConsoleCP(1251);         // установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);   // установка кодовой страницы win-cp 1251 в поток вывода

    setlocale(LC_CTYPE, "Russian");	// Для ввода-вывода русских букв

    Menu0 menu0("MainMenu.txt");

    Film_library Lib = Film_library(10);
    Film_library Lib2 = Film_library(10);
    int itemPos; // позиция в меню - Попробывать передать Int по string т.к при вводе символов меню крашится
    do
    {
        clrscr();
        itemPos = menu0.selectItem();
        clrscr();
        switch (itemPos)
        { 
        case 0: // Выход
            cout << "Программа завершена" << endl;
            return 0;
        case 1: // Добавить фильм !
        {
            int max_check = Lib.get_lib_size();
            if (max_check == LIB_SIZE)
            {
                cout << "Библиотека уже заполнена" << endl;
            }
            else 
            {
                Add_film(Lib);
                cout << "Фильм добавлен" << endl;
            }        
        }
            break;
        case 2: // Изменить данные фильма выбранного по названию !
        {
            string input_title;
            cout << "Введите название фильма, который желаете изменить: ";
            cin >> input_title;
            int _user_choose;
            cout << "1)Изменить название фильма \n 2)Изменить режисёра фильма \n 3)Изменить сценариста фильма \n 4)Изменить композитора фильма \n 5)Изменить дату \n 6)Изменить сборы фильма\n";
            cin >> _user_choose;
            Film_redactor(Lib, input_title, _user_choose);
            cout << "Данные изменнены" << endl;
        }
            break;
        case 3: //Найти фильм по названию и году !
            cout << "Введите название фильма: ";
            cin >> str_data1;
            cout << "Введит год фильма:";
            cin >> int_data1;
            output_lib_size1 = title_year_search(Lib, str_data1, int_data1);
            Write_lib(output_lib_size1);
            break;
        case 4: // Выдать все фильмы заданного режиссера !
            cout << "Введите Режисёра фильма: ";
            cin >> str_data1;
            output_lib_size10 = screenwriter_year_search(Lib, str_data1);
            Write_lib(output_lib_size10);
            break;
        case 5: //Выдать все фильмы, вышедшие в прокат в выбранном году !
            cout << "Введите год: ";
            cin >> int_data1;
            output_lib_size10 = year_search(Lib, int_data1);
            Write_lib(output_lib_size10);
            break;
        case 6: //Выдать заданное число фильмов с наибольшими сборами !
        {
            cout << "Введите сколько фильмов вы хотите вывести: ";
            cin >> int_data1;
            int Lib_size = Lib.get_lib_size();
            while (int_data1 > Lib_size || int_data1 < 0)
            {
                cout << "Размер библиотеки: " << Lib_size << endl;
                cout << "Ошибка ввода, попробуйте ещё раз" << endl;
            }
            output_lib_size10 = film_gross_search(Lib, int_data1, 0);
            Write_lib(output_lib_size10);
        }
            break;
        case 7: //Выдать заданное число фильмов с наибольшими сборами в выбранном году
        {
            int int_year; // нормальная проверка на ввод 
            cout << "Введите фильмы какого года вы хотите вывести:";
            cin >> int_year;
            cout << "Фильмов с введёным годом нет в библиотеке" << endl;
            cout << "Введите сколько фильмов вы хотите вывести: ";
            cin >> int_data1;
            int Lib_size = Lib.get_lib_size();
            while (int_data1 > Lib_size || int_data1 < 0)
            {
                cout << "Размер библиотеки: " << Lib_size << endl;
                cout << "Ошибка ввода, попробуйте ещё раз" << endl;
            }
            output_lib_size10 = film_gross_search(Lib, int_data1, 0);
            Write_lib(output_lib_size10);
        }
            break;
        case 8: // Узнать текущее число фильмов
        {
            int now_lib_size = get_films_count(Lib);
            cout << "Текущее кол-во фильмов: " << now_lib_size << endl;
        }
            break;
        case 9: // Удалить фильм по названию
        {

            string _title;
            cout << "Введите название фильма: ";
            cin >> _title;
            delete_film(Lib, _title);
        }
            break;
        case 10: // Сохранить Фильмотеку 
            Lib_save(Lib);
            break;
        case 11: // Загрузить Фильмотеку - недописана
            break;
        }

    } while (1);

	return 0;
}