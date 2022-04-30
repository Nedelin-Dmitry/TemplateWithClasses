/*6. ����������
����������� ����� FilmLibrary.
����� ������ ������� ���������� � �������.������ ����� ����������� ����������
������� : 
class Film_str
�������� - title
�������� - director
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
4) ������ ��� ������ ��������� ���������, - ,
5) ������ ��� ������, �������� � - ,
������ � ��������� ����, 
6) ������ �������� ����� ������� � ����������� �������, -  ,
7) ������
�������� ����� ������� � ����������� ������� � ��������� ����, - 
8) ������ ������� ����� - ,
�������, 
9) ������� ����� �� ��������, - ,
��������� ������ ����� ������� ���� ��� ������ ����������� ��������.
10) ��������� ���������� � ���� � ������� ���������� �� �����. - ������� � ����������� ����� � ������
*/
#pragma once

#include<iostream>
#include<cstring> 
#include<string>



class Film_int
{
protected:
	int day;
	int mount;
	int year;
	int film_gross;
public:
	Film_int();
	Film_int(int _day, int _mount, int _year, int _film_gross);
	//����������?
	void set_day(int _day) { day = _day; };
	void set_mount(int _mount) { mount = _mount; };
	void set_year(int _year) { year = _year; };
	void set_film_gross(int _film_gross) { film_gross = _film_gross; };

};

class Film_str 
{
 protected:
	std::string title;
	std::string director;
	std::string screenwriter;
	std::string composer;
	
public:
	Film_str();
	Film_str(std::string _title, std::string _director, std::string _screenwriter, std::string _composer);

	//����������?

	void set_title(std::string _title) { title = _title; };
	void set_director(std::string _director) { director = _director; };
	void set_screenwriter(std::string _screenwriter) { screenwriter = _screenwriter; };
	void set_composer(std::string _composer) { composer = _composer; };


};

class Film_library : public Film_int, public Film_str // ��� ��������� ������ �������? - Film
{
private:
	Film_str lib_str;
	Film_int lib_int;
public:
	//friend void Add_film(); // 1 �������� �����
	friend void Film_redactor(Film_library found_film, int _user_choose); // 2 �������� ������ ������ ���������� �� ��������
	friend void title_year_search(Film_library film_mass[], std::string _title, int _year); // 3 ����� ����� �� - �������� � ����
	friend void screenwriter_year_search(Film_library film_mass[], std::string _screenwriter); // 4 ������ ��� ������ ��������� ���������
	friend void year_search(Film_library film_mass[], int _num, int _year); // 5 ������ ��� ������, �������� � ������ � ��������� ����
	friend void film_gross_search(Film_library film_mass[], int num); // 6 ������ �������� ����� ������� � ����������� �������
	friend void year_maxn_gross_search(Film_library film_mass[], int num, int _year); // 7 ������ �������� ����� ������� � ����������� ������� � ��������� ����
	friend int get_films_count(); // 8 ������ ������� ����� �������
	friend void delete_film(std::string _title); // 9 ������� ����� �� ��������

	// ���������� ���������� ����� � ������ - 10 ��������� ���������� � ���� � ������� ���������� �� �����
	friend std::ostream& operator<<(std::ostream& out, const Film_library& _str);
	friend std::istream& operator>>(std::istream& in, Film_library& _str);
};

/*
class Film_library : public Film, public Film_int, public Film_str // ��������� ����� �� virtual
{
protected:
	Film* Lib = new Film;
public:
	//friend void Add_film(); // 1 �������� �����
	friend void Film_redactor(Film_library found_film, int _user_choose); // 2 �������� ������ ������ ���������� �� ��������
	friend void title_year_search(Film_library film_mass[], std::string _title, int _year); // 3 ����� ����� �� - �������� � ����
	friend void screenwriter_year_search(Film_library film_mass[], std::string _screenwriter); // 4 ������ ��� ������ ��������� ���������
	friend void year_search(Film_library film_mass[], int _num, int _year); // 5 ������ ��� ������, �������� � ������ � ��������� ����
	friend void film_gross_search(Film_library film_mass[], int num); // 6 ������ �������� ����� ������� � ����������� �������
	friend void year_maxn_gross_search(Film_library film_mass[], int num, int _year); // 7 ������ �������� ����� ������� � ����������� ������� � ��������� ����
	friend int get_films_count(); // 8 ������ ������� ����� �������
	friend void delete_film(std::string _title); // 9 ������� ����� �� ��������

	// ���������� ���������� ����� � ������ - 10 ��������� ���������� � ���� � ������� ���������� �� �����
	friend std::ostream& operator<<(std::ostream& out, const Film_library& _str);
	friend std::istream& operator>>(std::istream& in, Film_library& _str);

}
*/
//class menu{...}; 
/*
10) ��������� ���������� � ���� � ������� ���������� �� �����. - ������� � ����������� ����� � ������
.1) �������� �����,  - 
.2) �������� ������ ������ ���������� �� ��������,  - 
.3) ����� ����� �� - 
�������� � ����,  
.4) ������ ��� ������ ��������� ���������, - ,
.5) ������ ��� ������, �������� � - ,
������ � ��������� ����, 
.6) ������ �������� ����� ������� � ����������� �������, -  ,
.7) ������
�������� ����� ������� � ����������� ������� � ��������� ����, - 
.8) ������ ������� ����� - ,
�������, 
.9) ������� ����� �� ��������, - ,
��������� ������ ����� ������� ���� ��� ������ ����������� ��������
10) ��������� ���������� � ���� � ������� ���������� �� �����. - ������� � ����������� ����� � ������
*/