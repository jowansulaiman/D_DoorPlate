#include "DateTime.h"
#include <iostream>
#include <time.h>
#include <sstream>
#include <sys/timeb.h>
#include <string>
DateTime::_Time::_Time(int Sec, int Minute, int Hour) :m_Sec(Sec), m_Minute(Minute), m_Hour(Hour) { }
DateTime::_Time::~_Time(){  }

int DateTime::_Time::get_Hour() {
    return m_Hour;
}
int DateTime::_Time::get_Minute() {
    return m_Minute;
}
int DateTime::_Time::get_Second() {
    return m_Sec;
}

//End of class _Time ********************************************************************


DateTime::_Date::_Date(int Day, int Month, int Year) :  m_Day(Day), m_Month(Month),m_Year(Year) {}
DateTime::_Date::~_Date() {  }

int DateTime::_Date::get_Year() {
    return m_Year;
}
int DateTime::_Date::get_Month() {
    return m_Month;
}
int DateTime::_Date::get_Day() {
    return m_Day;
}

// End of class _Date ************************************************************************************************


DateTime::_DateTime::_DateTime(int day, int month, int year, int sec, int min, int hour) : _Date(day, month, year), _Time(sec, min, hour) { }
DateTime::_DateTime::~_DateTime(){ }

std::tuple <int, int, int> DateTime::_DateTime::get_Date() {
    return std::make_tuple(get_Day(), get_Month(), get_Year());
}

std::tuple <int, int, int> DateTime::_DateTime::get_Time() {
    return std::make_tuple(get_Hour(), get_Minute(), get_Second());
}






