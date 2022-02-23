/*
Вариант 5. Время
Разработать класс Time для работы с временем в формате, представленным в виде тройки hou,
min, sec.
Класс должен содержать:
 ???все необходимые конструкторы??? (включая преобразования типа из строки вида “12:24:35” 
и деструктор;
 метод представления времени в виде строки: “12:24:35”;
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
using std::string;
// if (h > 23 || min > 59 || sec > 59 || h < 0 || min < 0 || sec < 0) std:cout << "Input error! Try again";
class Time
{
private:
	int hour, min, sec;
	string str = "";
public:
	Time();
	Time(int _hour, int _min, int _sec);
	Time(const Time& get); // skip
	Time(std::string time_str);
	~Time();

	void Time_print();
	void Time_operation2(const Time& c2);
	void Time_operation3(int hour_, int min_, int sec_);
	void Time_operation4(int _hour, int _min, int _sec);
};