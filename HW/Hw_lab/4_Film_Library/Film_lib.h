#pragma once
// Copyright 2022 Nedelin-Dmitry
/*6. ����������
����������� ����� FilmLibrary.
����� ������ ������� ���������� � �������.������ ����� ����������� ����������
������� :
class Film_str
�������� - title
�������� - director (��������� �����?)
��������� - screenwriter
���������� - composer
�lass Film_int
���� ������ � ������(����, �����, ���) - date, mount, year
�����(� ������)  - film_gross
������ �������� ������������ �� �������� � �����.������ �������� ��
������� �����.
����� ������ ��������� ����������� ��������� ������(������������, ����������, �)..
����� ������ ������������� ��������� �������� :
1) �������� �����,  -
2) �������� ������ ������ ���������� �� ��������,  -
3) ����� ����� �� -
�������� � ����,
4)(�� �� �������) ������ ��� ������ ��������� ��������� , - ,
5)(�� �� �������) ������ ��� ������, �������� � - ,
������ � ��������� ����,
6)(�� �� �������) ������ �������� ����� ������� � ����������� �������, -  ,
7)(�� �� �������) ������
�������� ����� ������� � ����������� ������� � ��������� ����, -
8) ������ ������� ����� - ,
�������,
9) ������� ����� �� ��������, - ,
��������� ������ ����� ������� ���� ��� ������ ����������� ��������.
10) ��������� ���������� � ���� � ������� ���������� �� �����. - ������� � ����������� ����� � ������
*/

/*
 ��������� ���������������� ����:
 1)���������� ����������[]
 2)������ ������� - ��� ���� ����� ���� ����� ��������? + �������� � �����
 3)�������� � ��� �������� �����������
 4)���������� print

������ ������� ������ - ����������� �������� >> � ������� � �����������
*/
#pragma once

#define START_LIB_SIZE 0
#define NUM_IN_ASKII 48
#define SPACE_IN_ASKII 32

#include<iostream>
#include<cstring> 
#include<string>
#include<vector>
#include<fstream>
#include <algorithm>  // sort

using namespace std;

struct Date {
    int day;
    int mount;
    int year;
};



enum menu_selection {
    Exit = 0,
    Add_film_lib = 1,
    Change_film = 2,
    Find_title_year = 3,
    Films_director = 4,
    Find_film_year = 5,
    Film_gross_num = 6,
    Film_gross_num_year = 7,
    Lib_size = 8,
    Delete_film = 9,
    Save_lib = 10,
    Download_Film = 11,
    Write_Library = 12
};

enum film_data {
    _title = 1,
    _director = 2,
    _screenwriter = 3,
    _composer = 4,
    _day = 5,
    _mount = 6,
    _year = 7,
    _gross = 8
};

class Film {
 protected:
    string title;
    string director;
    string screenwriter;
    string composer;
    Date Film_date;
    int film_gross;
  public:
    // ������������
    Film();

    // �������
    void set_day(int _day) { Film_date.day = _day; }
    void set_mount(int _mount) { Film_date.mount = _mount; }
    void set_year(int _year) { Film_date.year = _year; }
    void set_film_gross(int _film_gross) { film_gross = _film_gross; }
    void set_title(std::string _title) { title = _title; }
    void set_director(std::string _director) { director = _director; }
    void set_screenwriter(std::string _screenwriter) { screenwriter = _screenwriter; }
    void set_composer(std::string _composer) { composer = _composer; }

    // �������
    string get_title() { return title; }
    string get_director() { return director; }
    string get_screenwriter() { return screenwriter; }
    string get_composer() { return composer; }
    int get_day() { return Film_date.day; }
    int get_mount() { return Film_date.mount; }
    int get_year() { return Film_date.year; }
    int get_film_gross() { return film_gross; }

    Film operator=(const Film& film_1);
    bool operator<(const Film& a) const { return film_gross < a.film_gross; }
};

class Film_library
{
 private:
    int num_of_films;
    vector <Film> Film_lib;
 public:
    // ������������
    Film_library();
    Film_library(const Film_library& copy);
    ~Film_library();
    // ������
    int get_num_of_films() { return num_of_films; }
    // �������
    friend void Add_film(Film_library& _Film_lib);  // 1 �������� �����
    // 2 �������� ������ ������ ���������� �� ��������
    friend void Film_redactor(Film_library& _Film_lib, string _title_, int _user_choose);
    // 3 ����� ����� �� - �������� � ����
    friend Film_library title_year_search(Film_library& _Film_lib, string _title, int _year);
    // 4 ������ ��� ������ ��������� ��������� (�� �� �������)
    friend Film_library screenwriter_year_search(Film_library& _Film_lib, string _director); 
    // 5 ������ ��� ������, �������� � ������ � ��������� ���� (�� �� �������)
    friend Film_library year_search(Film_library& _Film_lib, int _year); 
    // 6 ������ �������� ����� ������� � ����������� ������� (�� �� �������)
    friend Film_library film_gross_search(Film_library& _Film_lib, int num); 
    // 7 ������ �������� ����� ������� � ����������� ������� � ��������� ���� (�� �� �������)
    friend Film_library year_maxn_gross_search(Film_library& _Film_lib, int num, int _year);
    // 8 ������ ������� ����� �������
    friend void get_films_count(Film_library& _Film_lib);
    // 9 ������� ����� �� ��������
    friend void delete_film(Film_library& _Film_lib, string _title);
    // ������� ���������� � �������� ���������� �� ����� - 10 ��������� ���������� � ���� � ������� ���������� �� ����� 
    friend void Lib_save(const Film_library& _Film_lib);
    friend void Lib_load(Film_library& _str);
    // 
    friend Film Line_to_Film(string _line);
    // ������� ������ - ���������� � ����������>>
    friend void Write_Film(Film_library& _Film);
    friend void Write_lib(Film_library& _Film_lib);

};