#include"Film_lib_2.h"


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

��������� ��� ���������� ���������� ������ �������
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
	title = '-';
	director = '-';
	screenwriter = '-';
	composer = '-';
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
	lib_size = LIB_SIZE;
	Film_lib = new Film[lib_size];

}

Film_library::Film_library(int _lib_size)
{
	lib_size = _lib_size;
	Film_lib = new Film[lib_size];
}
/*
Film_library::~Film_library()
{
	delete[] & Film_lib;
}
*/

// ��������� �� �������� � ��������
// �� ���� ����� 2 ������� partition � quickSort ����� �������
void Hoare_Sort(Film* Film_lib, int left, int right) // ��������� �� ������ �������, ������ �������, ������ ������� - lib_size
{
	int pivot; // ����������� �������
	int l_hold = left; //����� �������
	int r_hold = right; // ������ �������
	pivot = Film_lib[left].get_film_gross();
	while (left < right) // ���� ������� �� ���������
	{
		while ((Film_lib[right].get_film_gross() >= pivot) && (left < right))
			right--; // �������� ������ ������� ���� ������� [right] ������ [pivot]
		if (left != right) // ���� ������� �� ����������
		{
			Film_lib[left] = Film_lib[right]; // ���������� ������� [right] �� ����� ������������
			left++; // �������� ����� ������� ������
		}
		while ((Film_lib[left].get_film_gross() <= pivot) && (left < right))
			left++; // �������� ����� ������� ���� ������� [left] ������ [pivot]
		if (left != right) // ���� ������� �� ����������
		{
			Film_lib[right] = Film_lib[left]; // ���������� ������� [left] �� ����� [right]
			right--; // �������� ������ ������� �����
		}
	}
	Film_lib[left].set_film_gross(pivot); // ������ ����������� ������� �� �����
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot) // ���������� �������� ���������� ��� ����� � ������ ����� �������
		Hoare_Sort(Film_lib, left, pivot - 1);
	if (right > pivot)
		Hoare_Sort(Film_lib, pivot + 1, right);
}

Film& Film_library::operator[](const int index) // �������� assert
{
	assert(index >= 0 && index <= lib_size); // ��������� ������ ��������� ��� ������ �� �������, ������ �� ������������
	return Film_lib[index];
}

const Film& Film_library::operator[](const int index) const
{
	assert(index >= 0 && index <= lib_size); // ��������� ������ ��������� ��� ������ �� �������, ������ �� ������������
	return Film_lib[index];
}

// ���������� ������� ������

//2 ��������� - string & int -  3 ����� ����� �� - �������� � ����
Film_library search(Film_library _Film_lib, string _title, int _year)
{
	int a = LIB_SIZE; // ������� �.� ������������ ��������� define
	Film_library Return_lib = Film_library(1);
	//int return_fill_pos = 0;
	for (int i = 0; i < _Film_lib.lib_size; i++)
	{

		if (_Film_lib.Film_lib[i].get_title() == _title && _Film_lib.Film_lib[i].get_year() == _year)
		{
			Return_lib.Film_lib[0] = _Film_lib.Film_lib[i];
			return Return_lib;
		}
	}
	cout << "������ �� �������..." << endl;
	return Return_lib;
}

// 1 �������� string - 4 ������ ��� ������ ��������� ��������� (�� �� �������) - string
Film_library search(Film_library _Film_lib, string _director)
{
	int a = LIB_SIZE; // ������� �.� ������������ ��������� define
	Film_library Return_lib = Film_library(a);
	int return_fill_pos = 0;
	for (int i = 0; i < _Film_lib.lib_size; i++)
	{

		if (_Film_lib.Film_lib[i].get_director() == _director)
		{
			Return_lib.Film_lib[return_fill_pos] = _Film_lib.Film_lib[i];
			return_fill_pos += 1;
		}
	}
	if (return_fill_pos > 0)
	{
		return Return_lib;
	}
	cout << "������ �� �������..." << endl;
	return Return_lib;
};


// 1 �������� Int - 5 ������ ��� ������, �������� � ������ � ��������� ���� (�� �� �������) - int
Film_library search(Film_library _Film_lib, int _year)
{
	int a = LIB_SIZE; // ������� �.� ������������ ��������� define
	Film_library Return_lib = Film_library(a);
	int return_fill_pos = 0;
	for (int i = 0; i < _Film_lib.lib_size; i++)
	{

		if (_Film_lib.Film_lib[i].get_year() == _year)
		{
			Return_lib.Film_lib[return_fill_pos] = _Film_lib.Film_lib[i];
			return_fill_pos += 1;
		}
	}
	if (return_fill_pos > 0)
	{
		return Return_lib;
	}
	cout << "������ �� �������..." << endl;
	return Return_lib;

};


