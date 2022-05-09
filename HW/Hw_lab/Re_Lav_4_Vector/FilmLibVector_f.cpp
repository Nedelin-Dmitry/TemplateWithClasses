#include"Film_lib_vecrtor.h"


using namespace std;


/*
class Film_str
название - title
режиссер - director
сценарист - screenwriter
композитор - composer
сlass Film_int
дата выхода в прокат(день, месяц, год) - date, mount, year
сборы(в рублях)  - film_gross

векторы
https://bestprogrammer.ru/programmirovanie-i-razrabotka/kak-ispolzovat-vektor-vecto-v-c

Разобрать для реализации сортировки черезе векторы
int partition(std::vector<int>& vector, int lo, int hi)
{
  int i = lo;
  int j = hi + 1;
  while (true)
  {
	while (vector[++i] < vector[lo])
	{
	  if (i == hi) break;
	}
	while (vector[--j] > vector[lo])
	{
	  if (j == lo)
	  {
		break;
	  }
	}
	if (i >= j)
	{
	  break;
	}
	std::swap(vector[i], vector[j]);
  }
  std::swap(vector[lo], vector[j]);
  return j;
}

void quickSort(std::vector<int>& vector, int lo, int hi)
{
  if (hi <= lo) return;

  int j = partition(vector, lo, hi);

  quickSort(vector, lo, j - 1);
  quickSort(vector, j + 1, hi);
}
*/

// class Film

Film::Film()
{
	title = "";
	director = "";
	screenwriter = "";
	composer = "";
	Film_date.day = 0;
	Film_date.mount = 0;
	Film_date.year = 0;
	film_gross = 0;
}

Film Film::operator=(const Film& film_1)
{
	if (this != &film_1)
	{
		title = film_1.title;
		director = film_1.director;
		screenwriter = film_1.screenwriter;
		composer = film_1.composer;
		Film_date.day = film_1.Film_date.day;
		Film_date.mount = film_1.Film_date.mount;
		Film_date.year = film_1.Film_date.year;
		film_gross = film_1.film_gross;
	}
	return *this;
}

//class Fulm_library

Film_library::Film_library()
{
	num_of_films = 0;
	vector <Film> Film_lib(10);
}

Film_library::Film_library(const Film_library& copy)
{
	num_of_films = copy.num_of_films;
	Film_lib.resize(num_of_films);
	for (int i = 0; i < num_of_films; i++)
	{
		Film_lib[i] = copy.Film_lib[i];
	}
}

Film_library::~Film_library()
{
	Film_lib.clear(); // удаление всех элементов вектора
}

int Partirion(Film_library& _Film_lib, int left, int right) // библиотека - начало вектора - конец вектора
{

	int i = left;
	int j = right + 1;
	while (true)
	{
		while (_Film_lib.Film_lib[++i].get_film_gross() < _Film_lib.Film_lib[left].get_film_gross())
		{
			if (i == right) break;
		}
		while (_Film_lib.Film_lib[--j].get_film_gross() > _Film_lib.Film_lib[left].get_film_gross())
		{
			if (j == left)
			{
				break;
			}
		}
		if (i >= j)
		{
			break;
		}
		swap(_Film_lib.Film_lib[i], _Film_lib.Film_lib[j]);
	}
	swap(_Film_lib.Film_lib[left], _Film_lib.Film_lib[j]);
	return j;

}

//void quickSort(std::vector<int>&vector, int lo, int hi)
void Hoare_Sort(Film_library & _Film_lib, int left, int right)
{
		if (right <= left) return;

		int j = Partirion(_Film_lib, left, right);

		Hoare_Sort(_Film_lib, left, j - 1);
		Hoare_Sort(_Film_lib, j + 1, right);
}

//2 параметра - string & int -  3 найти фильм по - названию и году
Film_library search(Film_library& _Film_lib, string _title, int _year)
{
	Film_library for_return = Film_library();
	for (int i = 0; i < _Film_lib.num_of_films; i++)
	{
		if (_title == _Film_lib.Film_lib[i].get_title() && _year == _Film_lib.Film_lib[i].get_year())
		{
			for_return.Film_lib[0] = _Film_lib.Film_lib[i];
			cout << "Film found" << endl;
			system("pause");
			return for_return;
		}
	}
	cout << "The Film was not found" << endl;
	return for_return;
}

 // 1 параметр string - 4 выдать все фильмы заданного режиссера (не на консоль) - string
