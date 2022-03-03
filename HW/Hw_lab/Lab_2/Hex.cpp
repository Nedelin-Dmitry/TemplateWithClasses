/*
 5. ����������������� �����
	������� ����� Hex ��� ������ � ������������ ������ ������������������ �������, ���������
	��� ������������� ����� ������ �� ��������� ���� unsigned char, ������ �� ������� ��������
	����������������� ������. ������� ����� ����� ������� ������. ������ ������� ��������
	��� �������� ������������.
	����������� ��������:
	������������;
	��������������: +, -;
	���������
	����� ����������� ���������
	�������� ���������� � ��������� ������ ������� �� ������� �������.
	�������� << � >> ��� ���������� ���� � ����� � ������ �� �����
*/
// 0123456789 A  B  C  D  E  F
// 0123456789 10 11 12 13 14 15
#include <cassert> // ��� assert();
#include<iostream>
#include<string>
#include<cstring> //�������� �� �������?
#include<cstdlib>
#include <sstream>
#include <fstream>

class Hex
{
private:
	int size;// ������ �������
	unsigned char* num;
	int* mass_int;//����� ����� ��� ���������� �������� � ���������

public:

	Hex()
	{
		size = 10;
		num[size];
		mass_int[size];

	}
	Hex(int size)// ����������� �������������
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

	void in_char(Hex& zero) // �������������� �������� mass_int � �������� ������� ��� num
	{ // 0(48) - 9(57) and A(65) - F(70) ��� ����������

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

	// ������ �� ������ � ������������� ���������� "�����" 
	Hex operator+(const Hex& h2)
	{
		int a;
		if (size > h2.size) // ���������� ���������� ������
		{
			a = size;
		}
		else
		{
			a = h2.size;
		}
		int* mass_int1 = new int; // ������ ������� � �������� ����������� �������
		*mass_int1 = a;
		int* mass_int2 = new int;
		*mass_int2 = a;
		for (int i = 0; i < a; i++) // ��������� ������
		{
			mass_int1[i] = 0;
			mass_int2[i] = 0;
		}
		for (int i = 0; i < size; i++) // �������� � ����� ������� �������� ������
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
		// ������� �������� �������� main_int(for_return) � �������� �� ASCII
		return for_return;

	}
	// ������ �� ������ � ������������� ���������� "����"
	Hex operator-(const Hex& h3)
	{
		int a;
		if (size > h3.size) // ���������� ���������� ������
		{
			a = size;
		}
		else
		{
			a = h3.size;
		}
		int* mass_int1 = new int; // ������ ������� � �������� ����������� �������
		*mass_int1 = a;
		int* mass_int2 = new int;
		*mass_int2 = a;
		for (int i = 0; i < a; i++) // ��������� ������
		{
			mass_int1[i] = 0;
			mass_int2[i] = 0;
		}
		for (int i = 0; i < size; i++) // �������� � ����� ������� �������� ������
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
		in_char(for_return); // ��������� ��������?
		// ������� �������� �������� main_int(for_return) � �������� �� ASCII
		return for_return;
	}

	Hex operator[](const int index)
	{
		assert(index >= 0 && index <= size); // ��������� ������ ��������� ��� ������ �� �������, ������ �� ������������
		return mass_int[index];
	}

	Hex operator[](const int index) const
	{
		assert(index >= 0 && index <= size); // ��������� ������ ��������� ��� ������ �� �������, ������ �� ������������
		return mass_int[index];
	}

	Hex operator*(const Hex& h4) // ��� ������� ��� ����
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