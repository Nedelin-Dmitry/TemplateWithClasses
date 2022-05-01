#include"Re_FilmLib.h"

using namespace std;


/*
class Film_str
�������� - title
�������� - director
��������� - screenwriter
���������� - composer
�lass Film_int
���� ������ � ������(����, �����, ���) - date, mount, year
�����(� ������)  - film_gross
*/


Film::Film()
{
	title = '-';
	director = '-';
	screenwriter = '-';
	composer = '-';
	day = 0;
	mount = 0;
	year = 0;
	film_gross = 0;
}

Film Film::operator=(const Film& film_1)
{
	title = film_1.title;
	director = film_1.director;
	screenwriter = film_1.screenwriter;
	composer = film_1.composer;
	day = film_1.day;
	mount = film_1.mount;
	year = film_1.year;
	film_gross = film_1.film_gross;
}


Film_library::Film_library()
{
	lib_size = 10;
	Film_lib = new Film[lib_size];

}

Film_library::Film_library(int _lib_size)
{
	lib_size = _lib_size;
	Film_lib = new Film[lib_size];
}

Film_library::~Film_library()
{
	delete[] &Film_lib;
}

int& Film_library::operator[](const int index)
{

}

const int& Film_library::operator[](const int index) const
{

}


void Add_film(Film_library _Film_lib)
{
	string for_add_str;
	int for_add_int;
	std::cout << "������� �������� ������:" << endl;
	std::cin >> for_add_str;
	_Film_lib.set_title(for_add_str);
	std::cout << "������� ������� ������:" << endl;
	std::cin >> for_add_str;
	_Film_lib.set_director(for_add_str);
	std::cout << "������� ���������� ������:" << endl;
	std::cin >> for_add_str;
	_Film_lib.set_screenwriter(for_add_str);
	std::cout << "������� ����������� ������:" << endl;
	std::cin >> for_add_str;
	_Film_lib.set_composer(for_add_str);
	std::cout << "������� ���� ������ ������:" << endl;
	std::cin >> for_add_int;
	_Film_lib.set_day(for_add_int);
	std::cout << "������� ����� ������ ������:" << endl;
	std::cin >> for_add_int;
	_Film_lib.set_mount(for_add_int);
	std::cout << "������� ��� ������ ������:" << endl;
	std::cin >> for_add_int;
	_Film_lib.set_year(for_add_int);
	std::cout << "������� ����� ������:" << endl;
	std::cin >> for_add_int;
	_Film_lib.set_film_gross(for_add_int);
	
};

void Film_redactor(Film_library _film_lib, string _title, int _user_choose) // 2 �������� ������ ������ ���������� �� ��������
{
	for (int i = 0; i < _film_lib[i].get_size_lib(_film_lib); i++)
	{
		if (_film_lib.Film_lib[i].get_title() == _title)
		{
			switch (_user_choose)
			{

			case 1:
			{
				string for_add_str;
				std::cout << "������� �������� ������:";
				std::cin >> for_add_str;
				_film_lib.set_title(for_add_str);
			}
			break;
			case 2:
			{
				string for_add_str;
				std::cout << "������� ������� ������:";
				std::cin >> for_add_str;
				_film_lib.set_director(for_add_str);
			}
			break;
			case 3:
			{
				string for_add_str;
				std::cout << "������� ���������� ������:";
				std::cin >> for_add_str;
				_film_lib.set_screenwriter(for_add_str);
			}
			break;
			case 4:
			{
				string for_add_str;
				std::cout << "������� ����������� ������:";
				std::cin >> for_add_str;
				_film_lib.set_composer(for_add_str);
			}
			break;
			case 5:
			{
				int _user_choose_2;
				std::cout << "1)�������� ���� \n 2)�������� ����� \n 3)�������� ���";
				std::cin >> _user_choose_2;
				int for_add_int;
				switch (_user_choose_2)
				{
				case 1:
					std::cout << "������� ����:";
					std::cin >> for_add_int;
					_film_lib.set_day(for_add_int);
					break;
				case 2:
					std::cout << "������� �����:";
					std::cin >> for_add_int;
					_film_lib.set_mount(for_add_int);
					break;
				case 3:
					std::cout << "������� ���:";
					std::cin >> for_add_int;
					_film_lib.set_year(for_add_int);
					break;
				}
			}
			case 6:
			{
				int for_add_int;
				std::cout << "������� ����� ������:";
				std::cin >> for_add_int;
				_film_lib.set_film_gross(for_add_int);
			}
			break;
			break;

			}


		}
		break;
	}
}