Film_library search(Film_library& _Film_lib, string _director)
{
	Film_library for_return = Film_library();
	int _director_films = 0;
	for (int i = 0; i < _Film_lib.num_of_films; i++)
	{
		if (_director == _Film_lib.Film_lib[i].get_director()) { _director_films += 1; };
	}
	if (_director_films == 0)
	{
		cout << "No films of this director were found" << endl;
		return for_return;
	}
	else
	{
		for_return.Film_lib.resize(_director_films + 1);
		for_return.num_of_films = for_return.Film_lib.size();
		for (int i = 0; i < for_return.num_of_films; i++)
		{
			if (_director == _Film_lib.Film_lib[i].get_director())
			{
				for_return.Film_lib[i] = _Film_lib.Film_lib[i];
			}
		}
		return for_return;
	}
}

// 1 параметр Int - 5 выдать все фильмы, вышедшие в прокат в выбранном году (не на консоль) - int
Film_library search(Film_library& _Film_lib, int _year)
{
	Film_library for_return = Film_library();
	int _year_films = 0;
	for (int i = 0; i < _Film_lib.num_of_films; i++)
	{
		if (_year == _Film_lib.Film_lib[i].get_year()) { _year_films += 1; };
	}
	if (_year_films == 0)
	{
		cout << "No films of this year were found" << endl;
		return for_return;
	}
	else
	{
		for_return.Film_lib.resize(_year_films + 1);
		for_return.num_of_films = for_return.Film_lib.size();
		for (int i = 0; i < for_return.num_of_films; i++)
		{
			if (_year == _Film_lib.Film_lib[i].get_year())
			{
				for_return.Film_lib[i] = _Film_lib.Film_lib[i];
			}
		}
		return for_return;
	}
}


// 2 параметрА Int 6 выдать заданное число фильмов с наибольшими сборами (не на консоль) - int int
Film_library search(Film_library& _Film_lib, int num, int _film_gross)
{
	Film_library sorted_lib = Film_library();
	Film_library for_return = Film_library();
	sorted_lib.Film_lib.resize(_Film_lib.num_of_films);
	for_return.Film_lib.resize(num);
	for (int i = 0; i < _Film_lib.num_of_films; i++)
	{
		sorted_lib.Film_lib[i] = _Film_lib.Film_lib[i];
	}
	Hoare_Sort(sorted_lib, 0, sorted_lib.num_of_films);
	int check_num = 0;
	for (int i = sorted_lib.num_of_films - 1; i >= 0; i--)
	{
		if (check_num == num) { break; };
		for_return.Film_lib[i] = sorted_lib.Film_lib[i];
	}
	return for_return;
}

// 3 параметрА Int - 7 выдать заданное число фильмов с наибольшими сборами в выбранном году (не на консоль) - int int int
Film_library search(Film_library& _Film_lib, int num, int _film_gross, int _year) // неэффективно 
{
	Film_library sorted_lib = Film_library();
	Film_library for_return = Film_library();
	int year_count = 0;
	for (int i = 0; i < _Film_lib.num_of_films; i++)
	{
		if (_year == _Film_lib.Film_lib[i].get_year())
		{
			sorted_lib.Film_lib[i] = _Film_lib.Film_lib[i];
			year_count += 1; 
		};
	}
	sorted_lib.Film_lib.resize(year_count);
	for_return.Film_lib.resize(num);
	//for (int i = 0; i < _Film_lib.num_of_films; i++)
	//{
	//	if (_year == _Film_lib.Film_lib[i].get_year())
	//	{
	//		sorted_lib.Film_lib[i] = _Film_lib.Film_lib[i];
	//	}
	//}
	Hoare_Sort(sorted_lib, 0, sorted_lib.num_of_films);
	int check_num = 0;
	for (int i = sorted_lib.num_of_films - 1; i >= 0; i--)
	{
		if (check_num == num) { break; };
		for_return.Film_lib[i] = sorted_lib.Film_lib[i];
	}
	return for_return;
}

