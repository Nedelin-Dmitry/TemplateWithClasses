#include"Time.h"
// Copyright 2022 Nedelin-Dmitry

Time::Time() {  // default constructor
    hour = 0;
    min = 0;
    sec = 0;
}

Time::Time(std::string time_str) {  // translating from a character string to an int value
    hour = std::stoi(time_str.substr(0, 2));
    min = std::stoi(time_str.substr(3, 2));
    sec = std::stoi(time_str.substr(6, 2));
}

Time::Time(int _hour, int _min, int _sec) {  // constructor with parameters with specified time parameters
    hour = _hour;
    min = _min;
    sec = _sec;
}

Time::Time(const Time& t_copy) {  // copy constructor
    hour = t_copy.hour;
    min = t_copy.min;
    sec = t_copy.sec;
}

Time::~Time() {  // Useless because there is no dynamic memory allocation
    hour = 0;
    min = 0;
    sec = 0;
}

Time Time::operator+(const Time t1) {  // addition
    Time f_ret;
    // we add up hours with hours, etc., we translate everything into seconds
    f_ret.sec = (hour * 3600 + min * 60 + sec) + (t1.hour * 3600 + t1.min * 60 + t1.sec);
    while (sec >= sec_per_day) {  // In case of overflow "up" - 24 hours out of the sum of time
        f_ret.sec -= sec_per_day;
    }
    // If there is an untranslated clock in seconds, we translate it, then we remove the clock from the seconds value
    while (f_ret.sec > 3599) {
        f_ret.hour += 1;
        f_ret.sec = f_ret.sec - 3600;
    }
    // converting seconds into minutes with the subsequent removal of minutes, seconds is not necessary because it's just the remainder of hours and minutes
    while (f_ret.sec > 59 && f_ret.sec < 3600) {
        f_ret.min += 1;
        f_ret.sec = f_ret.sec - 60;
    }

    return f_ret;
    // the remaining seconds remain in sec
}

Time Time::operator-(const Time& t2) {  // subtraction
    Time f_ret2;
    f_ret2.sec = (hour * 3600 + min * 60 + sec) - (t2.hour * 3600 + t2.min * 60 + t2.sec);
    f_ret2.sec = abs(f_ret2.sec);
    /*
        Because in the TOR it is indicated "to discard the day", that is,
        there is no difference for us, the overflow is "up" or "down" - so we take the module from the difference
    */
    // In case of overflow "up" - 24 hours out of the sum of time
    while (sec >= sec_per_day) {
        f_ret2.sec -= sec_per_day;
    }
    // If there is an untranslated clock in seconds, we translate it, then we remove the clock from the seconds value
    while (f_ret2.sec > 3599) {
        f_ret2.hour += 1;
        f_ret2.sec = f_ret2.sec - 3600;
    }
    // converting seconds into minutes with the subsequent removal of minutes
    // seconds is not necessary because it's just the remainder of hours and minutes
    while (f_ret2.sec > 59 && f_ret2.sec < 3600) {
        f_ret2.min += 1;
        f_ret2.sec = f_ret2.sec - 60;
    }

    return f_ret2;
    // the remaining seconds remain in sec
}

Time Time::operator=(const Time& as_ent) {
    if (this != &as_ent) {
        hour = as_ent.hour;
        min = as_ent.min;
        sec = as_ent.sec;
    }

    return *this;
}


bool operator==(const Time& t3, const Time& t4) {
    return (t3.hour == t4.hour && t3.min == t4.min && t3.sec == t4.sec);
}

bool operator!=(const Time& t13, const Time& t14) {
    return !(t13.hour == t14.hour && t13.min == t14.min && t13.sec == t14.sec);
}

bool operator<(const Time& t23, const Time& t24) {
    return (t23.hour < t24.hour&& t23.min < t24.min&& t23.sec < t24.sec);
}

bool operator>(const Time& t33, const Time& t34) {
    return (t33.hour > t34.hour && t33.min > t34.min && t33.sec > t34.sec);
}

bool operator<=(const Time& t43, const Time& t44) {
    return (t43.hour <= t44.hour && t43.min <= t44.min && t43.sec <= t44.sec);
}

bool operator>=(const Time& t53, const Time& t54) {
    return (t53.hour >= t54.hour && t53.min >= t54.min && t53.sec >= t54.sec);
}

std::ostream& operator<<(std::ostream& out, const Time& time) {  // conclusion  
    if (time.hour < 10 && time.hour > -1) {
        out << ":0" << time.hour;
    } else {
        out << time.hour;
    }
    if (time.min < 10 && time.min > -1) {
        out << ":0" << time.min;
    } else {
        out << ":" << time.min;
    }
    if (time.sec < 10 && time.sec > -1) {
        out << ":0" << time.sec;
    } else {
        out << ":" << time.sec;
    }

    return out;
}

// input ; enter must be non-constant to be able to change the members of the class
std::istream& operator>>(std::istream& in, Time& enter) {
    in >> enter.hour;
    in >> enter.min;
    in >> enter.sec;

    return in;
}