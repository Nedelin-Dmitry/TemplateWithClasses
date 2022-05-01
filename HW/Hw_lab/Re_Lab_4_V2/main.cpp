#include <iostream>
#include"Film_lib_2.h"
#include"Menu_Film_lib.h"
#include"Console_Film_lib.h"
#include"Submenu_Film_lib.h"

int int_data1 = 0, int_data2 = 0, int_data3 = 0;
string str_data1, str_data2;


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
        case 1: // Добавить фильм
            Add_film(Lib);
            cout << "Фильм добавлен" << endl;
            break;
        case 2: // Изменить данные фильма выбранного по названию(не работает)
            //SubMenu_work(hStdOut, Lib);
            system("pause");
            break;
        case 3: //Найти фильм по названию и году
            cout << "Введите название фильма: ";
            cin >> str_data1;
            cout << "Введит год фильма:";
            cin >> int_data1;
            title_year_search(Lib, str_data1, int_data1);
            Write_film(Lib);
            break;
        case 4: // Выдать все фильмы заданного режиссера
            cout << "Введите Режисёра фильма: ";
            cin >> str_data1;
            screenwriter_year_search(Lib, str_data1);
            Write_film(Lib);
            break;
        case 5: //Выдать все фильмы, вышедшие в прокат в выбранном году
            cout << "Введите год: ";
            cin >> int_data1;
            year_search(Lib, int_data1);
            Write_film(Lib);
            break;
        case 6: //Выдать заданное число фильмов с наибольшими сборами
            cout << "Введите сколько фильмов вы хотите вывести: ";
            cin >> int_data1;
            film_gross_search(Lib, int_data1, 0);
            Write_film(Lib2);
            break;
        case 7: //Выдать заданное число фильмов с наибольшими сборами в выбранном году
            break;
        case 8: // Узнать текущее число фильмов
            break;
        case 9: // Удалить фильм по названию
            break;
        case 10: // Сохранить Фильмотеку 
            break;
        case 11: // Закрузить Фильмотеку(не работает)
            break;
        }

    } while (1);
	return 0;
}