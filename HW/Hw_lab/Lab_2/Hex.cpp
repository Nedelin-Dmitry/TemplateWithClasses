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
//для массивов int mass = new int []  + решить как будет работать умножение
// 0123456789 A  B  C  D  E  F
// 0123456789 10 11 12 13 14 15
#include <cassert> // для assert();
#include<iostream>
#include<cstring> 
#include<cstdlib>
#include <sstream>
#include <fstream>

int in_int_4_constructor(unsigned char a)
{
	int Num_char = static_cast<int>(a);
	int result;
	if (Num_char >= 48 && Num_char <= 57)
	{
		result = Num_char - 48;
		return result;
	}
	else if (Num_char >= 65 && Num_char <= 70)
	{
		result = Num_char - 55;
		return result;
	}
}

class Hex
{
protected :
	int size;// размер массива
	unsigned char* num;
	int* mass_int;//будет нужен для перегрузки сложения и вычитания

public:

	Hex()
	{
		size = 10;
		num = new unsigned char[size];
		mass_int = new int[size];

	}

	Hex(int size)// конструктро инициализации
	{
		mass_int = new int [size];
		num = new unsigned char[size];
	}

	Hex(std::string vvod)
	{
		size = vvod.length();
		mass_int = new int [size];
		num = new unsigned char[size];
		for (int i = 0; i < size; i++)
		{
			num[i] = vvod[i];
		}
		for (int i = 0; i < size; i++)
		{
			mass_int[i] = in_int_4_constructor(num[i]);
		}
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
		for (int i = 0; i < size; i++)
		{
			int Num_char = (int)(num[i]);
			if (Num_char >= 48 && Num_char <= 57)
			{
				mass_int[i] = Num_char - 48;
			}
			else if (Num_char >= 65 && Num_char <= 70)
			{
				mass_int[i] = Num_char - 55;
			}
		}
	}

	~Hex()
	{
		delete[] mass_int;
		delete[] num;
		size = 0;
	}

