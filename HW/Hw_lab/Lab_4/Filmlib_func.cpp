#include "Filmlibr.h"

/*
class Film_str
название - title
режиссер - director
сценарист - screenwriter
композитор - composer
сlass Film_int
дата выхода в прокат(день, мес€ц, год) - date, mount, year
сборы(в рубл€х)  - film_gross
*/


Film_int::Film_int()
{
	day = 0;
	mount = 0;
	year = 0;
	film_gross = 0;
}

Film_int::Film_int(int _day, int _mount, int _year, int _film_gross)
{
	day = _day;
	mount = _mount;
	year = _year;
	film_gross = _film_gross;
}

Film_str::Film_str()
{
	title = "-";
	director = "-";
	screenwriter = "-";
	composer = "-";
}

Film_str::Film_str(std::string _title, std::string _director, std::string _screenwriter, std::string _composer)
{
	title = _title;
	director = _director;
	screenwriter = _screenwriter;
	composer = _composer;
}

/*
void Film_str::set_title(std::string _title) { title = _title; };
void Film_str::set_director(std::string _director) { director = _director; };
void Film_str::set_screenwriter(std::string _screenwriter) { screenwriter = _screenwriter; };
void Film_str::set_composer(std::string _composer) { composer = _composer; };
*/



void Add_film() // 1
{
	Film_library A; // ??
	int int_information = 0;
	std::string str_information;
	std::cout << "Input Fulm Title:" << std::endl;
	std::cin >> str_information;
	A.set_title(str_information);
	/*
	std::cout << "Input Fulm Director:" << std::endl;
	std::cin >> str_information;
	set_director(str_information);
	std::cout << "Input Fulm Screenwriter:" << std::endl;
	std::cin >> str_information;
	set_screenwriter(str_information);
	std::cout << "Input Fulm Composer:" << std::endl;
	std::cin >> str_information;
	set_composer(str_information);

	std::cout << "Input Fulm Year:" << std::endl;
	std::cin >> int_information;
	set_year(int int_information);
	std::cout << "Input Fulm Mount:" << std::endl;
	std::cin >> int_information;
	set_mount(int int_information);
	std::cout << "Input Fulm Day:" << std::endl;
	std::cin >> int_information;
	set_day(int int_information);
	std::cout << "Input Fulm Gross:" << std::endl;
	std::cin >> int_information;
	set_film_gross(int int_information);
	*/

};

void Film_redactor(Film_library found_film, int _user_choose) // 2
{
	std::string _for_str;
	int _for_int;
	switch(_user_choose)
	{
		case 1: // –ежисЄр
			std::cin >> _for_str;
			found_film.set_director(_for_str);
			break;
		case 2: // —ценарист
			std::cin >> _for_str;
			found_film.set_screenwriter(_for_str);
			break;
		case 3: //  омпозитор
			std::cin >> _for_str;
			found_film.set_composer(_for_str);
			break;
		case 4: // ƒата
			std::cout << "¬ведите день" << std::endl;
			std::cin >> _for_int;
			found_film.set_day(_for_int);
			std::cout << "¬ведите мес€ц" << std::endl;
			std::cin >> _for_int;
			found_film.set_mount(_for_int);
			std::cout << "¬ведите год" << std::endl;
			std::cin >> _for_int;
			found_film.set_year(_for_int);
			break;
		case 5: // сборы
			std::cin >> _for_int;
			found_film.set_film_gross(_for_int);
			break;
	}
}

void title_year_search(Film_library film_mass[], std::string _title, int _year) // 3
{
	int find_flag = 0;
	int position = -1;
	for (int i = 0; i < 10; i++)
	{
		if (film_mass[i].title == _title)
		{
			find_flag += 1;
		}
		if (film_mass[i].year == _year)
		{
			find_flag += 1;
		}
		if (find_flag == 2)
		{
			position = i;
			break;
		}
		else if (find_flag != 0)
		{
			find_flag = 0;
		}
	}
	if (position < 10 && position >= 0) // ограниченный размер библиотеки - сделать константой?
	{
		//write() - вывод данных фильма; или перегрузка вывода
	}
	if (position == -1)
	{
		std::cout << "Not found";
	}

}

void screenwriter_year_search(Film_library film_mass[], std::string _screenwriter) //4
{
	int find_flag = 0;
	int* position = new int[];
	for (int j = 0; j < 10; j++) { position[j] = -1; };
	int j = 0; // кол-во заполненых ?
	for (int i = 0; i < 10; i++)
	{
		if (film_mass[i].title == _title)
		{
			find_flag += 1;
		}
		if (film_mass[i].year == _year)
		{
			find_flag += 1;
		}
		if (find_flag == 2)
		{
			position[j] = i;
			j += 1;
			break;
		}
		else if (find_flag != 0)
		{
			find_flag = 0;
		}
	}
	if (position < 10 && position >= 0) // ограниченный размер библиотеки - сделать константой?
	{
		for (int k = 0; k < 10; k++)
		{
			//if (position[k] == -1) { break; };
			//else { write(); };
		}
		//write() - вывод данных фильма; или перегрузка вывода
	}
	if (j == -1)
	{
		std::cout << "Not found";
	}
}

void year_search(Film_library film_mass[], int _num, int _year) // 5
{


}

void film_gross_search(Film_library film_mass[], int num) // 6
{


}

void year_maxn_gross_search(Film_library film_mass[], int num, int _year) // 7
{


}

int get_films_count() // 8
{

	return 0;
}

void delete_film(std::string _title) // 9
{

}