#pragma once

/*6. Фильмотека
Разработать класс FilmLibrary.
Класс должен хранить информацию о фильмах.Каждый фильм описывается следующими
данными :
class Film_str
название - title
режиссер - director (структура людей?)
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

/*
 Пофиксить посредственность кода:
 1)Переписать перегрузку[]
 2)Вектор фильмов - для того чтобы было легче делитать? + работать в целом
 3)Выяснить в чём проблема деструктора
 4)Переписать print
 5)Сделать повсеместные проверки на ввод
 6)Ввод и вывод информации по одинаковому формату( иногда ввод с endl иногда после ":")
*/
#pragma once

#define LIB_SIZE 10
#define NUM_IN_ASKII 48

#include <cassert> // для assert();
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
	// конструкторы
	Film();

	//сеттеры
	void set_day(int _day) { Film_date.day = _day; };
	void set_mount(int _mount) { Film_date.mount = _mount; };
	void set_year(int _year) { Film_date.year = _year; };
	void set_film_gross(int _film_gross) { film_gross = _film_gross; };
	void set_title(std::string _title) { title = _title; };
	void set_director(std::string _director) { director = _director; };
	void set_screenwriter(std::string _screenwriter) { screenwriter = _screenwriter; };
	void set_composer(std::string _composer) { composer = _composer; };


	//геттеры
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
	//конструкторы
	Film_library();
	Film_library(int _lib_size);
	~Film_library(); //- выяснить в чём проблемма деструктора

	int get_lib_size() { return lib_size; };

	friend void Hoare_Sort(Film* Film_lib, int left, int right); // сортировка Хоара для 6 & 7 пунктов

	//функции
	friend void Add_film(Film_library _Film_lib); // 1 добавить фильм
	friend void Film_redactor(Film_library _Film_lib, string _title, int _user_choose); // 2 изменить данные фильма выбранного по названию
	friend Film_library title_year_search(Film_library _Film_lib, string _title, int _year); // 3 найти фильм по - названию и году - string & int
	friend Film_library screenwriter_year_search(Film_library _Film_lib, string _director); // 4 выдать все фильмы заданного режиссера (не на консоль) - string
	friend Film_library year_search(Film_library _Film_lib, int _year); // 5 выдать все фильмы, вышедшие в прокат в выбранном году (не на консоль) - int
	friend Film_library film_gross_search(Film_library _Film_lib, int num, int _film_gross); // 6 выдать заданное число фильмов с наибольшими сборами (не на консоль) - int int
	friend Film_library year_maxn_gross_search(Film_library _Film_lib, int num, int _film_gross, int _year); // 7 выдать заданное число фильмов с наибольшими сборами в выбранном году (не на консоль) - int int int
	friend int get_films_count(Film_library _Film_lib); // 8 узнать текущее число фильмов
	friend void delete_film(Film_library _Film_lib, string _title); // 9 удалить фильм по названию


	//функция поиска
	//2 параметра - string & int -  3 найти фильм по - названию и году
	friend Film_library search(Film_library _Film_lib, string _title, int _year);

	// 1 параметр string - 4 выдать все фильмы заданного режиссера (не на консоль) - string
	friend Film_library search(Film_library _Film_lib, string _director);

	// 1 параметр Int - 5 выдать все фильмы, вышедшие в прокат в выбранном году (не на консоль) - int
	friend Film_library search(Film_library _Film_lib, int _year);

	// 2 параметрА Int 6 выдать заданное число фильмов с наибольшими сборами (не на консоль) - int int
	friend Film_library search(Film_library _Film_lib, int num, int _film_gross);

	// 3 параметрА Int - 7 выдать заданное число фильмов с наибольшими сборами в выбранном году (не на консоль) - int int int
	friend Film_library search(Film_library _Film_lib, int num, int _film_gross, int _year); 

	Film& operator[](const int index);
	const Film& operator[](const int index) const;

	// Функции сохранения и загрузки библиотеки из файла - 10 сохранить фильмотеку в файл и считать фильмотеку из файла 
	friend void Lib_save (const Film_library& _Film_lib);
	friend void Lib_load(Film_library& _str);

	friend Film Line_to_Film(string _str); // недоделанна
	
	friend void Write_lib(Film_library _Film_lib);
};
