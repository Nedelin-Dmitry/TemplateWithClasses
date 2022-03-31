/*6. Фильмотека
Разработать класс FilmLibrary.
Класс должен хранить информацию о фильмах.Каждый фильм описывается следующими
данными : название, режиссер, сценарист, композитор, дата выхода в прокат(день, месяц, год),
сборы(в рублях).Фильмы хранятся упорядоченно по названию и годам.Данные вводятся на
русском языке.
Класс должен содержать необходимые служебные методы(конструкторы, деструктор, …)..
Класс должен предоставлять следующие операции :
10) сохранить фильмотеку в файл и считать фильмотеку из файла. - функция с перегрузкой ввода и вывода
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
*/