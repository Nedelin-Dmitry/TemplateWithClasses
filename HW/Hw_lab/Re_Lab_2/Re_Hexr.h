/*
5. ����������������� �����
������� ����� Hex ��� ������ � ������������ ������ ������������������ �������, ���������
��� ������������� ����� ������ �� ��������� ���� unsigned char, ������ �� ������� ��������
����������������� ������.������� ����� ����� ������� ������.������ ������� ��������
��� �������� ������������.
����������� �������� :
������������;
��������������: +, -;
���������
����� ����������� ���������
�������� ���������� � ��������� ������ ������� �� ������� �������.
�������� << � >> ��� ���������� ���� � ����� � ������ �� �����
*/

//��� �������� int mass = new int []  + ������ ��� ����� �������� ���������
// 0123456789 A  B  C  D  E  F
// 0123456789 10 11 12 13 14 15
#pragma once

#include <cassert> // ��� assert();
#include<iostream>
#include<cstring> 
#include<cstdlib>
#include <sstream>
#include <fstream>
#include <math.h>

class Hex
{
private:
	int size;
	unsigned char* num;
	int num_int;
public:
	Hex(); // �� ���������
	Hex(std::string vvod); // �������������� ���� 
	Hex(const Hex& copy);// �����������
	~Hex();// ����������

	friend int in_10_int(unsigned char _num[]);
	friend void int_in_char(Hex& h1);

	//�������

	int get_size();
	int get_int_i();
	char get_char_i(int i);

	// ��������� 
	Hex operator=(const Hex& h1);
	friend Hex operator+(const Hex& h1, const Hex& h2);
	friend Hex operator-(const Hex& h1, const Hex& h2);
	unsigned char& operator[](const unsigned char index); // char
	const unsigned char& operator[](const unsigned char index) const;
	friend Hex operator*(const Hex& h1, const Hex& h2);
	friend Hex operator*(const Hex& h1, int input);

	// ��������� ���������

	friend bool operator>(Hex& h1, Hex& h2);
	friend bool operator<(Hex& h1, Hex& h2);
	friend bool operator>=(Hex& h1, Hex& h2);
	friend bool operator<=(Hex& h1, Hex& h2);
	friend bool operator!=(Hex& h1, Hex& h2);
	friend bool operator==(Hex& h1, Hex& h2);

	// ��������� ����� � ������ � �����
	friend std::ostream& operator<<(std::ostream& out, const Hex& _str);
	friend std::istream& operator>>(std::istream& in, Hex& _str);

};
