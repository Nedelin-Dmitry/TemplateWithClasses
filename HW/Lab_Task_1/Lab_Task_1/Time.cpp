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

// if (h > 23 || min > 59 || sec > 59 || h < 0 || min < 0 || sec < 0) std:cout << "Input error! Try again";
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

	friend bool operator==(const Time& t3, const Time& t4); // операция сравнения
	friend std::ostream& operator<<(std::ostream& out, const Time& time); // вывод
	friend std::istream& operator>>(std::istream& in, Time& time); // ввод

};

bool operator==(const Time& t3, const Time& t4) // сравнение
{
	return (t3.hour == t4.hour && t3.min == t4.min && t3.sec == t4.sec);
}

std::ostream& operator<<(std::ostream& out, const Time& time) // вывод  
{
	out << time.hour << ":" << time.min << ":" << time.sec;

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
	Time copy = Time(19, 45, 29);
	std::cout << "Time is : " << copy << std::endl;
	std::cout << "Time is : " << defolt << std::endl;
	defolt = Time(copy);
	std::cout << "Time is : " << defolt << std::endl;

	std::cout << std::endl;

	//Ввод переменной
	std::cout << "Enter the time in the format hours, minuts, seconds - (9 12 13)" << std::endl;
	Time for_input;
	std::cin >> for_input;
	std::cout << "You entered: " << for_input << std::endl;
	/*
		Не успеваю сделать защиту от дурака, не душите сильно, пожалуйста
		Её можно сделать через цикл while()
		while(true)
			if (hour < 24 && min < 60 && sec < 60 && hour > -1 && min > -1 && sec > -1) - тут для сравнения нужны будут геттеры отдельных трёх переменных hour, min, sec
			{
				break;
			}
			else
			{
				std::cout << "Input error, try again"
			}
	*/

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
	// operation ==
	std::cout << "a is: " << f_pluz << " b is: " << minuzzd << std::endl;
	bool bad = f_pluz == minuzzd;
	std::cout << "a = b ? " << bad << std::endl;

	std::cout << std::endl;

	std::cout << "a is: " << defolt << " b is: " << copy << std::endl;
	bool good = defolt == copy; //
	std::cout << "a = b ? " << good << std::endl;


	return 0;
}