#pragma once

/*6. Фильмотека
Разработать класс FilmLibrary.
Класс должен хранить информацию о фильмах.Каждый фильм описывается следующими
данными :
class Film_str
название - title
режиссер - director
сценарист - screenwriter
композитор - composer
сlass Film_int
дата выхода в прокат(день, месяц, год) - date, mount, year
сборы(в рублях)  - film_gross
Фильмы хранятся упорядоченно по названию и годам.Данные вводятся на
русском языке.
Класс должен содержать необходимые служебные методы(конструкторы, деструктор, …)..
Класс должен предоставлять следующие операции :
1) добавить фильм,  -
2) изменить данные фильма выбранного по названию,  -
3) найти фильм по -
названию и году,
4)(не на консоль) выдать все фильмы заданного режиссера , - ,
5)(не на консоль) выдать все фильмы, вышедшие в - ,
прокат в выбранном году,
6)(не на консоль) выдать заданное число фильмов с наибольшими сборами, -  ,
7)(не на консоль) выдать
заданное число фильмов с наибольшими сборами в выбранном году, -
8) узнать текущее число - ,
фильмов,
9) удалить фильм по названию, - ,
Программа должна иметь простое меню для выбора необходимых операций.
10) сохранить фильмотеку в файл и считать фильмотеку из файла. - функция с перегрузкой ввода и вывода
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
	//деструктор?

	//геттеры

	//сеттеры
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

	//деструктор?

	//геттеры
	string get_title() { return title; };

	//сеттеры
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
	// конструктор  & деструктор
	//Film_library();
	~Film_library();

	//геттеры
	int get_size_lib(Film_library _Film_lib);

	//функции
	friend void Add_film(Film_library _Film_lib); // 1 добавить фильм
	friend void Film_redactor(Film_library found_film, int _user_choose); // 2 изменить данные фильма выбранного по названию
	friend Film_library title_year_search(Film_library film_mass[], std::string _title, int _year); // 3 найти фильм по - названию и году
	friend Film_library screenwriter_year_search(Film_library film_mass[], std::string _screenwriter); // 4 выдать все фильмы заданного режиссера (не на консоль)
	friend Film_library year_search(Film_library film_mass[], int _num, int _year); // 5 выдать все фильмы, вышедшие в прокат в выбранном году (не на консоль)
	friend Film_library film_gross_search(Film_library film_mass[], int num); // 6 выдать заданное число фильмов с наибольшими сборами (не на консоль)
	friend Film_library year_maxn_gross_search(Film_library film_mass[], int num, int _year); // 7 выдать заданное число фильмов с наибольшими сборами в выбранном году (не на консоль)
	friend int get_films_count(); // 8 узнать текущее число фильмов
	friend void delete_film(std::string _title); // 9 удалить фильм по названию

	//перегрузка операторов
	friend Film_library operator -=(Film_library one, Film two);
	friend Film_library operator +=(Film_library one, Film two);

	// перегрузка операторов ввода и вывода - 10 сохранить фильмотеку в файл и считать фильмотеку из файла
	friend std::ostream& operator<<(std::ostream& out, const Film_library& _str);
	friend std::istream& operator>>(std::istream& in, Film_library& _str);


};


// 2 параметра поиска

Film_library search( /*const?*/ Film_library film_mass, std::string _title, int _year) // 3 найти фильм по - названию и году; - вероятнее всего не на консоль
{
	Film_library search_result_lib;
	int _size_lub = film_mass.get_size_lib(film_mass);
	if (_size_lub == 0)
	{
		cout << "Библиотека пуста" << endl;
		return  search_result_lib;
	}
	for (int i = 0; i < _size_lub; i++)
	{
		//film_mass[i] =
	}
	return search_result_lib;
};



// 1 параметр поиска

// 4 выдать все фильмы заданного режиссера (не на консоль)

Film_library search(Film_library film_mass, string _str_) 
{
	Film_library search_result_lib;
	int _size_lub = film_mass.get_size_lib(film_mass);
	string _title_lib;
	int j = 0;
	if (_size_lub == 0)
	{
		cout << "Библиотека пуста" << endl;
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

// 5 выдать все фильмы, вышедшие в прокат в выбранном году (не на консоль)
// 6 выдать заданное число фильмов с наибольшими сборами (не на консоль)
// 7 выдать заданное число фильмов с наибольшими сборами в выбранном году (не на консоль)
Film_library search(Film_library film_mass, int _int_, int option_year)
{
	Film_library search_result_lib;

	return search_result_lib;
};


































/*
* Как бы я реализовал поиск
У меня перегрузка одной функции по параметрам принцип работы уебанский
1)получает параметр по которому ищет + саму библиотеку
2)Создаёт Film_library 1 в который будет кидать результаты
(скорее всего надо добавить функцию которая будет копировать нужные фильмы)
3)По for ищет равен ли параметр который передаётся тому что в фильме
(если их два то после проверки первого проверяет второй иначе break;)
4)Добавляет в 1 данные нужного фильма по концу цикла возвращет библиотеку
	

Разработать класс FilmLibrary.
Класс должен хранить информацию о фильмах.Каждый фильм описывается следующими
данными :
class Film_str
название - title
режиссер - director
сценарист - screenwriter
композитор - composer
сlass Film_int
дата выхода в прокат(день, месяц, год) - date, mount, year
сборы(в рублях)  - film_gross
Фильмы хранятся упорядоченно по названию и годам.Данные вводятся на
русском языке.
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
	// конструктор  & деструктор
	//Film_library(); - я не совсем разобрался с наследованием и хз нужен ли тут конструктор
	~Film_library();

3) найти фильм по -
названию и году,
4)(не на консоль) выдать все фильмы заданного режиссера , - ,
5)(не на консоль) выдать все фильмы, вышедшие в - ,
прокат в выбранном году,
6)(не на консоль) выдать заданное число фильмов с наибольшими сборами, -  ,
7)(не на консоль) выдать
заданное число фильмов с наибольшими сборами в выбранном году, -
*/