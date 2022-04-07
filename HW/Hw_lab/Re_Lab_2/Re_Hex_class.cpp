#include "Re_Hexr.h"

int in_10_int(unsigned char _num[])
{
	int for_return = 0;	
	int size_num = sizeof(_num) / sizeof(_num[0]);
	int one_number;
	int degree = sizeof(_num) / sizeof(_num[0]) - 1;
	for (int i = 0; i < size_num; i++) // Ѕред?
	{
		switch (_num[i])
		{
		case '0': one_number = 0; break;
		case '1': one_number = 1; break;
		case '2': one_number = 2; break;
		case '3': one_number = 3; break;
		case '4': one_number = 4; break;
		case '5': one_number = 5; break;
		case '6': one_number = 6; break;
		case '7': one_number = 7; break;
		case '8': one_number = 8; break;
		case '9': one_number = 9; break;
		case 'A': one_number = 10; break;
		case 'B': one_number = 11; break;
		case 'C': one_number = 12; break;
		case 'D': one_number = 13; break;
		case 'E': one_number = 14; break;
		case 'F': one_number = 15; break;
		}
		for_return += one_number * (int)pow(16, degree);
		degree--;
	}
	return for_return;
}
void int_in_char(Hex& h1)
{
	int _zero = h1.num_int;
	int r;
	unsigned char* for__return = new unsigned char[100];
	for (int i = h1.size; i >= 0; i--) // while _zero /= 16 != 0
	{
		r = _zero % 16;
		_zero /= 16;
		if (r <= 9)
		{
			for__return[i] = (char)r;
		}
		else if (r > 9)
		{
			switch (r)
			{
			case 10: r = 'A'; break;
			case 11: for__return[i] = 'B'; break;
			case 12: for__return[i] = 'C'; break;
			case 13: for__return[i] = 'D'; break;
			case 14: for__return[i] = 'E'; break;
			case 15: for__return[i] = 'F'; break;
			}
			for__return[i] = (char)r;
		}
	}
	for (int i = h1.size; i >= 0; i--)
	{
		h1.num[i] = for__return[i];
	}

}

Hex::Hex()
{
	size = 20;
	num = new unsigned char[size];
	num_int = 0;
}

Hex::Hex(std::string vvod)
{
	size = vvod.length(); // возможна потер€ данных
	num = new unsigned char[size];
	for (int i = 0; i < size; i++)
	{
		num[i] = vvod[i];
	}
	num_int = in_10_int(num);
}

Hex::Hex(const Hex& copy)
{
	size = copy.size;
	num_int = copy.num_int;
	for (int i = 0; i < size; i++)
	{
		num[i] = copy.num[i];
	}

}

Hex::~Hex()
{
	delete[] num;
}

//геттеры

int Hex::get_size() { return size; };
int Hex::get_int_i() { return num_int; };
char Hex::get_char_i(int i) { return num[i]; };

Hex Hex::operator=(const Hex& h1)
{
	if (this != &h1)
	{
		size = h1.size;
		num_int = h1.num_int;
		num = new unsigned char[size];

		for (int i = 0; i < h1.size; i++)
		{
			num[i] = h1.num[i];
		}
	}
	return *this;
}

Hex operator+(const Hex& h1, const Hex& h2)
{
	Hex for_return = Hex();
	for_return.num_int = h1.num_int + h2.num_int;
	int for_dozens = for_return.num_int;
	int dozens = 0;
	int doz_test = 1;
	while (for_dozens / doz_test > 0)
	{
		doz_test *= 10;
		dozens += 1;
	}
	for_return.size = dozens - 1;
	for_return.num = new unsigned char[for_return.size];
	int_in_char(for_return);
	return for_return;

}

Hex operator-(const Hex& h1, const Hex& h2)
{
	Hex zero = Hex(h2);
	zero.num_int = (-1) * zero.num_int;
	Hex for_return = Hex();
	for_return = h1 + zero;
	return for_return;
}

unsigned char& Hex::operator[](const unsigned char index)
{
	assert(index >= 0 && index <= size); // прерывает работу программы при выходе за пределы, пам€ть не повреждаетс€
	return num[index];
}

const unsigned char& Hex::operator[](const unsigned char index) const
{
	assert(index >= 0 && index <= size); // прерывает работу программы при выходе за пределы, пам€ть не повреждаетс€
	return num[index];
}

Hex operator*(const Hex& h1, const Hex& h2)
{
	Hex for_return = Hex();
	for_return.num_int = h1.num_int * h2.num_int;
	int_in_char(for_return);
	return for_return;
}

Hex operator*(const Hex& h1, int input)
{
	Hex for_return = Hex();
	for_return.num_int = h1.num_int * input;
	int_in_char(for_return);
	return for_return;
}

bool operator>(Hex& h1, Hex& h2)
{
	if (h1.num_int > h2.num_int)
	{
		return 1;
	}
	return 0;
}
bool operator<(Hex& h1, Hex& h2)
{
	if (h1.num_int < h2.num_int)
	{
		return 1;
	}
	return 0;
}
bool operator>=(Hex& h1, Hex& h2)
{
	if (h1.num_int >= h2.num_int)
	{
		return 1;
	}
	return 0;
}
bool operator<=(Hex& h1, Hex& h2)
{
	if (h1.num_int <= h2.num_int)
	{
		return 1;
	}
	return 0;
}

bool operator==(Hex& h1, Hex& h2)
{
	if (h1.num_int == h2.num_int)
	{
		return 1;
	}
	return 0;
}

bool operator!=(Hex& h1, Hex& h2)
{
	return !(h1 == h2);
} 

std::ostream& operator<<(std::ostream& out, const Hex& _str)
{
	for (int i = 0; i < _str.size; i++)
	{
		out << _str.num[i];
	}
	out << std::endl;
	return out;
}

std::istream& operator>>(std::istream& in, Hex& _str)
{
	char ss[255];
	in.getline(ss, 255);
	for (int i = 0; i < 255; i++)
	{
		_str.num[i] = ss[i];
	}
	return in;

}