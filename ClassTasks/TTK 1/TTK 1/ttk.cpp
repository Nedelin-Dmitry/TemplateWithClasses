/*
Самостоятельная работа вер.2

До конца пары, иначе -1.

Постановка задачи.
Реализовать класс Вес (Weight).
Класс должен уметь работать с весами в килограммах(1000 грамм), граммах, фунтах(453 грама).

Требования.
1. Не хранить все 3 веса. В качестве поля использовать только то, что считается общепризнанной мерой массы
в системе СИ - граммы.
2. Минимальный набор функций:
- базовые конструкторы: конструктор по умолчанию, конструктор инициализации;
- конструкторы преобразования типа: из килограммов, из фунтов; 
- перегрузки основных арифметических операторов:
	-(к весу можно прибавлять веса, фунты, килограммы, граммы),
	+= (из расстояния можно вычитать веса, фунты, килограммы, граммы),
	* на число;
- перегрузка оператора присваивания =;
- перегрузка операторов сравнения двух весов: ==, !=, >, <, >=, <=;
- функции to_pounds(), to_kilograms() для перевода расстояний к указанным типам;
- вывод на экран (метод или перегрузка оператора <<).

Подсказки.
1. Для удобства работы можно реализовать структуры/классы pounds_t, kilograms_t, grams_t.

*/

#include<iostream>
#include<string>
#include<cstdlib>

struct pounds_t // ???
{
	double pd_t;
};

struct kilograms_t
{
	double kg_t;
};

struct grams_t
{
	double gm;
};
//

class Weight
{
private:
	grams_t gr;
public:
	Weight()
	{
		gr.gm = 0;
	}
/*
	Weight(double ves, char a) // a = 1 - кг ; a = 2 - фунты;
	{
		if (a == '1') 
		{
			gramm = gramm + (ves * 1000);
		}
		else if (a == '2')
		{
			gramm = gramm + (ves * 453);
		}
		else
		{
			std::cout << "Error" << std::endl;
		}
	}
*/

	Weight(pounds_t ves)
	{
		gr.gm = ves.pd_t * 453;
	}

	Weight(kilograms_t ves)
	{
		gr.gm = ves.kg_t * 1000;
	}

	Weight(grams_t ves)
	{
		gr.gm = ves.gm;
	}

	friend Weight operator+(pounds_t c11, pounds_t c12);
	friend Weight operator+(kilograms_t c21, kilograms_t c22);
	friend Weight operator+(grams_t c31, grams_t c32);
	friend Weight operator-(pounds_t c11, pounds_t c12);
	friend Weight operator-(kilograms_t c21, kilograms_t c22);
	friend Weight operator-(grams_t c31, grams_t c32);
	friend Weight operator*(pounds_t c11, double a);
	friend Weight operator*(kilograms_t c21, double a);
	friend Weight operator*(grams_t c31, double a);

	Weight operator=(const Weight& w3)
	{
		if (this != &w3) 
		{
			gr.gm = w3.gr.gm;
		}
		return *this;
	}


	friend double to_pounds(const double gramm);
	friend double to_kilograms(const double gramm);
	//- перегрузка операторов сравнения двух весов: ==, !=, >, <, >=, <=;
	friend bool operator==(const Weight& w14, const Weight& w15);
	friend bool operator!=(const Weight& w24, const Weight& w25);
	friend bool operator>(const Weight& w34, const Weight& w35);
	friend bool operator<(const Weight& w44, const Weight& w45);
	friend bool operator>=(const Weight& w54, const Weight& w55);
	friend bool operator<=(const Weight& w64, const Weight& w65);
	friend std::ostream& operator<<(std::ostream& out, const Weight& w7);
};


Weight operator+(pounds_t c11, pounds_t c12)
{
	Weight f_ret_1;
	f_ret_1.gr.gm = (c11.pd_t + c12.pd_t) * 453;
	return f_ret_1;
}

Weight operator+(kilograms_t c21, kilograms_t c22)
{
	Weight f_ret_1;
	f_ret_1.gr.gm = (c21.kg_t + c22.kg_t) * 1000;
	return f_ret_1;
}

Weight operator+(grams_t c31, grams_t c32)
{
	Weight f_ret_1;
	f_ret_1.gr.gm = (c31.gm + c32.gm);
	return f_ret_1;
}

Weight operator-(pounds_t c11, pounds_t c12)
{
	Weight f_ret_1;
	f_ret_1.gr.gm = (c11.pd_t - c12.pd_t) * 453;
	return f_ret_1;

}
Weight operator-(kilograms_t c21, kilograms_t c22)
{
	Weight f_ret_1;
	f_ret_1.gr.gm = (c21.kg_t - c22.kg_t) * 1000;
	return f_ret_1;

}
Weight operator-(grams_t c31, grams_t c32)
{
	Weight f_ret_1;
	f_ret_1.gr.gm = (c31.gm - c32.gm);
	return f_ret_1;

}
Weight operator*(pounds_t c11, double a)
{
	Weight for_ret;
	for_ret.gr.gm = (c11.pd_t * a) * 453;
	return for_ret;
}

Weight operator*(kilograms_t c21, double a)
{
	Weight for_ret;
	for_ret.gr.gm = (c21.kg_t * a) * 1000;
	return for_ret;
}

Weight operator*(grams_t c31, double a)
{
	Weight for_ret;
	for_ret.gr.gm = c31.gm * a;
	return for_ret;
}


double to_pounds(const double gramm)
{
	pounds_t a;
	a.pd_t = gramm / 453;
	return a.pd_t;
}

double to_kilograms(const double gramm)
{
	kilograms_t b;
	b.kg_t = gramm / 1000;
	return b.kg_t;
}

bool operator==(const Weight& w14, const Weight& w15)
{
	return (w14.gr.gm == w15.gr.gm);
}

bool operator!=(const Weight& w24, const Weight& w25)
{
	return !(w24.gr.gm == w25.gr.gm);
}

bool operator>(const Weight& w34, const Weight& w35)
{
	return (w34.gr.gm > w35.gr.gm);
}

bool operator<(const Weight& w44, const Weight& w45)
{
	return (w44.gr.gm < w45.gr.gm);
}

bool operator>=(const Weight& w54, const Weight& w55)
{
	return (w54.gr.gm >= w55.gr.gm);
}

bool operator<=(const Weight& w64, const Weight& w65)
{
	return (w64.gr.gm <= w65.gr.gm);
}

std::ostream& operator<<(std::ostream& out, const Weight& w7)
{
	out << "Weight in gramm: " << w7.gr.gm << std::endl;
	out << "Weight in kilogram: " << to_kilograms(w7.gr.gm) << std::endl;
	out << "Weight in pounds: " << to_pounds(w7.gr.gm) << std::endl;
	return out;
}

int main()
{
	return 0;
}