#pragma once
// Copyright 2022 Nedelin-Dmitry
/*
Option 5. Time
Develop a Time class to work with time in a format represented as a triple hou,
min, sec.
The class must contain:
 all necessary constructors (including type conversions from a string of the form “12:24:35”
and a destructor;
 method of representing time as a string: “12:24:35”; - method => outside the class?
The following operations should be overloaded in the class:
 assignments;
 addition (and subtraction) of time with the number of seconds (overflow of the result "up"
or "down" should perform the transition to the next or previous day with
the "discard" of the number of days);
 comparison;
 input/output operation to the stream.
*/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cmath>

#define sec_per_day 86400  // number of seconds per day for calculation in plus & minus

class Time {
  private:
    int hour, min, sec;  // time variables
  public:
    // Constructors
    Time();  // default constructor
    Time(std::string time_str);  // translating from a character string to an int value
    Time(int _hour, int _min, int _sec);  // constructor with parameters with specified time parameters
    Time(const Time& t_copy);  // copy constructor
    ~Time();
    // getters
    int get_hour() const { return hour; }
    int get_min() const { return min; }
    int get_sec() const { return sec; }
     // operator overloading
    Time operator+(const Time t1);  // addition
    Time operator-(const Time& t2);  // subtraction
    Time operator=(const Time& as_ent);
    friend bool operator==(const Time& t3, const Time& t4);  // comparison operations
    friend bool operator!=(const Time& t13, const Time& t14);
    friend bool operator<(const Time& t23, const Time& t24);
    friend bool operator>(const Time& t33, const Time& t34);
    friend bool operator<=(const Time& t43, const Time& t44);
    friend bool operator>=(const Time& t53, const Time& t54);
    friend std::ostream& operator<<(std::ostream& out, const Time& time);  // conclusion
    friend std::istream& operator>>(std::istream& in, Time& time);  // input
};