void Add_film(Film_library& _Film_lib)
{
	int vector_size = _Film_lib.Film_lib.size(); // размер вектора
	if (_Film_lib.num_of_films == vector_size) { _Film_lib.Film_lib.resize(_Film_lib.num_of_films + 5); } // если вектор заканчивается добавляем 5 к размеру вектора
	string for_add_str;
	int for_add_int;
	int position_write = _Film_lib.num_of_films;
	std::cout << "Введите название фильма:" << endl;
	std::cin >> for_add_str;
	_Film_lib.Film_lib[position_write].set_title(for_add_str);
	std::cout << "Введите Режисёра фильма:" << endl;
	std::cin >> for_add_str;
	_Film_lib.Film_lib[position_write].set_director(for_add_str);
	std::cout << "Введите Сценариста фильма:" << endl;
	std::cin >> for_add_str;
	_Film_lib.Film_lib[position_write].set_screenwriter(for_add_str);
	std::cout << "Введите Композитора фильма:" << endl;
	std::cin >> for_add_str;
	_Film_lib.Film_lib[position_write].set_composer(for_add_str);
	std::cout << "Введите день выхода фильма:" << endl;
	std::cin >> for_add_int;
	_Film_lib.Film_lib[position_write].set_day(for_add_int);
	std::cout << "Введите месяц выхода фильма:" << endl;
	std::cin >> for_add_int;
	_Film_lib.Film_lib[position_write].set_mount(for_add_int);
	std::cout << "Введите год выхода фильма:" << endl;
	std::cin >> for_add_int;
	_Film_lib.Film_lib[position_write].set_year(for_add_int);
	std::cout << "Введите сборы фильма:" << endl;
	std::cin >> for_add_int;
	_Film_lib.Film_lib[position_write].set_film_gross(for_add_int);
	_Film_lib.num_of_films += 1;
}


void Film_redactor(Film_library& _Film_lib, string _title_, int _user_choose)
{

	for (int i = 0; i < _Film_lib.num_of_films; i++)
	{
		if (_title_ == _Film_lib.Film_lib[i].get_title())
		{
			switch (_user_choose)
			{
			case _title:
			{
				string for_add_str;
				std::cout << "Введите назнание фильма:" << endl;
				std::cin >> for_add_str;
				_Film_lib.Film_lib[i].set_title(for_add_str);
			}
			break;
			case _director:
			{
				string for_add_str;
				std::cout << "Введите Режисёра фильма:" << endl;
				std::cin >> for_add_str;
				_Film_lib.Film_lib[i].set_director(for_add_str);
			}
			break;
			case _screenwriter:
			{
				string for_add_str;
				std::cout << "Введите Сценариста фильма:" << endl;
				std::cin >> for_add_str;
				_Film_lib.Film_lib[i].set_screenwriter(for_add_str);
			}
			break;
			case _composer:
			{
				string for_add_str;
				std::cout << "Введите Композитора фильма:" << endl;
				std::cin >> for_add_str;
				_Film_lib.Film_lib[i].set_composer(for_add_str);
			}
			break;
			case _day:
			{
				int for_add_int;
				std::cout << "Введите день фильма:" << endl;
				std::cin >> for_add_int;
				_Film_lib.Film_lib[i].set_day(for_add_int);
			}
			break;
			case _mount:
			{
				int for_add_int;
				std::cout << "Введите месяц фильма:" << endl;
				std::cin >> for_add_int;
				_Film_lib.Film_lib[i].set_mount(for_add_int);
			}
			break;
			case _year:
			{
				int for_add_int;
				std::cout << "Введите год фильма:" << endl;
				std::cin >> for_add_int;
				_Film_lib.Film_lib[i].set_year(for_add_int);
			}
			break;
			case _gross:
			{
				int for_add_int;
				std::cout << "Введите сборы фильма:" << endl;
				std::cin >> for_add_int;
				_Film_lib.Film_lib[i].set_film_gross(for_add_int);
			}
			break;
			}
		}
		break;
	}
}

Film_library title_year_search(Film_library& _Film_lib, string _title, int _year)
{
	Film_library for_return = Film_library();
	for_return.Film_lib.resize(1);
	for (int i = 0; i < _Film_lib.num_of_films; i++)
	{
		if (_title == _Film_lib.Film_lib[i].get_title() && _year == _Film_lib.Film_lib[i].get_year())
		{
			for_return.Film_lib[0] = _Film_lib.Film_lib[i];
			for_return.num_of_films = 1;
			cout << "Film found" << endl;
			return for_return;
		}
	}
	cout << "The Film was not found" << endl;
	return for_return;
}

Film_library screenwriter_year_search(Film_library& _Film_lib, string _director)
{
	Film_library for_return = Film_library();
	int _director_films = 0;
	for (int i = 0; i < _Film_lib.num_of_films; i++)
	{
		if (_director == _Film_lib.Film_lib[i].get_director()) { _director_films += 1; };
	}
	if (_director_films == 0)
	{
		cout << "No films of this director were found" << endl;
		for_return.Film_lib.resize(1);
		for_return.num_of_films = 0;
		return for_return;
	}
	else
	{
		for_return.Film_lib.resize(_director_films + 1);
		for_return.num_of_films = _director_films;
		for (int i = 0; i < for_return.num_of_films; i++)
		{
			if (_director == _Film_lib.Film_lib[i].get_director())
			{
				for_return.Film_lib[i] = _Film_lib.Film_lib[i];
			}
		}
		return for_return;
	}

}

