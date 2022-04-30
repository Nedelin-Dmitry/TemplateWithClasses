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

	
};

