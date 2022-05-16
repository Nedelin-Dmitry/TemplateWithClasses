#include<iostream>
#include"Time.h"
using namespace std;
// Copyright 2022 Nedelin-Dmitry

int main() {
    //по умолчанию
    Time defolt = Time();
    cout << "Time is : " << defolt << endl;
    // преобразование строки в параметры времени
    string a = "12:54:23";
    Time strng_time = Time(a);
    cout << "Time is : " << strng_time << endl;  // перегрузка вывода
    cout << endl;
    // Копирование и конструктор с задаными параметрами
    Time f_copy = Time();
    Time copy = Time(19, 45, 29);
    cout << "Time is : " << copy << endl;
    cout << "Time is : " << f_copy << endl;
    f_copy = Time(copy);
    cout << "Time is : " << f_copy << endl;
    cout << endl;
    //Ввод переменной
    cout << "Enter the time in the format hours, minuts, seconds - (9 12 13)" 
    << endl;
    Time for_input;
    while (1) {
        cin >> for_input;
        if (for_input.get_hour() > -1 && for_input.get_hour() < 24 && for_input.get_min() > -1 && for_input.get_min() < 60 && for_input.get_sec() > -1 && for_input.get_sec() < 60) {
            break;
        }
        else {
            cout << "Input error, try again" << endl;
        }
    }
    cout << "You entered: " << for_input << endl;
    cout << endl;

    // operator +
    cout << "Plus : a + b" << endl;
    cout << "a: " << defolt << endl;
    Time f_pluz = Time(3, 10, 10);
    cout << "b: " << f_pluz << :endl;
    Time pluzzd = defolt + f_pluz;
    cout << "a + b :" << pluzzd << endl;
    cout << endl;

    // operator -
    cout << "Minus : a - b" << endl;
    cout << "a: " << pluzzd << endl;
    cout << "b: " << f_pluz << endl;
    Time minuzzd = pluzzd - f_pluz;
    cout << "a - b:" << minuzzd << endl;
    cout << endl;

    // operator =
    cout << "copy is: " << copy << endl;
    Time ravno = copy;
    cout << "ravno is: " << ravno << endl;
    cout << endl;
    cout << "Comparison operators" << endl;
    Time bolshe = Time(10, 10, 10);
    Time menshe = Time(1, 1, 1);
    cout << "a is: " << bolshe << endl;
    cout << "b is: " << menshe << endl;
    cout << endl;

    // operation ==
    bool good1 = bolshe == bolshe;
    cout << "a = a? " << good1 << endl;
    bool bad1 = bolshe == menshe;
    cout << "a = b? " << bad1 << endl;
    cout << endl;

    // operator <=
    bool good2 = bolshe <= menshe;
    cout << "a <= b? " << good2 << endl;
    bool bad2 = menshe <= bolshe;
    cout << "b <= a? " << bad2 << endl;
    cout << endl;

    // operator >=

    bool good3 = bolshe >= menshe;
    cout << "a >= b? " << good3 << endl;
    bool bad3 = menshe >= bolshe;
    cout << "b >= a? " << bad3 << endl;
    cout << endl;

    // operator >

    bool good4 = bolshe > menshe;
    cout << "a > b? " << good3 << endl;
    bool bad4 = menshe > bolshe;
    cout << "b > a? " << bad3 << endl;
    cout << endl;

    // operator <
    bool good5 = bolshe < menshe;
    cout << "a < b? " << good5 << endl;
    bool bad5 = menshe < bolshe;
    cout << "b < a? " << bad5 << endl;
    cout << endl;


    // operator !=
    bool good6 = bolshe != menshe;
    cout << "a != b? " << good6 << endl;
    bool bad6 = menshe != menshe;
    cout << "b != b? " << bad6 << endl;
    cout << endl;


    return 0;
}