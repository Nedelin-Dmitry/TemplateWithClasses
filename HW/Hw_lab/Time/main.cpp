#include<iostream>
#include"Time.h"

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