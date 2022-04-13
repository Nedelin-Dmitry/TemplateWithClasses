#include "Re_Hexr.h"



Hex::Hex()
{
	size = 20;
	num = new unsigned char[size];
	num_int = 0;
}

Hex::Hex(std::string vvod)
{
	size = vvod.length(); 
	num = new unsigned char[size];
	for (int i = 0; i < size; i++)
	{
		num[i] = (unsigned char)vvod[i];
	}
	int n = size - 1;
	num_int = 0;
	
	for (int i = 0; i < size; i++)
	{
		if ((int)num[i] >= 48 && (int)num[i] <= 57)
		{
			num_int = num_int + ((int)num[i] - 48) * ((int)pow(16, n));
			n = n - 1;
		}
		else if((int)num[i] >= 65 && (int)num[i] <= 70)
		{
			num_int = num_int + ((int)num[i] - 55) * (int)pow(16, n);
			n = n - 1;
		}
	}
	
}

Hex::Hex(int _num_int)
{
	// 0(48) - 9(57) and A(65) - F(70) ��� ����������
	int minus_flag = 0;
	if (_num_int < 0) minus_flag += 1;
	int zero_int = abs(_num_int);
	unsigned char* mass_char = new unsigned char[30];
	for (int i = 0; i < 30; i++)
	{
		mass_char[i] = (unsigned char)'0';
	}
	int remain = 0;
	int i = 0;
	while (zero_int != 0)
	{
		remain = zero_int % 16;
		if (remain >= 0 && remain <= 9)
		{
			mass_char[i] = (unsigned char)(48 + remain);
			i += 1;
			zero_int /= 16;
		}
		else if (remain > 9 && remain <= 15)
		{
			mass_char[i] = (unsigned char)(55 + remain);
			i += 1;
			zero_int /= 16;
		}
	}
	int _size = 0;// ��� �������� ������� 16-������� �����
	int flag = 0; //��� ���� ����� ������ ������ ������� ������ ����� (ABC000...0)
	int position = 29; // ��� ����, ����� ������ �� ����� ������� ���������
	for (int j = 29; j >= 0; j--)
	{
		if (mass_char[j] != '0')
		{
			flag = 1;
			position = i;
		}
		if (flag == 1) _size += 1;
	}
	size = _size;
	if (minus_flag == 1) size += 1;
	num_int = _num_int;
	num = new unsigned char[size];
	for (int j = 0; j < position; j++)
	{
		num[j] = mass_char[j];
	}
	/* - ����� ������� �� 1 ����� num[0] = '-'
	if (minus_flag == 1)
	{
		for (int j = 1; j < size - 1; j++)
		{
			
		}
	}
	*/
	for (int j = 0, k = size - 1; j < size; j++, k--)
	{
		unsigned char to_turn;
		to_turn = num[j];
		num[j] = num[k];
		num[k] = to_turn;
	}
}


Hex::Hex(const Hex& copy)
{
	size = copy.size;
	num_int = copy.num_int;
	num = new unsigned char[size];
	for (int i = 0; i < size; i++)
	{
		num[i] = copy.num[i];
	}

}

Hex::~Hex()
{
	delete[] num;
}

void write(Hex& h1)
{
	int output_int = h1.get_int();
	std::cout << output_int;
	std::cout << std::endl;
	for (int i = h1.get_size() - 1; i >= 0; i--) // ��������� ������ �� ��������???
	{
		char output_char = h1.get_char_i(i);
		std::cout << output_char;
	}
	std::cout << std::endl;
	
}

//�������

int Hex::get_size() { return size; };
int Hex::get_int() { return num_int; };
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
	int zero_num_int = 0;
	zero_num_int = h1.num_int + h2.num_int;
	Hex for_return = Hex(zero_num_int);
	return for_return;

}

Hex operator-(const Hex& h1, const Hex& h2)
{
	int zero_num_int = 0;
	if (h1.num_int > h2.num_int) zero_num_int = h1.num_int - h2.num_int;
	else if (h1.num_int < h2.num_int) zero_num_int = (-1) * (h2.num_int - h1.num_int);
	else zero_num_int = 0;
	Hex for_return = Hex(zero_num_int);
	return for_return;
}

unsigned char& Hex::operator[](const unsigned char index)
{
	assert(index >= 0 && index <= size); // assert - ��������� ������ ��������� ��� ������ �� �������, ������ �� ������������
	return num[index];
}

const unsigned char& Hex::operator[](const unsigned char index) const
{
	assert(index >= 0 && index <= size); 
	return num[index];
}

Hex operator*(const Hex& h1, const Hex& h2)
{
	Hex zero_num_int = Hex();
	zero_num_int.num_int = h1.num_int * h2.num_int;
	Hex for_return = Hex(zero_num_int.num_int);
	return for_return;
}

Hex operator*(const Hex& h1, int input)
{
	Hex zero_num_int = Hex();
	zero_num_int.num_int = h1.num_int * input;
	Hex for_return = Hex(zero_num_int.num_int);
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