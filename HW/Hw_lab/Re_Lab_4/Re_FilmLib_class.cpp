#include"Re_FilmLib.h"
using namespace std;
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
Film_library()
{
	Film_library::Film_lib = new Film;
}
*/

/*
Film& Film::operator[](int index)
{

}
*/
Film_library::~Film_library()
{
	delete[] Film_lib;
};

int Film_library::get_size_lib(Film_library _Film_lib) { return _Film_lib.size_lib; };

/*
Film_library operator -=(Film_library one, Film two)
{

}

Film_library operator +=(Film_library one, Film two)
{
	//one[i] = two;
}
*/

void Add_film(Film_library _Film_lib)
{
	string for_add_str;
	int for_add_int;
	cout << "¬ведите название фильма:" << endl;
	cin >> for_add_str;
	_Film_lib.set_title(for_add_str);
	cout << "¬ведите –ежисЄра фильма:" << endl;
	cin >> for_add_str;
	_Film_lib.set_director(for_add_str);
	cout << "¬ведите —ценариста фильма:" << endl;
	cin >> for_add_str;
	_Film_lib.set_screenwriter(for_add_str);
	cout << "¬ведите  омпозитора фильма:" << endl;
	cin >> for_add_str;
	_Film_lib.set_composer(for_add_str);
	cout << "¬ведите день выхода фильма:" << endl;
	cin >> for_add_int;
	_Film_lib.set_day(for_add_int);
	cout << "¬ведите мес€ц выхода фильма:" << endl;
	cin >> for_add_int;
	_Film_lib.set_mount(for_add_int);
	cout << "¬ведите год выхода фильма:" << endl;
	cin >> for_add_int;
	_Film_lib.set_year(for_add_int);
	cout << "¬ведите сборы фильма:" << endl;
	cin >> for_add_int;
	_Film_lib.set_film_gross(for_add_int);
	
};