Film_library year_search(Film_library& _Film_lib, int _year)
{
	Film_library for_return = Film_library();
	int _year_films = 0;
	for (int i = 0; i < _Film_lib.num_of_films; i++)
	{
		if (_year == _Film_lib.Film_lib[i].get_year()) { _year_films += 1; };
	}
	if (_year_films == 0)
	{
		cout << "No films of this director were found" << endl;
		for_return.Film_lib.resize(1);
		for_return.num_of_films = 0;
		return for_return;
	}
	else
	{
		for_return.Film_lib.resize(_year_films + 1);
		for_return.num_of_films = _year_films;
		for (int i = 0; i < for_return.num_of_films; i++)
		{
			if (_year == _Film_lib.Film_lib[i].get_year())
			{
				for_return.Film_lib[i] = _Film_lib.Film_lib[i];
			}
		}
		return for_return;
	}
}

Film_library film_gross_search(Film_library& _Film_lib, int num, int _film_gross)
{
	Film_library sorted_lib = Film_library(_Film_lib);
	Film_library for_return = Film_library();
	for_return.Film_lib.resize(num);
	for_return.num_of_films = num;
	Hoare_Sort(sorted_lib, 0, sorted_lib.num_of_films);
	return sorted_lib; // руина в сортировке
	/*int check_num = 0;
	for (int i = sorted_lib.num_of_films - 1; i > 0; i--)
	{
		if (check_num == num) { break; };
		for_return.Film_lib[i] = sorted_lib.Film_lib[i];
		check_num += 1;
	}
	return for_return;*/
}

Film_library year_maxn_gross_search(Film_library& _Film_lib, int num, int _film_gross, int _year)
{
	Film_library sorted_lib = Film_library();
	Film_library for_return = Film_library();
	int year_count = 0;
	for (int i = 0; i < _Film_lib.num_of_films; i++)
	{
		if (_year == _Film_lib.Film_lib[i].get_year())
		{
			sorted_lib.Film_lib[i] = _Film_lib.Film_lib[i];
			year_count += 1;
		};
	}
	sorted_lib.Film_lib.resize(year_count);
	for_return.Film_lib.resize(num);
	//for (int i = 0; i < _Film_lib.num_of_films; i++)
	//{
	//	if (_year == _Film_lib.Film_lib[i].get_year())
	//	{
	//		sorted_lib.Film_lib[i] = _Film_lib.Film_lib[i];
	//	}
	//}
	Hoare_Sort(sorted_lib, 0, sorted_lib.num_of_films);
	int check_num = 0;
	for (int i = sorted_lib.num_of_films - 1; i >= 0; i--)
	{
		if (check_num == num) { break; };
		for_return.Film_lib[i] = sorted_lib.Film_lib[i];
	}
	return for_return;
}



void get_films_count(Film_library& _Film_lib)
{
	cout << "Film in lib: " << _Film_lib.num_of_films << endl;
	system("pause");
}

void delete_film(Film_library& _Film_lib, string _title)
{
	int _iterator = -1;
	for (int i = 0; i < _Film_lib.num_of_films; i++)
	{
		if (_title == _Film_lib.Film_lib[i].get_title())
		{
			_iterator = i;
			break;
		}
	}
	/*if (_iterator == -1)
	{
		cout << "A film with this name was not found" << endl;
	}
	else
	{
		_Film_lib.Film_lib.erase(_iterator);
	}*/
}

void Lib_save(const Film_library& _Film_lib)
{
	ofstream out;
	out.open("Saved_film_lib.txt");
	if (out.is_open())
	{
		Film for_output;
		string _title_;
		string _director_;
		string _screenwriter;
		string _composer_;
		int _day_;
		int _mount_;
		int _year_;
		int _gross_;
		for (int i = 0; i < _Film_lib.num_of_films ; i++)
		{
			for_output = _Film_lib.Film_lib[i];
			_title_ = for_output.get_title();
			_director_ = for_output.get_director();
			_screenwriter = for_output.get_screenwriter();
			_composer_ = for_output.get_composer();
			_day_ = for_output.get_day();
			_mount_ = for_output.get_mount();
			_year_ = for_output.get_year();
			_gross_ = for_output.get_film_gross();
			// i) title | director | screenwritter | composer | day.mount.year | film_gross  - один фильм 
			out << i << ") " << _title_ << " | " << _director_ << " | "
				<< _screenwriter << " | " << _composer_ << " | "
				<< _day_ << "." << _mount_ << "." << _year_ << " | "
				<< _gross_ << endl;
		}
		cout << "Library saved" << endl;
		out.close();
		system("pause");

	}
	else { cout << "File not open" << endl; };
}

