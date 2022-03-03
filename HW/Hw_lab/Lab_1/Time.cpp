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
	Time()// конструктор по умолчанию
	{
		hour = 0;
		min = 0;
		sec = 0;
	};

	Time(std::string time_str) // перевод из символьной строки в int значения
	{
		hour = std::stoi(time_str.substr(0, 2));
		min = std::stoi(time_str.substr(3, 2));
		sec = std::stoi(time_str.substr(6, 2));

	}

	Time(int _hour, int _min, int _sec)// конструктор с параметрами с задаными параметрами времени
	{
		hour = _hour;
		min = _min;
		sec = _sec;
	}

	Time(const Time& t_copy) // конструктор копирования
	{
		hour = t_copy.hour;
		min = t_copy.min;
		sec = t_copy.sec;
	}

	~Time() // Бесполезен т.к нет динамического выделения памяти
	{
		hour = 0;
		min = 0;
		sec = 0;
	}

	int get_hour() const { return hour; };
	int get_min() const { return min; };
	int get_sec() const { return sec; };

	Time operator+(const Time t1) // сложение
	{
		Time f_ret;
		f_ret.sec = (hour * 3600 + min * 60 + sec) + (t1.hour * 3600 + t1.min * 60 + t1.sec); // складываем часы с часами и т.д, всё переводим в секунды
		while (sec >= sec_per_day) // В случае переполнения "вверх" - 24 часа из суммы времени
		{
			f_ret.sec -= sec_per_day;
		}
		while (f_ret.sec > 3599) // Если в секундах есть непереведённые часы - переводим, после убираем часы из значения секунд
		{
			f_ret.hour += 1;
			f_ret.sec = f_ret.sec - 3600;
		}
		while (f_ret.sec > 59 && f_ret.sec < 3600) // перевод секунд в минуты с последующим удалением минут, секунды нет необходимости т.к это просто остаток от часов и минут
		{
			f_ret.min += 1;
			f_ret.sec = f_ret.sec - 60;
		}

		return f_ret;
		// оставшиеся секунды остаются в sec
	}

	Time operator-(const Time& t2) // вычитание
	{
		Time f_ret2;
		f_ret2.sec = (hour * 3600 + min * 60 + sec) - (t2.hour * 3600 + t2.min * 60 + t2.sec);
		f_ret2.sec = abs(f_ret2.sec);
		/*
			Т.к в ТЗ указанно "отбрасывать сутки", то-есть для нас нет разницы переполнение "вверх" или "вниз" - значит берём модуль от разницы
		*/
		while (sec >= sec_per_day) // В случае переполнения "вверх" - 24 часа из суммы времени
		{
			f_ret2.sec -= sec_per_day;
		}
		while (f_ret2.sec > 3599) // Если в секундах есть непереведённые часы - переводим, после убираем часы из значения секунд
		{
			f_ret2.hour += 1;
			f_ret2.sec = f_ret2.sec - 3600;
		}
		while (f_ret2.sec > 59 && f_ret2.sec < 3600) // перевод секунд в минуты с последующим удалением минут, секунды нет необходимости т.к это просто остаток от часов и минут
		{
			f_ret2.min += 1;
			f_ret2.sec = f_ret2.sec - 60;
		}

		return f_ret2;
		// оставшиеся секунды остаются в sec
	}
	Time operator=(const Time& as_ent)
	{
		if (this != &as_ent)
		{
			hour = as_ent.hour;
			min = as_ent.min;
			sec = as_ent.sec;
		}

		return *this;
	}

	friend bool operator==(const Time& t3, const Time& t4); // операции сравнения
	friend bool operator!=(const Time& t13, const Time& t14);
	friend bool operator<(const Time& t23, const Time& t24);
	friend bool operator>(const Time& t33, const Time& t34);
	friend bool operator<=(const Time& t43, const Time& t44);
	friend bool operator>=(const Time& t53, const Time& t54);
	friend std::ostream& operator<<(std::ostream& out, const Time& time); // вывод
	friend std::istream& operator>>(std::istream& in, Time& time); // ввод

};

bool operator==(const Time& t3, const Time& t4) //const? сравнение
{
	return (t3.hour == t4.hour && t3.min == t4.min && t3.sec == t4.sec);
}

bool operator!=(const Time& t13, const Time& t14)
{
	return !(t13.hour == t14.hour && t13.min == t14.min && t13.sec == t14.sec);
}

bool operator<(const Time& t23, const Time& t24)
{
	return (t23.hour < t24.hour&& t23.min < t24.min&& t23.sec < t24.sec);
}

bool operator>(const Time& t33, const Time& t34)
{
	return (t33.hour > t34.hour && t33.min > t34.min && t33.sec > t34.sec);
}
bool operator<=(const Time& t43, const Time& t44)
{
	return (t43.hour <= t44.hour && t43.min <= t44.min && t43.sec <= t44.sec);
}

bool operator>=(const Time& t53, const Time& t54)
{
	return (t53.hour >= t54.hour && t53.min >= t54.min && t53.sec >= t54.sec);
}

