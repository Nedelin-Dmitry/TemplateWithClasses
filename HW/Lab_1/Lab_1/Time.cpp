#include<iostream>
#include<string>
#include "Time.h"

Time::Time()
{
	hour = 12;
	min = 24;
	sec = 35;
}

Time::Time(int _hour, int _min, int _sec)
{
	hour = _hour;
	min = _min;
	sec = _sec;
}

/*
Time::Time(std::string time_str)
{
	hour += stoi(std:time_str, ???)
}
*/

Time::~Time()
{
	hour = 0;
	min = 0;
	sec = 0;
}

Time::Time_print()
{
	std::string hour = std::to_string(hour);
	std::string min = std::to_string(min);
	std::string sec = std::to_string(sec);
	if (hour >= 0 && hour < 10)
	{
		hour = "0" + hour;
	}
	if (min >= 0 && min < 10)
	{
		min = "0" + min;
	}
	if (sec >= 0 && sec < 10)
	{
		sec = "0" + sec;
	}
	std::string time_str = hour + ":" + min + ":" + sec;
	std::cout << "Time:" << time_str << endl;
}
Time::Time_operation3(int hour_, int min_, int sec_) //case
{
	if (hour + hour_ > 24)
	{
		hour_ = (hour + hour_) % 24;
	}
	if (min + min_ > 59)
	{
		hour += (min + min_) / 60;
		min_ = (min + min_) % 60;
	}
	if (sec + sec_ > 59)
	{
		min += (sec + sec_) / 60;
		sec_ = (sec + sec_) % 60;
	}
	sec = (hour + hour_) * 3600 + (min + min_) * 60 + (sec + sec_);
	if (sec > 86400)
	{
		sec -= 86400;
	}
	if (sec > 3599)
	{
		hour = (sec / 3600);
		sec -= hour * 3600;
	}
	if (sec > 59 && sec < 3599) 
	{
		min = (sec / 60);
		sec -= min * 60;
	}
}

Time::Time_operation4(int _hour, int _min, int _sec) //case
{
	if (hour + _hour > 24)
	{
		_hour = (hour + _hour) % 24;
	}
	if (min + _min > 59)
	{
		hour += (min + _min) / 60;
		_min = (min + _min) % 60;
	}
	if (sec + _sec > 59)
	{
		min += (sec + _sec) / 60;
		_sec = (sec + _sec) % 60;
	}
	sec = (hour + _hour) * 3600 + (min + _min) * 60 + (sec + _sec);
	if (sec > 86400)
	{
		sec -= 86400;
	}
	if (sec > 3599)
	{
		hour = (sec / 3600);
		sec -= hour * 3600;
	}
	if (sec > 59 && sec < 3599)
	{
		min = (sec / 60);
		sec -= min * 60;
	}
}
