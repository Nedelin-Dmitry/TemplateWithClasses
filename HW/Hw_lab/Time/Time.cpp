#include"Time.h"
// Copyright 2022 Nedelin-Dmitry

Time::Time(){  // конструктор по умолчанию
    hour = 0;
    min = 0;
    sec = 0;
};

Time::Time(std::string time_str){  // перевод из символьной строки в int значени€
    hour = std::stoi(time_str.substr(0, 2));
    min = std::stoi(time_str.substr(3, 2));
    sec = std::stoi(time_str.substr(6, 2));

}

Time::Time(int _hour, int _min, int _sec){  // конструктор с параметрами с задаными параметрами времени
    hour = _hour;
    min = _min;
    sec = _sec;
}

Time::Time(const Time& t_copy){  // конструктор копировани€
    hour = t_copy.hour;
    min = t_copy.min;
    sec = t_copy.sec;
}

Time::~Time(){  // Ѕесполезен т.к нет динамического выделени€ пам€ти
    hour = 0;
    min = 0;
    sec = 0;
}

Time Time::operator+(const Time t1){  // сложение
    Time f_ret;
    f_ret.sec = (hour * 3600 + min * 60 + sec) + (t1.hour * 3600 + t1.min * 60 + t1.sec);  // складываем часы с часами и т.д, всЄ переводим в секунды
    while (sec >= sec_per_day){  // ¬ случае переполнени€ "вверх" - 24 часа из суммы времени
        f_ret.sec -= sec_per_day;
    }
    while (f_ret.sec > 3599){  // ≈сли в секундах есть непереведЄнные часы - переводим, после убираем часы из значени€ секунд
        f_ret.hour += 1;
        f_ret.sec = f_ret.sec - 3600;
    }
    while (f_ret.sec > 59 && f_ret.sec < 3600){  // перевод секунд в минуты с последующим удалением минут, секунды нет необходимости т.к это просто остаток от часов и минут
        f_ret.min += 1;
        f_ret.sec = f_ret.sec - 60;
    }

    return f_ret;
    // оставшиес€ секунды остаютс€ в sec
}

Time Time::operator-(const Time& t2){  // вычитание
    Time f_ret2;
    f_ret2.sec = (hour * 3600 + min * 60 + sec) - (t2.hour * 3600 + t2.min * 60 + t2.sec);
    f_ret2.sec = abs(f_ret2.sec);
    /*
        “.к в “« указанно "отбрасывать сутки", то-есть дл€ нас нет разницы переполнение "вверх" или "вниз" - значит берЄм модуль от разницы
    */
    while (sec >= sec_per_day){  // ¬ случае переполнени€ "вверх" - 24 часа из суммы времени
        f_ret2.sec -= sec_per_day;
    }
    while (f_ret2.sec > 3599){  // ≈сли в секундах есть непереведЄнные часы - переводим, после убираем часы из значени€ секунд
        f_ret2.hour += 1;
        f_ret2.sec = f_ret2.sec - 3600;
    }
    while (f_ret2.sec > 59 && f_ret2.sec < 3600){  // перевод секунд в минуты с последующим удалением минут, секунды нет необходимости т.к это просто остаток от часов и минут
        f_ret2.min += 1;
        f_ret2.sec = f_ret2.sec - 60;
    }

    return f_ret2;
    // оставшиес€ секунды остаютс€ в sec
}

Time Time::operator=(const Time& as_ent){
    if (this != &as_ent){
        hour = as_ent.hour;
        min = as_ent.min;
        sec = as_ent.sec;
    }

    return *this;
}


bool operator==(const Time& t3, const Time& t4){  //const? сравнение
    return (t3.hour == t4.hour && t3.min == t4.min && t3.sec == t4.sec);
}

bool operator!=(const Time& t13, const Time& t14){
    return !(t13.hour == t14.hour && t13.min == t14.min && t13.sec == t14.sec);
}

bool operator<(const Time& t23, const Time& t24){
    return (t23.hour < t24.hour&& t23.min < t24.min&& t23.sec < t24.sec);
}

bool operator>(const Time& t33, const Time& t34){
    return (t33.hour > t34.hour && t33.min > t34.min && t33.sec > t34.sec);
}

bool operator<=(const Time& t43, const Time& t44){
    return (t43.hour <= t44.hour && t43.min <= t44.min && t43.sec <= t44.sec);
}

bool operator>=(const Time& t53, const Time& t54){
    return (t53.hour >= t54.hour && t53.min >= t54.min && t53.sec >= t54.sec);
}

std::ostream& operator<<(std::ostream& out, const Time& time){  // вывод  
    if (time.hour < 10 && time.hour > -1){
        out << ":0" << time.hour;
    }
    else{
        out << time.hour;
    }
    if (time.min < 10 && time.min > -1){
        out << ":0" << time.min;
    }
    else{
        out << ":" << time.min;
    }
    if (time.sec < 10 && time.sec > -1){
        out << ":0" << time.sec;
    }
    else{
        out << ":" << time.sec;
    }

    return out;
}

std::istream& operator>>(std::istream& in, Time& enter){  // ввод ; enter должен быть неконстантный, чтобы была возможность изменить члены класса
    in >> enter.hour;
    in >> enter.min;
    in >> enter.sec;

    return in;

}