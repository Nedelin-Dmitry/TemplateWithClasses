#include <iostream>
#include"Text_Editor.h"
#include"Menu.h"
#include"Console.h"
#include"SubMenu.h"

using namespace std;

int main() {
    // setting the name of the console window
    system("title TextEditor");

    // getting a window handle to access the console
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    // we establish interaction with Russian letters
    SetConsoleCP(1251);         // installing the win-cp 1251 code page in the input stream
    SetConsoleOutputCP(1251);   // installing the win-cp 1251 code page in the output stream

    setlocale(LC_CTYPE, "Russian");  // For input/output of Russian letters

    Menu0 menu0("MainMenu.txt");

    TextEditor Editor = TextEditor();
    // the position in the menu is to try to pass Int by string, because when entering characters, the menu crashes
    int itemPos;
    do {
        clrscr();
        itemPos = menu0.selectItem();
        clrscr();
        switch (itemPos) {
        case 0: // exiting the text editor
            off_editor(hStdOut, Editor);
            break; // do I need a break? everything works without it
        case 1: // the work of a text editor
            on_text_editor(hStdOut, Editor);
            break;
        case 2:
            SubMenu_work(hStdOut, Editor);
            system("pause");
            break;
        case 3:
            cout << "Для того, чтобы вернуть редактор - нажмите любую кнопку" << endl;
            system("pause");
            hide_show_editor(Editor);
        }

    } while (1);

    return 0;

}