	static void in_char(Hex& zero) // преобразование значений mass_int в символы для num
	{ // 0(48) - 9(57) and A(65) - F(70) для десятичной

		for (int i = 0; i < zero.size; i++)
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
	
	static void in_int(Hex& one)
	{// 0(48) - 9(57) and A(65) - F(70) для десятичной
		for (int i = 0; i < one.size; i++)
		{
			int Num_char = (int)(one.num[i]);
			if (Num_char >= 48 && Num_char <= 57)
			{
				one.mass_int[i] = static_cast<int>(one.num[i]) - 48;
			}
			else if (Num_char >= 65 && Num_char <= 70)
			{
				one.mass_int[i] = static_cast<int>(one.num[i]) - 55;
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
		int* mass_int1 = new int [a]; // создаём массивы с размером наибольшего массива
		int* mass_int2 = new int [a];
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
			for_return.mass_int[i] = mass_int1[i] + mass_int2[i]; //C:\Users\Admin\Desktop\Studies\Prog\HW_2\Hw_lab
			if (i != 1 && for_return.mass_int[i] > 15) {
				while (for_return.mass_int[i] % 15 == 0)
				{
					for_return.mass_int[i - 1] += 1;
					for_return.mass_int[i] -= 15;
				}
			}
		}
		if (for_return.mass_int[0] >= 16)
		{
			Hex ret = Hex(a + 1);
			for (int i = a; i > 0; i--)
			{
				ret[i] = for_return.mass_int[i];
			}
			ret.mass_int[0] = 1;
			ret.mass_int[1] -= 15;
			in_char(ret);
			return ret;
		}
		// функция перевода значений main_int(for_return) в значения из ASCII
		else
		{
			in_char(for_return);
			return for_return;
		}
	}
	/*
	 ???
	 Оформление через +
	 В перегрузку + добавить переполнение "вниз"
	 через friend перегрузку -, перезаписывается как обычно, но во втором массиве записать значения с "-"
	 вызвать Hex3 = Hex1 + Hex2
	 return Hex3
	 ???
	*/
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
		int* mass_int1 = new int [a]; // создаём массивы с размером наибольшего массива
		int* mass_int2 = new int [a];
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
			if (mass_int1[i] > mass_int2[i])
			{
				for_return[i] = mass_int1[i] - mass_int2[i];
			}
			else if (mass_int1[i] < mass_int2[i] && i!=0)// дальнейший заём по разряду?
			{
				mass_int1[i - 1] -= 1;
				mass_int1[i] += 15;
				for_return[i] = mass_int1[i] - mass_int2[i];
			}
		}
		Hex for_return2 = Hex(a - 1);
		if (for_return.mass_int[0] <= 0)
		{
			for (int i = 0; i < a - 1; i++)
			{
				for_return2.mass_int[i] = for_return.mass_int[i+1];
			}
			in_char(for_return2);
			return for_return2;
		}
		else
		{
			return for_return;
		}
		// функция перевода значений main_int(for_return) в значения из ASCII
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

	int get_size() const { return size; };
	int get_int_i(int i) { return mass_int[i]; };
	int get_char_i(int i) { return num[i]; };

	friend Hex operator*(const Hex& h4, const Hex& h4_1);
	friend Hex operator*(const Hex& h4, int input);
	friend std::ostream& operator<<(std::ostream& out, const Hex& h5);
	friend std::istream& operator>>(std::istream& in, Hex& h6);
	friend std::ostream& operator<<(std::ostream& stream, const Hex& _str);
	friend std::istream& operator>>(std::istream& stream, Hex& _str);

};

Hex operator*(const Hex& h4, const Hex& h4_1)
{
	int a;
	if (h4.size > h4_1.size) 
	{
		a = h4.size;
	}
	else
	{
		a = h4_1.size;
	}
	int* mass_int1 = new int[a]; 
	int* mass_int2 = new int[a];
	for(int i = 0; i < h4.size; i++) 
	{
		mass_int1[a - i] = h4.mass_int[h4.size - i];
	}
	for (int i = 0; i < h4_1.size; i++)
	{
		mass_int2[a - i] = h4_1.mass_int[h4_1.size - i];
	}
	Hex for_return = Hex(a);
	for (int i = a; i > -1; i--)
	{
		for_return.mass_int[i] = mass_int1[i] * mass_int2[i];
		while (for_return.mass_int[i] >= 16 && i!= 0)
		{
			for_return.mass_int[i - 1] += 1;
			for_return.mass_int[i] -= 15;
		}
	}
	int overflow = 0;
	if(for_return.mass_int[0] >= 16)
	{
		int overflow_unit = 1;
		while(for_return.mass_int[0] / overflow_unit != 0)
		{
			overflow_unit *= 15;
			overflow += 1;
		}
		Hex for_return2 = Hex(a + overflow);
		for (int i = a + overflow; i > 0; i--)
		{
			while (for_return2.mass_int[i] >= 16)
			{
				for_return2.mass_int[i - 1] += 1;
				for_return2.mass_int[i] -= 15;
			}
		}
		return for_return2;
	}
	else
	{
		return for_return;
	}
}

Hex operator*(const Hex& h4, int input)
{
	Hex for_return = Hex(h4.size);
	for (int i = h4.size; i > 0; i--)
	{
		for_return.mass_int[i] = h4.mass_int[i] * input;
		while (for_return.mass_int[i] >= 16)
		{
			for_return.mass_int[i - 1] += 1;
			for_return.mass_int[i] -= 15;
		}
	}
	int overflow = 0;
	if (for_return.mass_int[0] >= 16)
	{
		int overflow_unit = 1;
		while (for_return.mass_int[0] / overflow_unit != 0)
		{
			overflow_unit *= 15;
			overflow += 1;
		}
		Hex for_return2 = Hex(h4.size + overflow);
		for (int i = h4.size + overflow; i > 0; i--)
		{
			while (for_return2.mass_int[i] >= 16)
			{
				for_return2.mass_int[i - 1] += 1;
				for_return2.mass_int[i] -= 15;
			}
		}
		return for_return2;
	}
	else
	{
		return for_return;
	}
	

}
/*
std::ostream& operator<<(std::ostream& stream, const Hex& _str)
{
	stream << _str.num << std::endl;
	return stream;
}
std::istream& operator>>(std::istream& stream, Hex& _str)
{
	stream >> _str.num;
	return stream;

}
*/


int main() {

	/*
	присваивания;
	арифметические: +, -;
	сравнения
	можно попробовать умножение
	операцию индексации с контролем выхода индекса за границы массива.
	операции << и >> для сохранения себя в файле и чтения из файла
	*/
	Hex A = Hex('A1');
	Hex B = Hex('B1');
	Hex Result1 = Hex();
	Result1 = A + B;
	for (int i = 0; i < Result1.get_size(); i++)
	{
		int output_int = Result1.get_int_i(i);
		std::cout << output_int << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < Result1.get_size(); i++)
	{
		char output_char = Result1.get_char_i(i);
		std::cout << output_char << " ";
	}
	std::cout << std::endl;
	Hex Result2 = Hex();
	Result2 = Result1 - B;
	for (int i = 0; i < Result2.get_size(); i++)
	{
		int output_int = Result2.get_int_i(i);
		std::cout << output_int << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < Result2.get_size(); i++)
	{
		char output_char = Result2.get_char_i(i);
		std::cout << output_char << " ";
	}
	std::cout << std::endl;
	/*
	ofstream os;            // поток для записи
	os.open("complex.txt"); // файл для записи
	os << c2 << c3 << endl;
	os.close();

	// Чтение из потока
	ifstream is;            // поток для чтения
	is.open("complex.txt"); // файл для чтения
	is >> c1 >> c4;
	cout <<"c1: "<< c1;
	cout <<"c4: "<< c4;
	c4.outPut("c4");    // Это уже не нужно!!!
	is.close();

	*/

	return 0;

}