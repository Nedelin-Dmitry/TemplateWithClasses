#include"Text_Editor.h"


TextEditor::TextEditor(){
    text_pos.X = 0;
    text_pos.Y = 0;
    text_len = 10;
    text = new char[text_len];
}

TextEditor::TextEditor(short int x, short int y, int len){
    text_pos.X = x;
    text_pos.Y = y;
    text_len = len;
    text = new char[text_len];
}

TextEditor::TextEditor(const TextEditor& copy){
    text_pos.X = copy.text_pos.X;
    text_pos.Y = copy.text_pos.Y;
    text_len = copy.text_len;
    text = new char[text_len];
    for (int i = 0; i < text_len; i++){
        text[i] = copy.text[i];
    }
}

TextEditor::~TextEditor(){
    delete[] text;
}

COORD TextEditor::get_pos() { return text_pos; };
int TextEditor::get_len() { return text_len; };
char* TextEditor::get_text() { return text; };

void window_position(HANDLE _hStdOut, short int _x_pos_win, short int _y_pos_win, short int _weight_win, short int _height_win, TextEditor& ZERO){
    HWND hWnd = FindWindow(nullptr, L"TextEditor"); // �������� ���������� ���� �� title
    SetWindowPos(hWnd, nullptr, _x_pos_win, _y_pos_win, _weight_win, _height_win, SWP_NOOWNERZORDER); //����� ��������� ���� - ���� ��� �������� �� ��� Z
}

void window_size(HANDLE _hStdOut, short int _x_pos_win, short int _y_pos_win, short int _weight_win, short int _height_win, TextEditor& ZERO){

    //������� ������ ����������� �������� ����� �� ������
    SMALL_RECT zeroWindow = { 0, 0, 0, 0 };
    COORD zBuffer = { 1, 1 };
    SetConsoleWindowInfo(_hStdOut, TRUE, &zeroWindow);
    SetConsoleScreenBufferSize(_hStdOut, zBuffer);

    //������ �������� �������� �� ������ ���
    COORD bufferSize = { _weight_win, _height_win };
    SMALL_RECT windowSize = { _x_pos_win, _y_pos_win, _weight_win - 1, _height_win - 1 };
    SetConsoleScreenBufferSize(_hStdOut, bufferSize);
    // ������� ������ �������, ���� ����� ������� ������������� ������� �������� ������, ��� ��������������� ������ ���� �������
    SetConsoleWindowInfo(_hStdOut, TRUE, &windowSize);
}   // ������� �� ��������� ���� ������, ���� ���������� ���� ������������� ���� ��������� ������� ��������� ������ ������� ��� ������

void hide_show_editor(TextEditor& ZERO){
    HWND hWnd = FindWindow(nullptr, L"TextEditor");
    ShowWindow(hWnd, 0);
    system("pause");
    ShowWindow(hWnd, 1);
}

void on_text_editor(HANDLE _hStdOut, TextEditor& EditorWork){
    int len = EditorWork.text_len;
    SetConsoleCursorPosition(_hStdOut, EditorWork.text_pos);
    DWORD _cWrittenChars;
    FillConsoleOutputCharacter(_hStdOut, (TCHAR)'_', EditorWork.text_len, EditorWork.text_pos, &_cWrittenChars);  // ���������� ������ � �������� ������ ������� �������� ����� ���
    SetConsoleCursorPosition(_hStdOut, EditorWork.text_pos);
    // ���� ������ � �������������� �� ���� insert
    // ����� �� ������� ESC, �� ���� ����� ����� ��������� � ������� �������
    int iKey = 67;              // ��������
    int started_pos_x = EditorWork.text_pos.X;
    CONSOLE_SCREEN_BUFFER_INFO cbsi;

    while (iKey != KEY_EXIT && len > 0 && iKey != KEY_ENTER) {
        switch (iKey){
        case KEY_ARROW_LEFT:
            GetConsoleScreenBufferInfo(_hStdOut, &cbsi);                // ��������� ���������� � �������� �������� ������ �������
            EditorWork.text_pos.X = cbsi.dwCursorPosition.X - 1;        // ������� ������� ��������� ������� �� ������ �����
            SetConsoleCursorPosition(_hStdOut, EditorWork.text_pos);
            len++;
            iKey = 67;
            break;
        case KEY_ARROW_RIGHT:
            GetConsoleScreenBufferInfo(_hStdOut, &cbsi);
            EditorWork.text_pos.X = cbsi.dwCursorPosition.X + 1;
            SetConsoleCursorPosition(_hStdOut, EditorWork.text_pos);
            len--;
            iKey = 67;
            break;
        case KEY_BACKSPACE:
            GetConsoleScreenBufferInfo(_hStdOut, &cbsi);   // ��������� ���������� � �������� �������� ������ �������              
            if (len == EditorWork.text_len){               // ��� ������� break - ��������� ��������
                std::cout << (char)'_';
                EditorWork.text_pos.X = cbsi.dwCursorPosition.X;
                SetConsoleCursorPosition(_hStdOut, EditorWork.text_pos);
                iKey = 67;
                break;
            }
            else{
                EditorWork.text_pos.X = cbsi.dwCursorPosition.X - 1;        // �������� �� 1 ����� -> set
                SetConsoleCursorPosition(_hStdOut, EditorWork.text_pos);
                std::cout << (char)'_';                                     // ��� ����� �������, ������� ������������� ����������� ������ ������
                EditorWork.text_pos.X = cbsi.dwCursorPosition.X - 1;        // �������� ����� -> set
                SetConsoleCursorPosition(_hStdOut, EditorWork.text_pos);
                len++;
                iKey = 67;
                break;
            }
        case KEY_SPACE:
            GetConsoleScreenBufferInfo(_hStdOut, &cbsi);       // ��������� ���������� � �������� �������� ������ �������
            std::cout << (char)' ';
            EditorWork.text_pos.X = cbsi.dwCursorPosition.X - 1;        // ������� ������� ��������� ������� �� ������ �����
            SetConsoleCursorPosition(_hStdOut, EditorWork.text_pos);
            len--;
            iKey = 67;
            break;

        default:
            iKey = _getch();
            if (iKey == KEY_EXIT || iKey == ARROW_KEY || iKey == KEY_SPACE
                || iKey == KEY_ARROW_LEFT || iKey == KEY_ARROW_RIGHT || iKey == KEY_ARROW_DOWN || iKey == KEY_ARROW_UP || iKey == KEY_BACKSPACE)break;
            else {
                std::cout << (char)iKey;    // ������ ���� ��� ������ ������ ���������� ��� � �������
                len--;
                break;
            }
        }
    }

    // ��������� ���������� � ������� ����� � ������ (������ ��������)
    wchar_t* Chars = new wchar_t[EditorWork.text_len + 1];
    DWORD dwRead;
    ReadConsoleOutputCharacter(_hStdOut, Chars, EditorWork.text_len, { EditorWork.text_pos.X, EditorWork.text_pos.Y }, &dwRead);
    Chars[EditorWork.text_len] = '\0';
    system("CLS");
    std::wcout << "Your finale text: " << Chars << std::endl;  //wcout: ����� �������� � � wchar_t � � char - cout: ����� �������� ������ � char
    system("pause");

}

void off_editor(HANDLE _hStdOut, TextEditor& EditorOff)
{
    COORD curs_pos;
    curs_pos.X = 0;
    curs_pos.Y = 0;
    SetConsoleCursorPosition(_hStdOut, curs_pos);
    std::cout << "The program is closed";
    exit(0);
}