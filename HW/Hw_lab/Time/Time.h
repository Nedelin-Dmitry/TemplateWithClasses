#pragma once
/*
Вариант 5. Время
Разработать класс Time для работы с временем в формате, представленным в виде тройки hou,
min, sec.
Класс должен содержать:
 все необходимые конструкторы (включая преобразования типа из строки вида “12:24:35”
и деструктор;
 метод представления времени в виде строки: “12:24:35”; - метод => за пределами класса?
В классе должны быть перегружены операции:
 присваивания;
 сложения (и вычитания) времени с количеством секунд (переполнение результата «вверх»
или «вниз» должно выполнять переход на следующие или предыдущие сутки с
«отбрасываем» количества суток );
 сравнения;
 операция ввода/вывода в поток.
*/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cmath>

#define sec_per_day 86400 // кол-во секунд в сутках для расчёта в plus & minus

class Time
{
private:
	int hour, min, sec; // переменные времени
public:
	// Конструкторы
	Time();// конструктор по умолчанию
	Time(std::string time_str); // перевод из символьной строки в int значения
	Time(int _hour, int _min, int _sec);// конструктор с параметрами с задаными параметрами времени
	Time(const Time& t_copy); // конструктор копирования
	~Time(); // Бесполезен т.к нет динамического выделения памяти

	// геттеры
	int get_hour() const { return hour; };
	int get_min() const { return min; };
	int get_sec() const { return sec; };

	// перегрузка операторов
	Time operator+(const Time t1); // сложение
	Time operator-(const Time& t2); // вычитание
	Time operator=(const Time& as_ent);

	friend bool operator==(const Time& t3, const Time& t4); // операции сравнения
	friend bool operator!=(const Time& t13, const Time& t14);
	friend bool operator<(const Time& t23, const Time& t24);
	friend bool operator>(const Time& t33, const Time& t34);
	friend bool operator<=(const Time& t43, const Time& t44);
	friend bool operator>=(const Time& t53, const Time& t54);
	friend std::ostream& operator<<(std::ostream& out, const Time& time); // вывод
	friend std::istream& operator>>(std::istream& in, Time& time); // ввод

};


