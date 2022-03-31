
#include "hex_class.h"

//тип класс:: функция()zalupa::zalupa plus()

int to_int_4_class(unsigned char a)
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
	else
	{
		return 0;
	}
}

Hex::Hex()
{
	size = 10;
	num = new unsigned char[size];
	mass_int = new int[size];
}
Hex::Hex(int _size)
{
	size = _size;
	mass_int = new int[size];
	num = new unsigned char[size];
}
Hex::Hex(std::string vvod)
{
	size = vvod.length(); // возможна потеря данных
	mass_int = new int[size];
	num = new unsigned char[size];
	for (int i = 0; i < size; i++)
	{
		num[i] = vvod[i];
	}
	for (int i = 0; i < size; i++)
	{
		mass_int[i] = to_int_4_class(num[i]);
	}
}

/*
Hex::Hex(int _mass_int[])
{

}
*/

Hex::Hex(const Hex& copy)
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

Hex::~Hex()
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

int Hex::get_size() { return size; };
int Hex::get_int_i(int i) { return mass_int[i]; };
char Hex::get_char_i(int i) { return num[i]; };

Hex Hex::operator=(const Hex& h1)
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

Hex operator+(const Hex& h1, const Hex& h2)
{
	int a;
	if (h1.size > h2.size) // определяем наибольший массив
	{
		a = h1.size;
	}
	else
	{
		a = h2.size;
	}
	int* mass_int1 = new int[a]; // создаём массивы с размером наибольшего массива
	int* mass_int2 = new int[a];
	for (int i = 0; i < a; i++) // заполняем нулями
	{
		mass_int1[i] = 0;
		mass_int2[i] = 0;
	}
	for (int i = (a - h1.size) - 1; i < h1.size; i++) // копируем в новые массивы значения старых
	{
		mass_int1[i] = h1.mass_int[i - (a - h1.size) + 1];
	}
	for (int i = (a - h2.size) - 1; i < h2.size; i++)
	{
		mass_int2[i] = h2.mass_int[i - (a - h2.size) + 1];
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
Hex operator-(const Hex& h1, const Hex& h2)
{
	Hex _h2 = Hex(h2);
	for (int i = 0; i < h2.size; i++)
	{
		_h2.mass_int[i] = (-1) * _h2.mass_int[i];
	}
	int max_size;
	if (h1.size > h2.size)
	{
		max_size = h1.size;
	}
	else
	{
		max_size = h2.size;
	}
	Hex draft_for_return = Hex(max_size);
	for (int i = 0; i < max_size; i++)
	{
		draft_for_return.mass_int[i] = 0;
	}
	draft_for_return = h1 + _h2;
	int return_mass_size = draft_for_return.size;
	for (int i = 0; i < max_size; i++)
	{
		if (draft_for_return.mass_int[i] == 0)
		{
			return_mass_size -= 1;
		}
	}
	Hex for_return = Hex()

}
*/
Hex operator-(const Hex& h1, const Hex& h2)
{
	int a;
	if (h1.size > h2.size) // определяем наибольший массив
	{
		a = h1.size;
	}
	else
	{
		a = h2.size;
	}
	int* mass_int1 = new int[a]; // создаём массивы с размером наибольшего массива
	int* mass_int2 = new int[a];
	for (int i = 0; i < a; i++) // заполняем нулями
	{
		mass_int1[i] = 0;
		mass_int2[i] = 0;
	}
	for (int i = (a - h1.size) - 1; i < h1.size; i++) // копируем в новые массивы значения старых
	{
		mass_int1[i] = h1.mass_int[i - (a - h1.size) + 1];
	}
	for (int i = (a - h2.size) - 1; i < h2.size; i++)
	{
		mass_int2[i] = h2.mass_int[i - (a - h2.size) + 1];
	}
	Hex for_return = Hex(a);
	for (int i = a; i > 0; i--)
	{
		if (mass_int1[i] > mass_int2[i])
		{
			for_return[i] = mass_int1[i] - mass_int2[i];
		}
		else if (mass_int1[i] < mass_int2[i] && i != 0)// дальнейший заём по разряду?
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
			for_return2.mass_int[i] = for_return.mass_int[i + 1];
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

int& Hex::operator[](const int index)
{
	assert(index >= 0 && index <= size); // прерывает работу программы при выходе за пределы, память не повреждается
	return mass_int[index];
}

const int& Hex::operator[](const int index) const
{
	assert(index >= 0 && index <= size); // прерывает работу программы при выходе за пределы, память не повреждается
	return mass_int[index];
}

Hex operator*(const Hex& h1, const Hex& h2)
{
	int a;
	if (h1.size > h2.size)
	{
		a = h1.size;
	}
	else
	{
		a = h2.size;
	}
	int* mass_int1 = new int[a];
	int* mass_int2 = new int[a];
	for (int i = (a - h1.size) - 1; i < h1.size; i++) // копируем в новые массивы значения старых
	{
		mass_int1[i] = h1.mass_int[i - (a - h1.size) + 1];
	}
	for (int i = (a - h2.size) - 1; i < h2.size; i++)
	{
		mass_int2[i] = h2.mass_int[i - (a - h2.size) + 1];
	}
	Hex for_return = Hex(a);
	for (int i = a; i > -1; i--)
	{
		for_return.mass_int[i] = mass_int1[i] * mass_int2[i];
		while (for_return.mass_int[i] >= 16 && i != 0)
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

Hex operator*(const Hex& h1, int input)
{
	Hex for_return = Hex(h1.size);
	for (int i = h1.size; i > 0; i--)
	{
		for_return.mass_int[i] = h1.mass_int[i] * input;
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
		Hex for_return2 = Hex(h1.size + overflow);
		for (int i = h1.size + overflow; i > 0; i--)
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

bool operator>(Hex& h1, Hex& h2)
{
	if (h1.size < h2.size)
	{
		return false;
	}
	else if (h1.size > h2.size)
	{
		return true;
	}
	else
	{
		for (int i = 0; i < h1.size; i++)
		{
			if (h1.mass_int[i] > h2.mass_int[i])
			{
				return true;
			}
		}
		return false;
	}
}

bool operator<(Hex& h1, Hex& h2)
{
	if (h1.size < h2.size)
	{
		return true;
	}
	else if (h1.size > h2.size)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < h1.size; i++)
		{
			if (h1.mass_int[i] > h2.mass_int[i])
			{
				return false;
			}
		}
		return true;
	}
}
bool operator>=(Hex& h1, Hex& h2)
{
	if (h1.size < h2.size)
	{
		return false;
	}
	else if (h1.size > h2.size)
	{
		return true;
	}
	else
	{
		for (int i = 0; i < h1.size; i++)
		{
			int flag = 0;
			if (h1.mass_int[i] > h2.mass_int[i])
			{
				return true;
			}
			if (h1.mass_int[i] == h2.mass_int[i])
			{
				flag += 1;
				if (flag == h1.size)
				{
					return true;
				}
			}
		}
		return false;
	}
}

bool operator<=(Hex& h1, Hex& h2)
{
	if (h1.size < h2.size)
	{
		return true;
	}
	else if (h1.size > h2.size)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < h1.size; i++)
		{
			int flag = 0;
			if (h1.mass_int[i] > h2.mass_int[i])
			{
				return false;
			}
			if (h1.mass_int[i] == h2.mass_int[i])
			{
				flag += 1;
				if (flag == h1.size)
				{
					return true;
				}
			}
		}
		return true;
	}
}

bool operator==(Hex& h1, Hex& h2)
{
	if (h1.size == h2.size)
	{
		int flag = 0;
		for (int i = 0; i < h1.size; i++)
		{
			flag += 1;
			if (flag == h1.size)
			{
				return true;
			}
		}
	}
	else
	{
		return false;
	}
}

bool operator!=(Hex& h1, Hex& h2)
{
	return !(h1 == h2);
}

