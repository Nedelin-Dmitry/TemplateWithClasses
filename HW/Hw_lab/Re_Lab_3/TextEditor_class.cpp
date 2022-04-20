#include"TextEditor.h"


TextEditor::TextEditor()
{
	text_pos = { 0, 0 };
	text_len = 10;
	text = new char[text_len];
}

TextEditor::TextEditor(short int x, short int y, int len)
{
    text_pos.X = x;
    text_pos.Y = y;
	text_len = len;
	text = new char[text_len];
}

TextEditor::TextEditor(TextEditor& copy)
{
	text_pos = copy.text_pos;
	text_len = copy.text_len;
    text = new char[text_len];
    for (int i = 0; i < text_len; i++)
    {
        text[i] = copy.text[i];
    }
}

TextEditor::~TextEditor()
{
	delete[] text;
}

COORD TextEditor::get_pos() { return text_pos; };
int TextEditor::get_len() { return text_len; };
char* TextEditor::get_text() { return text; };

void on_text_editor(HANDLE _hStdOut, TextEditor& EditorWork)
{
	int len = EditorWork.text_len;
	SetConsoleCursorPosition(_hStdOut, EditorWork.text_pos);
    DWORD _cWrittenChars;
	FillConsoleOutputCharacter(_hStdOut, (TCHAR)'_', EditorWork.text_len, EditorWork.text_pos, &_cWrittenChars);  // ���������� ������ � �������� ������ ������� �������� ����� ���
	SetConsoleCursorPosition(_hStdOut, EditorWork.text_pos);
    // ���� ������ � �������������� �� ���� insert
    // ����� �� ������� ESC, �� ���� ����� ����� ��������� � ������� �������
    int iKey = 67;              // ������ ��������
    CONSOLE_SCREEN_BUFFER_INFO cbsi;

    while (iKey != KEY_EXIT && len > 0) {
        switch (iKey)
        {
        case KEY_ARROW_LEFT:
            GetConsoleScreenBufferInfo(_hStdOut, &cbsi);       // ��������� ���������� � �������� �������� ������ �������
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
        case KEY_BACKSPACE: // ��������?
            GetConsoleScreenBufferInfo(_hStdOut, &cbsi);       // ��������� ���������� � �������� �������� ������ �������
            std::cout << (char)'-';
            EditorWork.text_pos.X = cbsi.dwCursorPosition.X - 1;        // ������� ������� ��������� ������� �� ������ �����
            SetConsoleCursorPosition(_hStdOut, EditorWork.text_pos);
            len++;
            iKey = 67;
            break;
        case KEY_SPACE:
            GetConsoleScreenBufferInfo(_hStdOut, &cbsi);       // ��������� ���������� � �������� �������� ������ �������
            std::cout << (char)' ';
            EditorWork.text_pos.X = cbsi.dwCursorPosition.X - 1;        // ������� ������� ��������� ������� �� ������ �����
            SetConsoleCursorPosition(_hStdOut, EditorWork.text_pos);
            len++;
            iKey = 67;
            break;
        case KEY_ENTER:
            // ��������� ������ � ������ ������
            break;
        case KEY_ARROW_UP: // ����� ����� "H" & "D" // ��������?
            break;
        case KEY_ARROW_DOWN: // ��������?
            break;
        default:
            iKey = _getch();
            if (iKey == KEY_EXIT || iKey == ARROW_KEY || iKey == KEY_SPACE
                || iKey == KEY_ARROW_LEFT || iKey == KEY_ARROW_RIGHT) break;
            std::cout << (char)iKey;    // ������ ���� ��� ������ ������ ���������� ��� � �������
            len--;
            break;
        }
    }

    // ��������� ���������� � ������� ����� � ������ (������ ��������)
    wchar_t *Chars = new wchar_t[len + 1];
    DWORD dwRead;
    ReadConsoleOutputCharacter(_hStdOut, Chars, len, { EditorWork.text_pos.X, EditorWork.text_pos.Y }, &dwRead); // ??????????????????
    Chars[len] = '\0';
    system("CLS");

    std::cout << "Your finale text: " << Chars << std::endl;
    system("pause");



}