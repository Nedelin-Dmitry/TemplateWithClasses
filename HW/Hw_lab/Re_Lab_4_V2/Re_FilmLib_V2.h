#pragma once

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
#pragma once

#include<iostream>
#include<cstring> 
#include<string>

using namespace std;

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

	//�������

	//�������
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

	//�������
	string get_title() { return title; };

	//�������
	void set_title(std::string _title) { title = _title; };
	void set_director(std::string _director) { director = _director; };
	void set_screenwriter(std::string _screenwriter) { screenwriter = _screenwriter; };
	void set_composer(std::string _composer) { composer = _composer; };


};

class Film : public Film_int, public Film_str
{
protected:
	Film_str str_data;
	Film_int int_data;
public:

	
};

