#include <iostream>
#include"Menu.h"
#include"Film_lib.h"
#include"Console.h"



int main()
{

    system("title TextEditor");
 
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleCP(1251);         
    SetConsoleOutputCP(1251);   

    setlocale(LC_CTYPE, "Russian");	

    Menu0 menu0("MainMenu.txt");

    Film_library Ñurrent_lib = Film_library();
    int itemPos; 
    do {
        clrscr();
        itemPos = menu0.selectItem();
        clrscr();
        switch (itemPos)
        {
        case Add_film_lib: 
            Add_film(Ñurrent_lib);
            break;
        case Change_film: 
        {
            if (Ñurrent_lib.get_num_of_films() == 0)
            {
                cout << "The library is empty" << endl;
                system("pause");
                break;
            }
            string input_title;
            int _user_choose;
            cout << "Ââåäèòå íàçâàíèå ôèëüìà, êîòîðûé æåëàåòå èçìåíèòü: ";
            cin >> input_title;
            do {
                cout << "1)Èçìåíèòü íàçâàíèå ôèëüìà\n2)Èçìåíèòü ðåæèñ¸ðà ôèëüìà\n3)Èçìåíèòü ñöåíàðèñòà ôèëüìà\n4)Èçìåíèòü êîìïîçèòîðà ôèëüìà\n5)Èçìåíèòü äåíü ôèëüìà\n";
                cout << "6)Èçìåíèòü ìåñÿö ôèëüìà\n7)Èçìåíèòü ìåñÿö\n8)Èçìåíèòü ñáîðû ôèëüìà\n";
                cin >> _user_choose;
                Film_redactor(Ñurrent_lib, input_title, _user_choose);
            } while (_user_choose != 0);
        }
        break;
        case Find_title_year: 
            if (Ñurrent_lib.get_num_of_films() == 0)
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
                Film_library A = Film_library(title_year_search(Ñurrent_lib, _title, _year));
                Write_Film(A);
            }
            break;
        case Films_director: 
            if (Ñurrent_lib.get_num_of_films() == 0)
            {
                cout << "The library is empty" << endl;
                system("pause");
            }
            else
            {
                string _director;
                cout << "Input the director of the film: " << endl;
                cin >> _director;
                Film_library A = Film_library(screenwriter_year_search(Ñurrent_lib, _director));
                if (A.get_num_of_films() == 0)
                {

                }
                else {
                    Write_lib(A);
                }
            }
            break;
        case Find_film_year: 
            if (Ñurrent_lib.get_num_of_films() == 0)
            {
                cout << "The library is empty" << endl;
                system("pause");
            }
            else
            {
                int _year;
                cout << "Input the year of the film: " << endl;
                cin >> _year;
                Film_library A = Film_library(year_search(Ñurrent_lib, _year));
                if (A.get_num_of_films() == 0)
                {

                }
                else {
                    Write_lib(A);
                }
            }
            break;
        case Film_gross_num: 
            if (Ñurrent_lib.get_num_of_films() == 0) 
            {
                cout << "The library is empty" << endl;
                system("pause");
            }
            else
            {
                int _num;
                cout << "How many movies do you want to output" << endl;
                cin >> _num;
                Film_library A = Film_library(film_gross_search(Ñurrent_lib, _num));
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
        case Film_gross_num_year: 
            if (Ñurrent_lib.get_num_of_films() == 0)
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
                Film_library A = Film_library(year_maxn_gross_search(Ñurrent_lib, _num, _year));
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
        case Lib_size:
            get_films_count(Ñurrent_lib);
            break;
        case Delete_film:
        {
            string _title;
            cout << "Input film title: " << endl;
            cin >> _title;
            delete_film(Ñurrent_lib, _title);
        }
        break;
        case Save_lib: 
            Lib_save(Ñurrent_lib);
            break;
        case Download_Film: 
            Lib_load(Ñurrent_lib);
            break;
        case Write_Library: 
            if (Ñurrent_lib.get_num_of_films() == 0)
            {
                cout << "The library is empty" << endl;
                system("pause");
            }
            else
            {
                Write_lib(Ñurrent_lib);
            }
        }
    } while (itemPos != 0);

    cout << "Ïðîãðàììà çàâåðøåíà" << endl;

    return 0;
}