std::ostream& operator<<(std::ostream& out, const Time& time) // вывод  
{
	if (time.hour < 10 && time.hour > -1)
	{
		out << ":0" << time.hour;
	}
	else
	{
		out << time.hour;
	}
	if (time.min < 10 && time.min > -1)
	{
		out << ":0" << time.min;
	}
	else
	{
		out << ":" << time.min;
	}
	if (time.sec < 10 && time.sec > -1)
	{
		out << ":0" << time.sec;
	}
	else
	{
		out << ":" << time.sec;
	}

	return out;
}
std::istream& operator>>(std::istream& in, Time& enter) // ввод ; enter должен быть неконстантный, чтобы была возможность изменить члены класса
{
	in >> enter.hour;
	in >> enter.min;
	in >> enter.sec;

	return in;

}

int main()
{
	//по умолчанию
	Time defolt = Time();
	std::cout << "Time is : " << defolt << std::endl; // Доработать для формата 00:00:00
	// преобразование строки в параметры времени
	std::string a = "12:54:23";
	Time strng_time = Time(a);
	std::cout << "Time is : " << strng_time << std::endl; // перегрузка вывода

	std::cout << std::endl;

	// Копирование и конструктор с задаными параметрами
	Time f_copy = Time();
	Time copy = Time(19, 45, 29);
	std::cout << "Time is : " << copy << std::endl;
	std::cout << "Time is : " << f_copy << std::endl;
	f_copy = Time(copy);
	std::cout << "Time is : " << f_copy << std::endl;

	std::cout << std::endl;

	//Ввод переменной
	std::cout << "Enter the time in the format hours, minuts, seconds - (9 12 13)" << std::endl;
	Time for_input;
	while (1)
	{
		std::cin >> for_input;
		if (for_input.get_hour() > -1 && for_input.get_hour() < 24 && for_input.get_min() > -1 && for_input.get_min() < 60 && for_input.get_sec() > -1 && for_input.get_sec() < 60)
		{
			break;
		}
		else
		{
			std::cout << "Input error, try again" << std::endl;
		}
	}
	std::cout << "You entered: " << for_input << std::endl;

	std::cout << std::endl;

	// operator +
	std::cout << "Plus : a + b" << std::endl;
	std::cout << "a: " << defolt << std::endl;
	Time f_pluz = Time(3, 10, 10);
	std::cout << "b: " << f_pluz << std::endl;
	Time pluzzd = defolt + f_pluz;
	std::cout << "a + b :" << pluzzd << std::endl;

	std::cout << std::endl;

	//operator -
	std::cout << "Minus : a - b" << std::endl;
	std::cout << "a: " << pluzzd << std::endl;
	std::cout << "b: " << f_pluz << std::endl;
	Time minuzzd = pluzzd - f_pluz;
	std::cout << "a - b:" << minuzzd << std::endl;

	std::cout << std::endl;

	//operator =

	std::cout << "copy is: " << copy << std::endl;
	Time ravno = copy;
	std::cout << "ravno is: " << ravno << std::endl;

	std::cout << std::endl;

	std::cout << "Comparison operators" << std::endl;
	Time bolshe = Time(10, 10, 10);
	Time menshe = Time(1, 1, 1);
	std::cout << "a is: " << bolshe << std::endl;
	std::cout << "b is: " << menshe << std::endl;


	std::cout << std::endl;
	// operation ==
	bool good1 = bolshe == bolshe;
	std::cout << "a = a? " << good1 << std::endl;
	bool bad1 = bolshe == menshe;
	std::cout << "a = b? " << bad1 << std::endl;
	std::cout << std::endl;

	// operator <=

	bool good2 = bolshe <= menshe;
	std::cout << "a <= b? " << good2 << std::endl;
	bool bad2 = menshe <= bolshe;
	std::cout << "b <= a? " << bad2 << std::endl;
	std::cout << std::endl;

	// operator >=

	bool good3 = bolshe >= menshe;
	std::cout << "a >= b? " << good3 << std::endl;
	bool bad3 = menshe >= bolshe;
	std::cout << "b >= a? " << bad3 << std::endl;
	std::cout << std::endl;

	// operator >

	bool good4 = bolshe > menshe;
	std::cout << "a > b? " << good3 << std::endl;
	bool bad4 = menshe > bolshe;
	std::cout << "b > a? " << bad3 << std::endl;
	std::cout << std::endl;

	// operator <
	bool good5 = bolshe < menshe;
	std::cout << "a < b? " << good5 << std::endl;
	bool bad5 = menshe < bolshe;
	std::cout << "b < a? " << bad5 << std::endl;
	std::cout << std::endl;


	// operator !=
	bool good6 = bolshe != menshe;
	std::cout << "a != b? " << good6 << std::endl;
	bool bad6 = menshe != menshe;
	std::cout << "b != b? " << bad6 << std::endl;
	std::cout << std::endl;


	return 0;
}