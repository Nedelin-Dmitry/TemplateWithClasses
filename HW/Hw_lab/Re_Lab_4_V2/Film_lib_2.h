#pragma once

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
 5)������� ������������ �������� �� ����
 6)���� � ����� ���������� �� ����������� �������( ������ ���� � endl ������ ����� ":")
*/
#pragma once

#define LIB_SIZE 10
#define NUM_IN_ASKII 48

#include <cassert> // ��� assert();
#include<iostream>
#include<cstring> 
#include<string>
#include<vector>
#include<fstream>

using namespace std;

struct Date
{
	int day;
	int mount;
	int year;
};

class Film
{
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

	//�������
	void set_day(int _day) { Film_date.day = _day; };
	void set_mount(int _mount) { Film_date.mount = _mount; };
	void set_year(int _year) { Film_date.year = _year; };
	void set_film_gross(int _film_gross) { film_gross = _film_gross; };
	void set_title(std::string _title) { title = _title; };
	void set_director(std::string _director) { director = _director; };
	void set_screenwriter(std::string _screenwriter) { screenwriter = _screenwriter; };
	void set_composer(std::string _composer) { composer = _composer; };


	//�������
	string get_title() { return title; };
	string get_director() { return director; };
	string get_screenwriter() { return screenwriter; };
	string get_composer() { return composer; };
	int get_day() { return Film_date.day; };
	int get_mount() { return Film_date.mount; };
	int get_year() { return Film_date.year; };
	int get_film_gross() { return film_gross; };

	 Film operator=(const Film& film_1);


};

class Film_library : public Film
{
private:
	int lib_size;
	Film* Film_lib;
public:
	//������������
	Film_library();
	Film_library(int _lib_size);
	~Film_library(); //- �������� � ��� ��������� �����������

	int get_lib_size() { return lib_size; };

	friend void Hoare_Sort(Film* Film_lib, int left, int right); // ���������� ����� ��� 6 & 7 �������

	//�������
	friend void Add_film(Film_library _Film_lib); // 1 �������� �����
	friend void Film_redactor(Film_library _Film_lib, string _title, int _user_choose); // 2 �������� ������ ������ ���������� �� ��������
	friend Film_library title_year_search(Film_library _Film_lib, string _title, int _year); // 3 ����� ����� �� - �������� � ���� - string & int
	friend Film_library screenwriter_year_search(Film_library _Film_lib, string _director); // 4 ������ ��� ������ ��������� ��������� (�� �� �������) - string
	friend Film_library year_search(Film_library _Film_lib, int _year); // 5 ������ ��� ������, �������� � ������ � ��������� ���� (�� �� �������) - int
	friend Film_library film_gross_search(Film_library _Film_lib, int num, int _film_gross); // 6 ������ �������� ����� ������� � ����������� ������� (�� �� �������) - int int
	friend Film_library year_maxn_gross_search(Film_library _Film_lib, int num, int _film_gross, int _year); // 7 ������ �������� ����� ������� � ����������� ������� � ��������� ���� (�� �� �������) - int int int
	friend int get_films_count(Film_library _Film_lib); // 8 ������ ������� ����� �������
	friend void delete_film(Film_library _Film_lib, string _title); // 9 ������� ����� �� ��������


	//������� ������
	//2 ��������� - string & int -  3 ����� ����� �� - �������� � ����
	friend Film_library search(Film_library _Film_lib, string _title, int _year);

	// 1 �������� string - 4 ������ ��� ������ ��������� ��������� (�� �� �������) - string
	friend Film_library search(Film_library _Film_lib, string _director);

	// 1 �������� Int - 5 ������ ��� ������, �������� � ������ � ��������� ���� (�� �� �������) - int
	friend Film_library search(Film_library _Film_lib, int _year);

	// 2 ��������� Int 6 ������ �������� ����� ������� � ����������� ������� (�� �� �������) - int int
	friend Film_library search(Film_library _Film_lib, int num, int _film_gross);

	// 3 ��������� Int - 7 ������ �������� ����� ������� � ����������� ������� � ��������� ���� (�� �� �������) - int int int
	friend Film_library search(Film_library _Film_lib, int num, int _film_gross, int _year); 

	Film& operator[](const int index);
	const Film& operator[](const int index) const;

	// ������� ���������� � �������� ���������� �� ����� - 10 ��������� ���������� � ���� � ������� ���������� �� ����� 
	friend void Lib_save (const Film_library& _Film_lib);
	friend void Lib_load(Film_library& _str);

	friend Film Line_to_Film(string _str); // �����������
	
	friend void Write_lib(Film_library _Film_lib);
};
