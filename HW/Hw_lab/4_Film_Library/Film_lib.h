#pragma once
// Copyright 2022 Nedelin-Dmitry
/*6. Filmography
Develop the FilmLibrary class.
The class should store information about movies.Each film is described by the following
data:
class Film_str
title - title
director - director (structure of people?)
screenwriter - screenwriter
composer - composer

class Film_int release date(day, month, year) - date, mount, year
fees(in rubles) - film_gross
Movies are stored in order by name and year.The data is entered in
Russian.
The class must contain the necessary utility methods (constructors, destructor, ...)..
The class should provide the following operations :
1) add a movie,  -
2) change the data of the movie selected by name, -
3) find the movie by -
name and year,
4) (not on the console) output all the films of the specified director , - ,
5) (not on the console) give out all the films released in - ,
rental in the selected year,
6) (not to the console) issue a specified number of films with the highest fees, - ,
7) (not to the console) issue
a specified number of films with the highest fees in the selected year, -
8) find out the current number of - ,
films,
9) delete a movie by name, - ,
The program should have a simple menu for selecting the necessary operations.
10) save the movie library to a file and read the movie library from the file. - function with input and output overload
*/


#pragma once

#define START_LIB_SIZE 0
#define NUM_IN_ASKII 48
#define SPACE_IN_ASKII 32

#include<iostream>
#include<cstring> 
#include<string>
#include<vector>
#include<fstream>
#include <algorithm>  // sort

using namespace std;

struct Date {
    int day;
    int mount;
    int year;
};



enum menu_selection {
    Exit = 0,
    Add_film_lib = 1,
    Change_film = 2,
    Find_title_year = 3,
    Films_director = 4,
    Find_film_year = 5,
    Film_gross_num = 6,
    Film_gross_num_year = 7,
    Lib_size = 8,
    Delete_film = 9,
    Save_lib = 10,
    Download_Film = 11,
    Write_Library = 12
};

enum film_data {
    _title = 1,
    _director = 2,
    _screenwriter = 3,
    _composer = 4,
    _day = 5,
    _mount = 6,
    _year = 7,
    _gross = 8
};

class Film {
 protected:
    string title;
    string director;
    string screenwriter;
    string composer;
    Date Film_date;
    int film_gross;
  public:
    // constructors
    Film();
    // setters
    void set_day(int _day) { Film_date.day = _day; }
    void set_mount(int _mount) { Film_date.mount = _mount; }
    void set_year(int _year) { Film_date.year = _year; }
    void set_film_gross(int _film_gross) { film_gross = _film_gross; }
    void set_title(std::string _title) { title = _title; }
    void set_director(std::string _director) { director = _director; }
    void set_screenwriter(std::string _screenwriter) { screenwriter = _screenwriter; }
    void set_composer(std::string _composer) { composer = _composer; }
    // getters
    string get_title() { return title; }
    string get_director() { return director; }
    string get_screenwriter() { return screenwriter; }
    string get_composer() { return composer; }
    int get_day() { return Film_date.day; }
    int get_mount() { return Film_date.mount; }
    int get_year() { return Film_date.year; }
    int get_film_gross() { return film_gross; }
    // operator
    Film operator=(const Film& film_1);
    bool operator<(const Film& a) const { return film_gross < a.film_gross; }
    friend ostream& operator<<(ostream& out, Film& _Film);
};

class Film_library
{
 private:
    int num_of_films;
    vector <Film> Film_lib;
 public:
    // constructors
    Film_library();
    Film_library(const Film_library& copy);
    ~Film_library();
    // getter
    int get_num_of_films() { return num_of_films; }
    // functions
    // 1 добавить фильм1 add a movie
    friend void Add_film(Film_library& _Film_lib);
    // 2 change the data of the movie selected by name
    friend void Film_redactor(Film_library& _Film_lib, string _title_, int _user_choose);
    // 3 find a movie by name and year
    friend Film_library title_year_search(Film_library& _Film_lib, string _title, int _year);
    // 4 output all films of the specified director (not to the console)
    friend Film_library screenwriter_year_search(Film_library& _Film_lib, string _director); 
    // 5 give out all the films released in the selected year (not on the console)
    friend Film_library year_search(Film_library& _Film_lib, int _year); 
    // 6 output the specified number of movies with the highest fees (not to the console)
    friend Film_library film_gross_search(Film_library& _Film_lib, int num); 
    // 7 output the specified number of films with the highest fees in the selected year (not to the console)
    friend Film_library year_maxn_gross_search(Film_library& _Film_lib, int num, int _year);
    // 8 find out the current number of movies
    friend void get_films_count(Film_library& _Film_lib);
    // 9 delete a movie by name
    friend void delete_film(Film_library& _Film_lib, string _title);
    // Functions of saving and loading a library from a file -
    // - 10 save a movie library to a file and read a movie library from a file 
    friend void Lib_save(const Film_library& _Film_lib);
    friend void Lib_load(Film_library& _str);
    // 
    friend Film Line_to_Film(string _line);
    friend ostream& operator<<(ostream& out, Film_library& _Film_lib);
};