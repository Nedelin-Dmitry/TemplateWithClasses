#include <iostream>
using namespace std;

#include"SubMenu.h"
#include"Menu.h"
#include"Console.h"
#include"Text_Editor.h"

// Copyright 2022 Nedelin-Dmitry

int x = 0, y = 0;
short int weight = 600;
short int height = 600;

int width_buffer;


COORD For_set_positio = { 0, 0 };

CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;


int new_len = 10;

TextEditor For_copy;

void SubMenu_work(HANDLE _hStdOut, TextEditor& ZERO) {
    For_copy = TextEditor(ZERO);
    // setlocale(LC_CTYPE, "Russian"); // For input/output of Russian letters

    Menu0 menu0("SubMenu.txt");
    /*
    * Parameters - header
    3 - number of choices (not counting the output)
    Change the initial position of the window - Names of options
    Change window size
    Change the starting position of the line
    Change String length

    */
    int itemPos;
    do {
        clrscr();
        itemPos = menu0.selectItem();
        cout << "¬ыбрано " << itemPos << " +++++++++++++++++++++++++++" << endl;
        clrscr();
        switch (itemPos) {
        case 1:
            GetConsoleScreenBufferInfo(_hStdOut, &screen_buffer_info);
            cout << "¬ведите положение окна по X:" << endl;
            cin >> x;
            cout << "¬ведите положение окна по Y:" << endl;
            cin >> y;
            {
                int _weight = weight;
                int _height = height;
                window_position(_hStdOut, x, y, _weight, _height, ZERO);
            }
            break;
        case 2:
            GetConsoleScreenBufferInfo(_hStdOut, &screen_buffer_info);
            cout << "¬ведите ширину окна не превышающую " 
                << screen_buffer_info.dwMaximumWindowSize.X << ":" << endl;
            cin >> weight;
            cout << "¬ведите высоту окна не превышающую " 
                << screen_buffer_info.dwMaximumWindowSize.Y << ":" << endl;
            cin >> height;
            window_size(_hStdOut, x, y, weight, height, ZERO);
            break;
        case 3: 
            GetConsoleScreenBufferInfo(_hStdOut, &screen_buffer_info);
            {
                int for_control_len = ZERO.get_len();
                do {
                    cout << "¬ведите положение строки по X не превышающую " 
                        << screen_buffer_info.dwSize.X - for_control_len << ":" << endl;
                    cin >> For_set_positio.X;
                    if (For_set_positio.X < 0 ||
                        For_set_positio.X > screen_buffer_info.dwSize.X - for_control_len){
                        cout << "ќшибка ввода, попробуйте ещЄ!" << endl;
                    }
                } while (For_set_positio.X < 0 ||
                    For_set_positio.X > screen_buffer_info.dwSize.X - for_control_len);
                do {
                    cout << "¬ведите положение строки по Y не превышающую:" 
                        << screen_buffer_info.dwSize.Y << endl;
                    cin >> For_set_positio.Y;
                    if ((For_set_positio.Y < 0 ||
                        For_set_positio.X > screen_buffer_info.dwSize.Y)){
                        cout << "ќшибка ввода, попробуйте ещЄ!" << endl;
                    }
                } while (For_set_positio.Y < 0 ||
                    For_set_positio.X > screen_buffer_info.dwSize.Y);
                TextEditor().set_pos(For_set_positio, ZERO);  // creating a temporary object for work
            }
            break;
        case 4:
            GetConsoleScreenBufferInfo(_hStdOut, &screen_buffer_info);
            COORD for_control_x_pos = ZERO.get_pos();
            cout << "¬ведите длину строки больше 0 и не превышающую " 
                << screen_buffer_info.dwSize.X - for_control_x_pos.X << ":" << endl;
            do {
                cin >> new_len;
                if (new_len <= 0 || new_len > screen_buffer_info.dwSize.X) {
                    cout << "ќшибка ввода, попробуйте ещЄ!" << endl;
                }
            } while (new_len <= 0 ||
                new_len > (screen_buffer_info.dwSize.X - for_control_x_pos.X));
            TextEditor().set_len(new_len, ZERO);
            break;
        }
    } while (itemPos != 0);
}