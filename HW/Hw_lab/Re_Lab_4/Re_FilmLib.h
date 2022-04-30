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

	 Film& operator[](int index);
};

class Film_library : public Film
{
 protected:
	 Film* Film_lib = new Film;
	 int size_lib = 0;
public:
	// �����������  & ����������
	//Film_library();
	~Film_library();

	//�������
	int get_size_lib(Film_library _Film_lib);

	//�������
	friend void Add_film(Film_library _Film_lib); // 1 �������� �����
	friend void Film_redactor(Film_library found_film, int _user_choose); // 2 �������� ������ ������ ���������� �� ��������
	friend Film_library title_year_search(Film_library film_mass[], std::string _title, int _year); // 3 ����� ����� �� - �������� � ����
	friend Film_library screenwriter_year_search(Film_library film_mass[], std::string _screenwriter); // 4 ������ ��� ������ ��������� ��������� (�� �� �������)
	friend Film_library year_search(Film_library film_mass[], int _num, int _year); // 5 ������ ��� ������, �������� � ������ � ��������� ���� (�� �� �������)
	friend Film_library film_gross_search(Film_library film_mass[], int num); // 6 ������ �������� ����� ������� � ����������� ������� (�� �� �������)
	friend Film_library year_maxn_gross_search(Film_library film_mass[], int num, int _year); // 7 ������ �������� ����� ������� � ����������� ������� � ��������� ���� (�� �� �������)
	friend int get_films_count(); // 8 ������ ������� ����� �������
	friend void delete_film(std::string _title); // 9 ������� ����� �� ��������

	//���������� ����������
	friend Film_library operator -=(Film_library one, Film two);
	friend Film_library operator +=(Film_library one, Film two);

	// ���������� ���������� ����� � ������ - 10 ��������� ���������� � ���� � ������� ���������� �� �����
	friend std::ostream& operator<<(std::ostream& out, const Film_library& _str);
	friend std::istream& operator>>(std::istream& in, Film_library& _str);


};


// 2 ��������� ������

Film_library search( /*const?*/ Film_library film_mass, std::string _title, int _year) // 3 ����� ����� �� - �������� � ����; - ��������� ����� �� �� �������
{
	Film_library search_result_lib;
	int _size_lub = film_mass.get_size_lib(film_mass);
	if (_size_lub == 0)
	{
		cout << "���������� �����" << endl;
		return  search_result_lib;
	}
	for (int i = 0; i < _size_lub; i++)
	{
		//film_mass[i] =
	}
	return search_result_lib;
};



// 1 �������� ������

// 4 ������ ��� ������ ��������� ��������� (�� �� �������)

Film_library search(Film_library film_mass, string _str_) 
{
	Film_library search_result_lib;
	int _size_lub = film_mass.get_size_lib(film_mass);
	string _title_lib;
	int j = 0;
	if (_size_lub == 0)
	{
		cout << "���������� �����" << endl;
		return film_mass;
	}
	for (int i = 0; i < _size_lub; i++)
	{
		_title_lib = film_mass[i].get_title();
		if (_title_lib == _str_)
		{
			search_result_lib[j] = film_mass[i];
			j++;
		}
	}

		return search_result_lib;
};

// 5 ������ ��� ������, �������� � ������ � ��������� ���� (�� �� �������)
// 6 ������ �������� ����� ������� � ����������� ������� (�� �� �������)
// 7 ������ �������� ����� ������� � ����������� ������� � ��������� ���� (�� �� �������)
Film_library search(Film_library film_mass, int _int_, int option_year)
{
	Film_library search_result_lib;

	return search_result_lib;
};


































/*
* ��� �� � ���������� �����
� ���� ���������� ����� ������� �� ���������� ������� ������ ���������
1)�������� �������� �� �������� ���� + ���� ����������
2)������ Film_library 1 � ������� ����� ������ ����������
(������ ����� ���� �������� ������� ������� ����� ���������� ������ ������)
3)�� for ���� ����� �� �������� ������� ��������� ���� ��� � ������
(���� �� ��� �� ����� �������� ������� ��������� ������ ����� break;)
4)��������� � 1 ������ ������� ������ �� ����� ����� ��������� ����������
	

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
class Film : public Film_int, public Film_str
{
 protected:
	 Film_str str_data;
	 Film_int int_data;

};
class Film_library : public Film
{
 private:
	 Film* Film_lib = new Film;
public:
	// �����������  & ����������
	//Film_library(); - � �� ������ ���������� � ������������� � �� ����� �� ��� �����������
	~Film_library();

3) ����� ����� �� -
�������� � ����,
4)(�� �� �������) ������ ��� ������ ��������� ��������� , - ,
5)(�� �� �������) ������ ��� ������, �������� � - ,
������ � ��������� ����,
6)(�� �� �������) ������ �������� ����� ������� � ����������� �������, -  ,
7)(�� �� �������) ������
�������� ����� ������� � ����������� ������� � ��������� ����, -
*/