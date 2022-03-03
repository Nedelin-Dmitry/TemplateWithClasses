/*
 5. Шестнадцатеричное число
	Создать класс Hex для работы с беззнаковыми целыми шестнадцатеричными числами, используя
	для представления числа массив из элементов типа unsigned char, каждый из которых является
	шестнадцатеричной цифрой. Младшая цифра имеет меньший индекс. Размер массива задается
	как аргумент конструктора.
	Реализовать операции:
	присваивания;
	арифметические: +, -;
	сравнения
	можно попробовать умножение
	операцию индексации с контролем выхода индекса за границы массива.
	операции << и >> для сохранения себя в файле и чтения из файла
*/
// 0123456789 A  B  C  D  E  F
// 0123456789 10 11 12 13 14 15
#include <cassert> // для assert();
#include<iostream>
#include<string>
#include<cstring> //работают по разному?
#include<cstdlib>
#include <sstream>
#include <fstream>

class Hex
{
private:
	int size;// размер массива
	unsigned char* num;
	int* mass_int;//будет нужен для перегрузки сложения и вычитания

public:

	Hex()
	{
		size = 10;
		num[size];
		mass_int[size];

	}
	Hex(int size)// конструктро инициализации
	{
		mass_int[size];
		num[size];
	}
	Hex(const Hex& copy)
	{
		size = copy.size;
		mass_int = new int[size];
		num = new unsigned char[size];

		for (int i = 0; i < copy.size; i++)
		{
			mass_int[i] = copy.mass_int[i];
			num[i] = copy.mass_int[i];
		}
	}

	~Hex()
	{
		delete mass_int;
		delete num;
		size = 0;
	}

	void in_char(Hex& zero) // преобразование значение mass_int в значения символы для num
	{ // 0(48) - 9(57) and A(65) - F(70) для десятичной

		for (int i = 0; i < size; i++)
		{
			if (i >= 0 && i < 10)
			{
				zero.num[i] = 48 + zero.mass_int[i];
			}
			else if (i >= 10 && i <= 15)
			{
				zero.num[i] = 55 + zero.mass_int[i];
			}

		}
	}


	Hex operator=(const Hex& h1)
	{
		if (this != &h1)
		{
			size = h1.size;
			mass_int = new int[size];
			num = new unsigned char[size];

			for (int i = 0; i < h1.size; i++)
			{
				mass_int[i] = h1.mass_int[i];
				num[i] = h1.mass_int[i];
			}
		}
		return *this;
	}

	// ничего не сделал с переполнением результата "вверх" 
	Hex operator+(const Hex& h2)
	{
		int a;
		if (size > h2.size) // определяем наибольший массив
		{
			a = size;
		}
		else
		{
			a = h2.size;
		}
		int* mass_int1 = new int; // создаём массивы с размером наибольшего массива
		*mass_int1 = a;
		int* mass_int2 = new int;
		*mass_int2 = a;
		for (int i = 0; i < a; i++) // заполняем нулями
		{
			mass_int1[i] = 0;
			mass_int2[i] = 0;
		}
		for (int i = 0; i < size; i++) // копируем в новые массивы значения старых
		{
			mass_int1[a - i] = mass_int[size - i];
		}
		for (int i = 0; i < h2.size; i++)
		{
			mass_int2[a - i] = h2.mass_int[h2.size - i];
		}
		Hex for_return = Hex(a);
		for (int i = a; i > 0; i--)
		{
			for_return[i] = mass_int1[i] + mass_int2[i];
		}
		in_char(for_return);
		// функция перевода значений main_int(for_return) в значения из ASCII
		return for_return;

	}
	// ничего не сделал с переполнением результата "вниз"
	Hex operator-(const Hex& h3)
	{
		int a;
		if (size > h3.size) // определяем наибольший массив
		{
			a = size;
		}
		else
		{
			a = h3.size;
		}
		int* mass_int1 = new int; // создаём массивы с размером наибольшего массива
		*mass_int1 = a;
		int* mass_int2 = new int;
		*mass_int2 = a;
		for (int i = 0; i < a; i++) // заполняем нулями
		{
			mass_int1[i] = 0;
			mass_int2[i] = 0;
		}
		for (int i = 0; i < size; i++) // копируем в новые массивы значения старых
		{
			mass_int1[a - i] = mass_int[size - i];
		}
		for (int i = 0; i < h3.size; i++)
		{
			mass_int2[a - i] = h3.mass_int[h3.size - i];
		}
		Hex for_return = Hex(a);
		for (int i = a; i > 0; i--)
		{
			for_return[i] = mass_int1[i] - mass_int2[i];
		}
		in_char(for_return); // минусовое значение?
		// функция перевода значений main_int(for_return) в значения из ASCII
		return for_return;
	}

	Hex operator[](const int index)
	{
		assert(index >= 0 && index <= size); // прерывает работу программы при выходе за пределы, память не повреждается
		return mass_int[index];
	}

	Hex operator[](const int index) const
	{
		assert(index >= 0 && index <= size); // прерывает работу программы при выходе за пределы, память не повреждается
		return mass_int[index];
	}

	Hex operator*(const Hex& h4) // ещё работаю над этим
	{
		return h4;
	}

	friend std::ostream& operator<<(std::ostream& out, const Hex& h5);
	friend std::istream& operator>>(std::istream& in, Hex& h6);
};

std::ostream& operator<<(std::ostream& out, const Hex& h5)
{
	std::ofstream ofile{ "out.txt" };
	for (int i = 0; i < h5.size; i++)
	{
		out << h5.num[i];
	}
	return out;
}

std::istream& operator>>(std::istream& in, Hex& h6)
{
	std::string input;
	in >> std::hex >> input;
	for (int i = 0; i < h6.size; i++)
	{
		char input_t = input[i];
		h6.num[i] = (unsigned char)(input_t);
	}
	return in;
}

int main() {

	return 0;

}