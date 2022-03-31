/*6. ����������
����������� ����� FilmLibrary.
����� ������ ������� ���������� � �������.������ ����� ����������� ����������
������� : ��������, ��������, ���������, ����������, ���� ������ � ������(����, �����, ���),
�����(� ������).������ �������� ������������ �� �������� � �����.������ �������� ��
������� �����.
����� ������ ��������� ����������� ��������� ������(������������, ����������, �)..
����� ������ ������������� ��������� �������� :
10) ��������� ���������� � ���� � ������� ���������� �� �����. - ������� � ����������� ����� � ������
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
*/
#pragma once
#include<iostream>
#include<cstring> 

class Film_int
{
private:
	int* data = new int[3];
	int film_gross;
public:
	Film_int();
	Film_int(int _day, int _mount, int _year, int _film_gross);
	~Film_int();
	void set_day(int _day);
	void set_mount(int _mount);
	void set_year(int _year);
	void set_film_gross(int _gross);


	friend class Film_library;
};

class Film_str 
{
private:
	std::string title;
	std::string director;
	std::string screenwriter;
	std::string composer;
	
public:
	Film_str();
	Film_str(std::string _title, std::string _director, std::string _screenwriter, std::string _composer);
	void set_title(std::string _title);
	void set_director(std::string _director);
	void set_screenwriter(std::string _screenwriter);
	void set_composer(std::string _composer);


	friend class Film_library;
};

class Film_library
{
private:
	Film_str lib_str;
	Film_int lib_int;
public:
	void Add_film();//1
	Film_library title_year_search(std::string _title, int _year);//3
	Film_library screenwriter_year_search(std::string _screenwriter);//4
	Film_library year_search(int _year);//5
	Film_library film_gross_search(int num);//6
	Film_library year_maxn_gross_search(int _year, int quality);//7
	int get_films_count();//8
	void delete_film(std::string _title);//9
};

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
*/