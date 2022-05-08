#include <iostream>
#include"Menu.h"
#include"Film_lib_vecrtor.h"
#include"Consoler.h"
#include"SubMenu.h"



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

    Film_library Сurrent_lib = Film_library();
    int itemPos; // позиция в меню - Попробывать передать Int по string т.к при вводе символов меню крашится
    do {
        clrscr();
        itemPos = menu0.selectItem();
        clrscr();
        switch (itemPos)
        {
        case Add_film_lib: // работает
            Add_film(Сurrent_lib);
            break;
        case Change_film: // работает
        {
            if (Сurrent_lib.get_num_of_films() == 0)
            {
                cout << "The library is empty" << endl;
                system("pause");
                break;
            }
            string input_title;
            int _user_choose;
            cout << "Введите название фильма, который желаете изменить: ";
            cin >> input_title;
            do {
                cout << "1)Изменить название фильма\n2)Изменить режисёра фильма\n3)Изменить сценариста фильма\n4)Изменить композитора фильма\n5)Изменить день фильма\n";
                cout << "6)Изменить месяц фильма\n7)Изменить месяц\n8)Изменить сборы фильма\n";
                cin >> _user_choose;
                Film_redactor(Сurrent_lib, input_title, _user_choose);
            } while (_user_choose != 0);
        }
            break;
        case Find_title_year:
            break;
        case Films_director:
            break;
        case Find_film_year:
            break;
        case Film_gross_num: // прописать если размер библиотеки меньше кол-ва выданных фильмов или пустая вообще - 
            break;
        case Film_gross_num_year: // аналогично, для нулевого размера сделать исключение try catch - разобрать иттератор и дописать последний search
            break;
        case Lib_size: // работает
            get_films_count(Сurrent_lib);
            break;
        case Delete_film:
            break;
        case Save_lib: // работает
            Lib_save(Сurrent_lib);
            break;
        case Download_Film: // работает
            Lib_load(Сurrent_lib);
            break;
        }
    } while (itemPos != 0);

    cout << "Программа завершена" << endl;

    return 0;
}