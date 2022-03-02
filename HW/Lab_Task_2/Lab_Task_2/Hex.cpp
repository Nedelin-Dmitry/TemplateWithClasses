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
	можно попробовать умножение -!!!!!!!!!!!!!!!!!!!!!как решить проблему с большим преодолением предела "вверх"?!!!!!!!!!!!!!!!!!!!!!!!!
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

class Hex
{
private:
	int size;// размер массива
	unsigned char abc[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' }; // алфавит для функции (как метод?) значение в mass_int[i] равно букве abc[i]
	int* mass_int;//будет нужен для перегрузки сложения и вычитания
	std::string mass_str;

public:

	Hex()
	{
		size = 1;
	}
	Hex(int size)// для создания массива размером size
	{
		mass_int = new int(size); // перевернуть для удобства подсчёта?
	}
	Hex(int size, std::string input) // создаём массив размером size и сразу задаными значениями - удобно ли?
	{
		mass_int = new int(size);
		mass_str = input; // копируем  значение строки - спросить про конфликт функций strcpy и другими функциями!!
		int str_size = strlen(mass_str.c_str());// узнаём длину ввода - C4267	инициализация : преобразование из "size_t" в "int"; возможна потеря данных	

		for (int i = 0; i < str_size; i++) { // заполняем int массив десятичными аналогами для операций + и -
			char in = mass_str[i];
			switch (in) // можно ли сократить?
			{
			case '0':
				mass_int[i] = 0;
			case '1':
				mass_int[i] = 1;
			case '2':
				mass_int[i] = 2;
			case '3':
				mass_int[i] = 3;
			case '4':
				mass_int[i] = 4;
			case '5':
				mass_int[i] = 5;
			case '6':
				mass_int[i] = 6;
			case '7':
				mass_int[i] = 7;
			case '8':
				mass_int[i] = 8;
			case '9':
				mass_int[i] = 9;
			case 'A':
				mass_int[i] = 10;
			case 'B':
				mass_int[i] = 11;
			case 'C':
				mass_int[i] = 12;
			case 'D':
				mass_int[i] = 13;
			case 'E':
				mass_int[i] = 14;
			case 'F':
				mass_int[i] = 15;
			}
		}
	}

	~Hex()
	{
		delete mass_int;
	}

	Hex operator=(const Hex& in_1)
	{
		for (int i = 0; i < size; i++){
			mass_str[i] = in_1.mass_str[i];
			mass_int[i] = in_1.mass_int[i];
		}

	}
	Hex operator[](const int index) // для остального - работает ли для определённого массива?
	{
		assert(index >= 0 && index <= size); // прерывает работу программу при выходе за пределы массива - память не повреждается - можно через if с выводом error'а
		return mass_int[index];
	}

	Hex operator[](const int index) const // для вывода и просмотра
	{
		assert(index >= 0 && index <= size);
		return mass_int[index];
	}

	Hex operator+(const Hex& in_2) // Как решить проблему если создаётся новый десяток - создавать новый массив размером на 1 и после копирования со сдвигом вправо на 1 возвращать его?
	{
		Hex in_2_2;
		if (size > in_2.size)
		{
			in_2_2 = Hex(size); //создаём массив соответствующего размера и заполняем его
			int diff = size - in_2.size;
			for (int i = 0; i < diff; i++) 
			{
				in_2_2.mass_int[i] = 0;
			}
			for (int i = diff; i < size; i++) // начинаем заполнять с разности, отстальное равно нулю
			{
				in_2_2.mass_int[diff] = in_2.mass_int[i];
				diff += 1;
			}
			for (int i = size; i > 0; i--)
			{
				mass_int[i] += in_2_2.mass_int[i]; // написать отдельную функцию для замены mass_str на новые значения
				while (mass_int[i] > 15)
				{
					in_2.mass_int[i - 1] += 1;
					in_2.mass_int[i] -= 15;
				}
			}
			return in_2; // удалять h_2_2 перед return
		}
		else if (size < in_2.size)
		{
			in_2_2 = Hex(in_2.size);
			int diff = in_2.size - size;
			for (int i = 0; i < diff; i++)
			{
				in_2_2.mass_int[i] = 0;
			}
			for (int i = diff; i < in_2.size; i++) {
				in_2_2.mass_int[diff] = in_2.mass_int[i];
				diff += 1;
			}
			for (int i = size; i > 0; i--)
			{
				in_2.mass_int[i] += in_2_2.mass_int[i]; // пересечение верхнего предела? - создать размером на 1 больше, всё перезаписать- но что делать если несколько пересечений предела?
				while (in_2.mass_int[i] > 15)
				{
					in_2.mass_int[i - 1] += 1;
					in_2.mass_int[i] -= 15;
				}
			}
			Hex f_ret = Hex(in_2.size);
			for (int i = 0; i < in_2.size; i++) {
				f_ret.mass_int[i] = in_2.mass_int[i];
			}
			return f_ret;
	
		}

	}
	Hex operator-(const Hex& in_3)
	{
		return in_3;
	}

	friend bool operator==(const Hex& a, const Hex& b);
	friend std::ostream& operator<<(std::ostream& out, const Hex& f_out);
	friend std::istream& operator>>(std::istream& in, const Hex& f_in);
};

bool operator==(const Hex& a, const Hex& b)
{
	if (a.size == b.size)
	{
		for (int i = 0; i < a.size; i++)
		{
			int a1 = a.mass_int[i];
			int b1 = b.mass_int[i];
			if (a1 != b1)
			{
				return 0;
			}
			/*
			bool b = (a.mass_int[i] == b.mass_int[i]);
				c = c * b;
			*/
		}
		return 1;
	}
		return 0;
}

std::ostream& operator<<(std::ostream& out, const Hex& f_out) // сделать простой вывод строки mass_str(из функции)
{
	for (int i = 0; i < f_out.size; i++)
	{
		out << f_out.mass_int[i];
	}
	out << std::endl;

	return out;
}
std::istream& operator>>(std::istream& in, const Hex& f_in) // должен обрабатывать строку - сейчас не работает
{
	int a = sizeof f_in;
	for (int i = 0; i < a; i++) 
	{
		in >> f_in.mass_int[i];
	}

	return in;

}

int main() {

	return 0;

}