// получаем строку с getline и работаем с ней
Film Line_to_Film(string _line) // решить проблему с пробелами
{
	Film return_film = Film();
	for (int i = 3, data = 1; i < _line.size(); i++) // i - символ в строке
	{
		if (_line[i] == '|' || _line[i] == '.')
		{
			data += 1;
			if (_line[i] == '|')
			{
				i += 2;
			}
			else if (_line[i] == '.')
			{
				i += 1;
			}
		}
		switch (data)
		{
		case _title:
			if ((int)_line[i] == SPACE_IN_ASKII) {}
			else {
				return_film.set_title(return_film.get_title() + _line[i]);
			}
			break;
		case _director:
			if ((int)_line[i] == SPACE_IN_ASKII) {}
			else {
				return_film.set_director(return_film.get_director() + _line[i]);
			}
			break;
		case _screenwriter:
			if ((int)_line[i] == SPACE_IN_ASKII) {}
			else {
				return_film.set_screenwriter(return_film.get_screenwriter() + _line[i]);
			}
			break;
		case _composer:
			if ((int)_line[i] == SPACE_IN_ASKII) {}
			else {
				return_film.set_composer(return_film.get_composer() + _line[i]);
			}
			break;
		case _day:
			if ((int)_line[i] == SPACE_IN_ASKII) {}
			else {
				return_film.set_day((return_film.get_day() * 10) + ((int)_line[i] - NUM_IN_ASKII));
			}
			break;
		case _mount:
			if ((int)_line[i] == SPACE_IN_ASKII) {}
			else {
				return_film.set_mount((return_film.get_mount() * 10) + ((int)_line[i] - NUM_IN_ASKII));
			}
			break;
		case _year:
			if ((int)_line[i] == SPACE_IN_ASKII) {}
			else {
			return_film.set_year((return_film.get_year() * 10) + ((int)_line[i] - NUM_IN_ASKII));
			}
			break;
		case _gross:
			if ((int)_line[i] == SPACE_IN_ASKII) {}
			else {
			return_film.set_film_gross((return_film.get_film_gross() * 10) + ((int)_line[i] - NUM_IN_ASKII));
			}
			break;
		}


	}


	return return_film;
}

void Lib_load(Film_library& _str)
{
	Film Load_film;
	ifstream in;
	string read_line;
	in.open("Saved_film_lib.txt");
	if (in.is_open()) {
		// чистим текущую библиотеку
		_str.Film_lib.clear();
		_str.num_of_films = 0;
		// пока получаем строку
		while (getline(in, read_line)) {
			_str.Film_lib.push_back(Line_to_Film(read_line)); 
			_str.num_of_films += 1;
		}
		cout << "Lib download" << endl;
		cout << "In lib " << _str.num_of_films << " films" << endl;
	}
	else { cout << "File is not open" << endl; };
	system("pause");
}

void Write_Film(Film_library& _Film)
{
	if (_Film.Film_lib[0].get_title() == "-")
	{

	}
	else {
		cout << "Название фильма: " << _Film.Film_lib[0].get_title() << "\nРежисёр фильма: " << _Film.Film_lib[0].get_director() << "\nСценарист фильма: "
			<< _Film.Film_lib[0].get_screenwriter() << "\nКомпозитор фильма: " << _Film.Film_lib[0].get_composer() << "\nДата фильма: " << _Film.Film_lib[0].get_day() << "."
			<< _Film.Film_lib[0].get_mount() << "." << _Film.Film_lib[0].get_year() << "\nСборы фильма: " << _Film.Film_lib[0].get_film_gross() << "$" << endl;
		system("pause");
	}
}

void Write_lib(Film_library& _Film_lib)
{
	for (int i = 0; i < _Film_lib.num_of_films; i++)
	{
		cout << "Название фильма: " << _Film_lib.Film_lib[i].get_title() << "\nРежисёр фильма: " << _Film_lib.Film_lib[i].get_director() << "\nСценарист фильма: "
			<< _Film_lib.Film_lib[i].get_screenwriter() << "\nКомпозитор фильма: " << _Film_lib.Film_lib[i].get_composer() << "\nДата фильма: " << _Film_lib.Film_lib[i].get_day() << "."
			<< _Film_lib.Film_lib[i].get_mount() << "." << _Film_lib.Film_lib[i].get_year() << "\nСборы фильма: " << _Film_lib.Film_lib[i].get_film_gross() << "$" << endl;
	}
	system("pause");
}