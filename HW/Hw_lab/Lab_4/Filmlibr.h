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
4) выдать все фильмы заданного режиссера, - ,
5) выдать все фильмы, вышедшие в - ,
прокат в выбранном году, 
6) выдать заданное число фильмов с наибольшими сборами, -  ,
7) выдать
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

	void set_title(std::string _title) { title = _title; };
	void set_director(std::string _director) { director = _director; };
	void set_screenwriter(std::string _screenwriter) { screenwriter = _screenwriter; };
	void set_composer(std::string _composer) { composer = _composer; };


};

class Film_library : public Film_int, public Film_str // как заполнять массив фильмов? - Film
{
private:
	Film_str lib_str;
	Film_int lib_int;
public:
	//friend void Add_film(); // 1 добавить фильм
	friend void Film_redactor(Film_library found_film, int _user_choose); // 2 изменить данные фильма выбранного по названию
	friend void title_year_search(Film_library film_mass[], std::string _title, int _year); // 3 найти фильм по - названию и году
	friend void screenwriter_year_search(Film_library film_mass[], std::string _screenwriter); // 4 выдать все фильмы заданного режиссера
	friend void year_search(Film_library film_mass[], int _num, int _year); // 5 выдать все фильмы, вышедшие в прокат в выбранном году
	friend void film_gross_search(Film_library film_mass[], int num); // 6 выдать заданное число фильмов с наибольшими сборами
	friend void year_maxn_gross_search(Film_library film_mass[], int num, int _year); // 7 выдать заданное число фильмов с наибольшими сборами в выбранном году
	friend int get_films_count(); // 8 узнать текущее число фильмов
	friend void delete_film(std::string _title); // 9 удалить фильм по названию

	// перегрузка операторов ввода и вывода - 10 сохранить фильмотеку в файл и считать фильмотеку из файла
	friend std::ostream& operator<<(std::ostream& out, const Film_library& _str);
	friend std::istream& operator>>(std::istream& in, Film_library& _str);
};

/*
class Film_library : public Film, public Film_int, public Film_str // прочекать нужен ли virtual
{
protected:
	Film* Lib = new Film;
public:
	//friend void Add_film(); // 1 добавить фильм
	friend void Film_redactor(Film_library found_film, int _user_choose); // 2 изменить данные фильма выбранного по названию
	friend void title_year_search(Film_library film_mass[], std::string _title, int _year); // 3 найти фильм по - названию и году
	friend void screenwriter_year_search(Film_library film_mass[], std::string _screenwriter); // 4 выдать все фильмы заданного режиссера
	friend void year_search(Film_library film_mass[], int _num, int _year); // 5 выдать все фильмы, вышедшие в прокат в выбранном году
	friend void film_gross_search(Film_library film_mass[], int num); // 6 выдать заданное число фильмов с наибольшими сборами
	friend void year_maxn_gross_search(Film_library film_mass[], int num, int _year); // 7 выдать заданное число фильмов с наибольшими сборами в выбранном году
	friend int get_films_count(); // 8 узнать текущее число фильмов
	friend void delete_film(std::string _title); // 9 удалить фильм по названию

	// перегрузка операторов ввода и вывода - 10 сохранить фильмотеку в файл и считать фильмотеку из файла
	friend std::ostream& operator<<(std::ostream& out, const Film_library& _str);
	friend std::istream& operator>>(std::istream& in, Film_library& _str);

}
*/
//class menu{...}; 
/*
10) сохранить фильмотеку в файл и считать фильмотеку из файла. - функция с перегрузкой ввода и вывода
.1) добавить фильм,  - 
.2) изменить данные фильма выбранного по названию,  - 
.3) найти фильм по - 
названию и году,  
.4) выдать все фильмы заданного режиссера, - ,
.5) выдать все фильмы, вышедшие в - ,
прокат в выбранном году, 
.6) выдать заданное число фильмов с наибольшими сборами, -  ,
.7) выдать
заданное число фильмов с наибольшими сборами в выбранном году, - 
.8) узнать текущее число - ,
фильмов, 
.9) удалить фильм по названию, - ,
Программа должна иметь простое меню для выбора необходимых операций
10) сохранить фильмотеку в файл и считать фильмотеку из файла. - функция с перегрузкой ввода и вывода
*/