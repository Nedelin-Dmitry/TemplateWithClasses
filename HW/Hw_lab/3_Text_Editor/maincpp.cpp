#include <iostream>
#include"Text_Editor.h"
#include"Menu.h"
#include"Console.h"
#include"SubMenu.h"

using namespace std;

int main() {
    // ����� �������� ����������� ����
    system("title TextEditor");

    // �������� ���������� ���� ��� ��������� � �������
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    // ������������� �������������� � �������� �������
    SetConsoleCP(1251);         // ��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);   // ��������� ������� �������� win-cp 1251 � ����� ������

    setlocale(LC_CTYPE, "Russian");  // ��� �����-������ ������� ����

    Menu0 menu0("MainMenu.txt");

    TextEditor Editor = TextEditor();
    int itemPos;  // ������� � ���� - ����������� �������� Int �� string �.� ��� ����� �������� ���� ��������
    do {
        clrscr();
        itemPos = menu0.selectItem();
        cout << "������� " << itemPos << " +++++++++++++++++++++++++++" << endl;
        clrscr();
        switch (itemPos) {
        case 0: // ����� �� ���������� ���������
            off_editor(hStdOut, Editor);
            break; // ����� �� break? �� �������� � ��� ����
        case 1: // ������ ��������� ���������
            on_text_editor(hStdOut, Editor);
            break;
        case 2:
            SubMenu_work(hStdOut, Editor);
            system("pause");
            break;
        case 3:
            cout << "��� ����, ����� ������� �������� - ������� ����� ������" << endl;
            system("pause");
            hide_show_editor(Editor);
        }

    } while (1);

    return 0;

}