// 2 ��������� Int 6 ������ �������� ����� ������� � ����������� ������� (�� �� �������) - int int
Film_library search(Film_library _Film_lib, int num, int _film_gross)
{
	int a = LIB_SIZE; // ������� �.� ������������ ��������� define
	Film_library Return_lib = Film_library(a);
	Hoare_Sort(_Film_lib.Film_lib, 0, _Film_lib.lib_size); // ���������� ��������
	int return_lib_pos = 0;
	int num_check = 0;
	for (int i = _Film_lib.lib_size; i >= 0; i--)
	{
		if (num_check == num) break;
		Return_lib[return_lib_pos] = _Film_lib[i];
		num_check += 1;
	}
	return Return_lib;
	
};


// 3 ��������� Int - 7 ������ �������� ����� ������� � ����������� ������� � ��������� ���� (�� �� �������) - int int int
Film_library search(Film_library _Film_lib, int num, int _film_gross, int _year)
{
	int a = LIB_SIZE; // ������� �.� ������������ ��������� define
	Film_library Return_lib = Film_library(a);
	Hoare_Sort(_Film_lib.Film_lib, 0, _Film_lib.lib_size); // ���������� ��������
	int return_lib_pos = 0;
	int num_check = 0;
	for (int i = _Film_lib.lib_size; i >= 0; i--)
	{
		if (num_check == num) break;
		else if (_Film_lib[i].get_year() == _year)
		{
			Return_lib[return_lib_pos] = _Film_lib[i];
			num_check += 1;
		}
	}
	return Return_lib;
};



void Add_film(Film_library _Film_lib)
{
	string _title;
	for (int i = 0; i < _Film_lib.lib_size; i++)
	{
		_title = _Film_lib.Film_lib[i].get_title();
		if (_title == "-")
		{
			string for_add_str;
			int for_add_int;
			std::cout << "������� �������� ������:" << endl;
			std::cin >> for_add_str;
			_Film_lib.Film_lib[i].set_title(for_add_str);
			std::cout << "������� ������� ������:" << endl;
			std::cin >> for_add_str;
			_Film_lib.Film_lib[i].set_director(for_add_str);
			std::cout << "������� ���������� ������:" << endl;
			std::cin >> for_add_str;
			_Film_lib.Film_lib[i].set_screenwriter(for_add_str);
			std::cout << "������� ����������� ������:" << endl;
			std::cin >> for_add_str;
			_Film_lib.Film_lib[i].set_composer(for_add_str);
			std::cout << "������� ���� ������ ������:" << endl;
			std::cin >> for_add_int;
			_Film_lib.Film_lib[i].set_day(for_add_int);
			std::cout << "������� ����� ������ ������:" << endl;
			std::cin >> for_add_int;
			_Film_lib.Film_lib[i].set_mount(for_add_int);
			std::cout << "������� ��� ������ ������:" << endl;
			std::cin >> for_add_int;
			_Film_lib.Film_lib[i].set_year(for_add_int);
			std::cout << "������� ����� ������:" << endl;
			std::cin >> for_add_int;
			_Film_lib.Film_lib[i].set_film_gross(for_add_int);
			_Film_lib.lib_size += 1;
			break;
		}
	}

};

void Film_redactor(Film_library _Film_lib, string _title, int _user_choose) // 2 �������� ������ ������ ���������� �� ��������
{
	for (int i = 0; i < _Film_lib.lib_size; i++)
	{
		if (_Film_lib.Film_lib[i].get_title() == _title)
		{
			switch (_user_choose)
			{

			case 1:
			{
				string for_add_str;
				std::cout << "������� �������� ������:";
				std::cin >> for_add_str;
				_Film_lib.Film_lib[i].set_title(for_add_str);
			}
			break;
			case 2:
			{
				string for_add_str;
				std::cout << "������� ������� ������:";
				std::cin >> for_add_str;
				_Film_lib.Film_lib[i].set_director(for_add_str);
			}
			break;
			case 3:
			{
				string for_add_str;
				std::cout << "������� ���������� ������:";
				std::cin >> for_add_str;
				_Film_lib.Film_lib[i].set_screenwriter(for_add_str);
			}
			break;
			case 4:
			{
				string for_add_str;
				std::cout << "������� ����������� ������:";
				std::cin >> for_add_str;
				_Film_lib.Film_lib[i].set_composer(for_add_str);
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
					_Film_lib.Film_lib[i].set_day(for_add_int);
					break;
				case 2:
					std::cout << "������� �����:";
					std::cin >> for_add_int;
					_Film_lib.Film_lib[i].set_mount(for_add_int);
					break;
				case 3:
					std::cout << "������� ���:";
					std::cin >> for_add_int;
					_Film_lib.Film_lib[i].set_year(for_add_int);
					break;
				}
			}
			case 6:
			{
				int for_add_int;
				std::cout << "������� ����� ������:";
				std::cin >> for_add_int;
				_Film_lib.Film_lib[i].set_film_gross(for_add_int);
			}
			break;
			}

		break;
		}
	}
}

Film_library title_year_search(Film_library _Film_lib, string _title, int _year) // 3 ����� ����� �� - �������� � ���� - string & int
{
	return search(_Film_lib, _title, _year);
}

