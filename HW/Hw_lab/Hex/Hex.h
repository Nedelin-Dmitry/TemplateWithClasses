#pragma once
// Copyright Nedelin-Dmitry 2022
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

// 0123456789 A  B  C  D  E  F
// 0123456789 10 11 12 13 14 15
#pragma once

#define ASKII_0 48
#define ASKII_9 57
#define ASKII_A_55 55  // A(65) in ASKII = 10 in decimal system;  55 + 10 = 65 
#define ASKII_A_START 65
#define ASKII_F_END 70
#define ASKII_F 70
#define POTENSIAL_MAS_SIZE 30
#define ASKII_MINUS 45

#include<iostream>
#include<cstring> 
#include <string>
#include<cstdlib>
#include<sstream>
#include<fstream>
#include<cmath>

class Hex {
 private:
    int size;
    unsigned char* num;
    int num_int;
  public:
    Hex();  // by default
    explicit Hex(std::string vvod);  // type conversion
    explicit  Hex(int _num_int);  // type conversion
    Hex(const Hex& copy);  // copying
    ~Hex();  // destructor

    // the output function for the Hex class
    friend void write(Hex& h1);  // bugurt cpplint on the absence of const

    // getters
    int get_size();
    int get_int();
    char get_char_i(int i);
    // operators 
    Hex operator=(const Hex& h1);
    friend Hex operator+(const Hex& h1, const Hex& h2);
    friend Hex operator-(const Hex& h1, const Hex& h2);
    unsigned char& operator[](const unsigned char index);  // char
    const unsigned char& operator[](const unsigned char index) const;
    friend Hex operator*(const Hex& h1, const Hex& h2);
    friend Hex operator*(const Hex& h1, int input);

    // comparison operators
    friend bool operator>(const Hex& h1, const Hex& h2);
    friend bool operator<(const Hex& h1, const Hex& h2);
    friend bool operator>=(const Hex& h1, const Hex& h2);
    friend bool operator<=(const Hex& h1, const Hex& h2);
    friend bool operator!=(const Hex& h1, const Hex& h2);
    friend bool operator==(const Hex& h1, const Hex& h2);

    // input and output operators to the stream
    friend std::ostream& operator<<(std::ostream& out, const Hex& _str);
    friend std::istream& operator>>(std::istream& in, Hex& _str);
};
