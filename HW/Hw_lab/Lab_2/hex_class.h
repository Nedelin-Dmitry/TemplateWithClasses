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

class Hex
{
private:
	int size;
	unsigned char* num;
	int* mass_int;
public:
	Hex(); // �� ���������
	explicit Hex(int size); // ������������
	Hex(std::string vvod); // �������������� ���� 
	Hex(int _mass_int[]);
	Hex(const Hex& copy);// �����������
	~Hex();// ����������

	//������
	friend static void in_char(Hex& zero);
	friend static void in_int(Hex& one);
	//�������

	int get_size();
	int get_int_i(int i);
	char get_char_i(int i);

	// ��������� 
	Hex operator=(const Hex& h1);
	friend Hex operator+(const Hex& h1, const Hex& h2);
	friend Hex operator-(const Hex& h1, const Hex& h2);
	int& operator[](const int index);
	const int& operator[](const int index) const;
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