Film_library screenwriter_year_search(Film_library _Film_lib, string _director) // 4 ������ ��� ������ ��������� ��������� (�� �� �������) - string
{
	return search(_Film_lib, _director);
}

Film_library year_search(Film_library _Film_lib, int _year) // 5 ������ ��� ������, �������� � ������ � ��������� ���� (�� �� �������) - int
{
	return search(_Film_lib, _year);
}

Film_library film_gross_search(Film_library _Film_lib, int num, int _film_gross) // 6 ������ �������� ����� ������� � ����������� ������� (�� �� �������) - int int
{
	return search(_Film_lib, num, _film_gross);
}

Film_library year_maxn_gross_search(Film_library _Film_lib, int num, int _film_gross, int _year) // 7 ������ �������� ����� ������� � ����������� ������� � ��������� ���� (�� �� �������) - int int int
{
	return search(_Film_lib, num, _film_gross, _year);
}


int get_films_count(Film_library lib) // 8 ������ ������� ����� �������
{
	return lib.lib_size;
}

// ����� ������� - �������� � ������ ����� ������� � ��������
void delete_film(Film_library _film_lib, string _title) // 9 ������� ����� �� ��������
{
	for (int i = 0; i < _film_lib.lib_size; i++)
	{
		if (_film_lib.Film_lib[i].get_title() == _title)
		{
			string _not_delete_str = "-";
			int _not_delete_int = 0;
			_film_lib.Film_lib[i].set_day(_not_delete_int);
			_film_lib.Film_lib[i].set_mount(_not_delete_int);
			_film_lib.Film_lib[i].set_year(_not_delete_int);
			_film_lib.Film_lib[i].set_film_gross(_not_delete_int);
			_film_lib.Film_lib[i].set_title(_not_delete_str);
			_film_lib.Film_lib[i].set_director(_not_delete_str);
			_film_lib.Film_lib[i].set_screenwriter(_not_delete_str);
			_film_lib.Film_lib[i].set_composer(_not_delete_str);
			break;
		}
	}
}

// ������� ���������� � �������� ���������� �� ����� - 10 ��������� ���������� � ���� � ������� ���������� �� ����� 

void Lib_save(const Film_library& _Film_lib)
{
	ofstream out;
	out.open("Saved_film_lib");
	if (out.is_open())
	{
		for (int i = 0; i < _Film_lib.lib_size; i++)
		{
			if (_Film_lib.Film_lib[i].get_title() == "-") continue;
			// i) title || director || screenwritter || composer || day.mount.year || film_gross 
			out << to_string(i) << ") " << _Film_lib.Film_lib[i].get_title() << " || " << _Film_lib.Film_lib[i].get_director() << " || "
				<< _Film_lib.Film_lib[i].get_screenwriter() << " || " << _Film_lib.Film_lib[i].get_composer() << " || "
				<< _Film_lib.Film_lib[i].get_year() << "." << _Film_lib.Film_lib[i].get_mount() << "." << _Film_lib.Film_lib[i].get_year() << " || "
				<< _Film_lib.Film_lib[i].get_film_gross() << "       " << endl;
		}
	}
	out << std::endl;
	out.close();
}

void Lib_load(Film_library& _str)
{
	ifstream in;
	string line_read;
	in.open("Saved_film_lib");
	if (in.is_open())
	{
		while (getline(in, line_read))
		{
			// � ��� ��������� ������� �� 
		}
	}
}




Film Line_to_Film(string read_line)
{
	Film for_return;
	int num_data = 0;
	for (int i = 3; i < read_line.size() - 3; i++) // ���� �� ����� �� ������� ������ - ������� 7 ��������  
	{
		if(1)
		{

		}
		// ...
		switch (num_data)
		{
		case 1: // title
			break;
		case 2: // director
			break;
		case 3: // screenwriter
			break;
		case 4: // Composer
			break;
		case 5: // day
			break;
		case 6: // mount
			break;
		case 7: // year
			break;
		case 8: // film_gross
			break;
		}
	}
	return for_return;
}


void Write_film(Film_library _Film_lib)
{
	for (int i = 0; i < _Film_lib.lib_size; i++)
	{
		if (_Film_lib.Film_lib[i].get_title() != "-") continue;
		cout << "�������� ������: " << _Film_lib.Film_lib[i].get_title() << "\n������ ������: " << _Film_lib.Film_lib[i].get_director() << "\n��������� ������: "
			<< _Film_lib.Film_lib[i].get_screenwriter() << "\n���������� ������: " << _Film_lib.Film_lib[i].get_composer() << "\n���� ������: " << _Film_lib.Film_lib[i].get_day() << "."
			<< _Film_lib.Film_lib[i].get_mount() << "." << _Film_lib.Film_lib[i].get_year() << "\n����� ������: " << _Film_lib.Film_lib[i].get_film_gross() << "$" << endl;
	}
}