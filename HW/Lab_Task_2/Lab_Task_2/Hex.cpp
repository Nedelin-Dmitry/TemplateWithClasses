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
	����� ����������� ��������� -!!!!!!!!!!!!!!!!!!!!!��� ������ �������� � ������� ������������ ������� "�����"?!!!!!!!!!!!!!!!!!!!!!!!!
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

class Hex
{
private:
	int size;// ������ �������
	unsigned char abc[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' }; // ������� ��� ������� (��� �����?) �������� � mass_int[i] ����� ����� abc[i]
	int* mass_int;//����� ����� ��� ���������� �������� � ���������
	std::string mass_str;

public:

	Hex()
	{
		size = 1;
	}
	Hex(int size)// ��� �������� ������� �������� size
	{
		mass_int = new int(size); // ����������� ��� �������� ��������?
	}
	Hex(int size, std::string input) // ������ ������ �������� size � ����� �������� ���������� - ������ ��?
	{
		mass_int = new int(size);
		mass_str = input; // ��������  �������� ������ - �������� ��� �������� ������� strcpy � ������� ���������!!
		int str_size = strlen(mass_str.c_str());// ����� ����� ����� - C4267	������������� : �������������� �� "size_t" � "int"; �������� ������ ������	

		for (int i = 0; i < str_size; i++) { // ��������� int ������ ����������� ��������� ��� �������� + � -
			char in = mass_str[i];
			switch (in) // ����� �� ���������?
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
	Hex operator[](const int index) // ��� ���������� - �������� �� ��� ������������ �������?
	{
		assert(index >= 0 && index <= size); // ��������� ������ ��������� ��� ������ �� ������� ������� - ������ �� ������������ - ����� ����� if � ������� error'�
		return mass_int[index];
	}

	Hex operator[](const int index) const // ��� ������ � ���������
	{
		assert(index >= 0 && index <= size);
		return mass_int[index];
	}

	Hex operator+(const Hex& in_2) // ��� ������ �������� ���� �������� ����� ������� - ��������� ����� ������ �������� �� 1 � ����� ����������� �� ������� ������ �� 1 ���������� ���?
	{
		Hex in_2_2;
		if (size > in_2.size)
		{
			in_2_2 = Hex(size); //������ ������ ���������������� ������� � ��������� ���
			int diff = size - in_2.size;
			for (int i = 0; i < diff; i++) 
			{
				in_2_2.mass_int[i] = 0;
			}
			for (int i = diff; i < size; i++) // �������� ��������� � ��������, ���������� ����� ����
			{
				in_2_2.mass_int[diff] = in_2.mass_int[i];
				diff += 1;
			}
			for (int i = size; i > 0; i--)
			{
				mass_int[i] += in_2_2.mass_int[i]; // �������� ��������� ������� ��� ������ mass_str �� ����� ��������
				while (mass_int[i] > 15)
				{
					in_2.mass_int[i - 1] += 1;
					in_2.mass_int[i] -= 15;
				}
			}
			return in_2; // ������� h_2_2 ����� return
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
				in_2.mass_int[i] += in_2_2.mass_int[i]; // ����������� �������� �������? - ������� �������� �� 1 ������, �� ������������- �� ��� ������ ���� ��������� ����������� �������?
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

std::ostream& operator<<(std::ostream& out, const Hex& f_out) // ������� ������� ����� ������ mass_str(�� �������)
{
	for (int i = 0; i < f_out.size; i++)
	{
		out << f_out.mass_int[i];
	}
	out << std::endl;

	return out;
}
std::istream& operator>>(std::istream& in, const Hex& f_in) // ������ ������������ ������ - ������ �� ��������
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