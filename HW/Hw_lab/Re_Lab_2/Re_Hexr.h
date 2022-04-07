/*
5. Шестнадцатеричное число
Создать класс Hex для работы с беззнаковыми целыми шестнадцатеричными числами, используя
для представления числа массив из элементов типа unsigned char, каждый из которых является
шестнадцатеричной цифрой.Младшая цифра имеет меньший индекс.Размер массива задается
как аргумент конструктора.
Реализовать операции :
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
#pragma once

#include <cassert> // для assert();
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
	Hex(); // по умолчанию
	Hex(std::string vvod); // преобразование типа 
	Hex(const Hex& copy);// копирования
	~Hex();// деструктор

	friend int in_10_int(unsigned char _num[]);
	friend void int_in_char(Hex& h1);

	//геттеры

	int get_size();
	int get_int_i();
	char get_char_i(int i);

	// операторы 
	Hex operator=(const Hex& h1);
	friend Hex operator+(const Hex& h1, const Hex& h2);
	friend Hex operator-(const Hex& h1, const Hex& h2);
	unsigned char& operator[](const unsigned char index); // char
	const unsigned char& operator[](const unsigned char index) const;
	friend Hex operator*(const Hex& h1, const Hex& h2);
	friend Hex operator*(const Hex& h1, int input);

	// операторы сравнения

	friend bool operator>(Hex& h1, Hex& h2);
	friend bool operator<(Hex& h1, Hex& h2);
	friend bool operator>=(Hex& h1, Hex& h2);
	friend bool operator<=(Hex& h1, Hex& h2);
	friend bool operator!=(Hex& h1, Hex& h2);
	friend bool operator==(Hex& h1, Hex& h2);

	// операторы ввода и вывода в поток
	friend std::ostream& operator<<(std::ostream& out, const Hex& _str);
	friend std::istream& operator>>(std::istream& in, Hex& _str);

};
