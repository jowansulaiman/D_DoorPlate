#include "DateTime.h"
#include <iostream>
#include <time.h>
#include <sstream>
#include <sys/timeb.h>
#include <string>

DateTime::_Time::_Time(long int Minute, long int Hour) :m_Minute(Minute), m_Hour(Hour) { }
DateTime::_Time::~_Time(){  }

long int 
DateTime::_Time::get_Hour() {
    return m_Hour;
}
long int 
DateTime::_Time::get_Minute() {
    return m_Minute;
}

bool 
DateTime::_Time::compare_local_Time(std::shared_ptr<_Time> _DT) {
    using namespace boost::posix_time;
    using namespace boost::gregorian;

    time_t now = time(0);
    tm* ltm = localtime(&now);
    date dt(1900, Feb, 01);

    ptime local_DateTime(dt, hours(ltm->tm_hour) + minutes(ltm->tm_min));
    ptime that_DateTime(dt, hours(_DT->get_Hour()) + minutes(_DT->get_Minute()));

    if (that_DateTime < local_DateTime)
        return false;
}

bool
DateTime::_Time::compare_Time(std::shared_ptr<_Time> _DT) {
    using namespace boost::posix_time;
    using namespace boost::gregorian;

    date dt(1900, Feb, 01);

    ptime this_Time(dt, hours(this->m_Hour) + minutes(this->m_Minute) );
    ptime that_Time(dt, hours(_DT->get_Hour()) + minutes(_DT->get_Minute()));

    if (this_Time < that_Time)
        return false;
}

std::string
DateTime::_Time::get_Time() {
    using namespace std;

    stringstream stream;
    stream << to_string(m_Hour) + ":" + to_string(m_Minute);

    return stream.str();
}


DateTime::_Time
DateTime::_Time::operator+(const _Time& _T) {
    unsigned  int add_Hour = this->m_Hour + _T.m_Hour;
    unsigned  int add_Minute = this->m_Minute + _T.m_Minute;


    _Time new_DateTime(add_Minute, add_Hour);

    _T.~_Time();
    new_DateTime.~_Time();

    return new_DateTime;
 }

DateTime::_Time
DateTime::_Time::operator -(const _Time& _T) {
    long  int add_Hour = this->m_Hour - _T.m_Hour;
    (add_Hour < 0) ? add_Hour = add_Hour * -1 : add_Hour = add_Hour * 1;

    long  int add_Minute = this->m_Minute - _T.m_Minute;
    (add_Minute < 0) ? add_Minute = add_Minute * -1 : add_Minute = add_Minute * 1;

    _Time new_DateTime(add_Minute, add_Hour);

    _T.~_Time();
    new_DateTime.~_Time();

    return new_DateTime;
}

bool
DateTime::_Time::operator >(_Time& _T) {
    using namespace boost::posix_time;
    using namespace boost::gregorian;

    date _date(1900, Feb, 01);

    ptime this_Time(_date, hours(this->m_Hour) + minutes(this->m_Minute) );
    ptime that_Time(_date, hours(_T.m_Hour) + minutes(_T.m_Minute) );

    _T.~_Time();

    return this_Time > that_Time;
}
bool 
DateTime::_Time::operator <(_Time& _T) {
    using namespace boost::posix_time;
    using namespace boost::gregorian;

    date _date(1900, Feb, 01);

    ptime this_Time(_date, hours(this->m_Hour) + minutes(this->m_Minute) );
    ptime that_Time(_date, hours(_T.m_Hour) + minutes(_T.m_Minute) );

    _T.~_Time();

    return this_Time < that_Time;

}

bool
DateTime::_Time::operator==(_Time& _T) {
    using namespace boost::posix_time;
    using namespace boost::gregorian;

    date _date(1900, Feb, 01);

    ptime this_Time(_date, hours(this->m_Hour) + minutes(this->m_Minute) );
    ptime that_Time(_date, hours(_T.m_Hour) + minutes(_T.m_Minute));

    _T.~_Time();

    return this_Time == that_Time;
}

bool
DateTime::_Time::operator!=(_Time& _T) {
    using namespace boost::posix_time;
    using namespace boost::gregorian;

    date _date(1900, Feb, 01);

    ptime this_Time(_date, hours(this->m_Hour) + minutes(this->m_Minute));
    ptime that_Time(_date, hours(_T.m_Hour) + minutes(_T.m_Minute) );

    _T.~_Time();

    return this_Time != that_Time;
}

//End of class _Time ********************************************************************


DateTime::_Date::_Date(long int Day, long int Month, long int Year) :  m_Day(Day), m_Month(Month),m_Year(Year) {}
DateTime::_Date::~_Date() {  }

long int 
DateTime::_Date::get_Year() {
    return m_Year;
}
long int
DateTime::_Date::get_Month() {
    return m_Month;
}
long int 
DateTime::_Date::get_Day() {
    return m_Day;
}
std::string
DateTime::_Date::get_Date() {
    using namespace std;
    
    stringstream stream;
    stream << to_string(m_Day) + "." + to_string(m_Month) + "." + to_string(m_Year);

    return stream.str();
}

bool
DateTime::_Date::compare_local_Date(std::shared_ptr<_Date> _DT) {
    using namespace boost::posix_time;
    using namespace boost::gregorian;
    time_t now = time(0);
    tm* ltm = localtime(&now);
    int y = ltm->tm_year + 1900;
    int mo = ltm->tm_mon + 1;

    ptime local_Date(date(y, mo, ltm->tm_mday));
    ptime that_Date(date(_DT->get_Year(), _DT->get_Month(), _DT->get_Day()));

    if (that_Date < local_Date)
        return false;
}
bool 
DateTime::_Date::compare_Date(std::shared_ptr<_Date> _DT) {
    using namespace boost::posix_time;
    using namespace boost::gregorian;
   
    ptime this_Date(date(this->m_Year, this->m_Month, this->m_Day));
    ptime that_Date(date(_DT->get_Year(), _DT->get_Month(), _DT->get_Day()));

    if (this_Date < that_Date)
        return false;
}
DateTime::_Date
DateTime::_Date::operator+(const _Date& _T) {
    //long int sub_year= this->m_Year - _T.m_Year;
    //(sub_year < 0) ? sub_year = sub_year * -1 : sub_year = sub_year * 1;
    long  int add_Year = this->m_Year + _T.m_Year;
    long  int add_Month = this->m_Month + _T.m_Month;
    long  int add_Day = this->m_Day + _T.m_Day;

    _Date new_DateTime(add_Day, add_Month, add_Year);

    _T.~_Date();
    new_DateTime.~_Date();

    return new_DateTime;
}

DateTime::_Date 
DateTime::_Date::operator -(const _Date& _T) {
    long  int add_Year = this->m_Year - _T.m_Year;
    (add_Year < 0) ? add_Year = add_Year * -1 : add_Year = add_Year * 1;

    long  int add_Month = this->m_Month - _T.m_Month;
    (add_Month < 0) ? add_Month = add_Month * -1 : add_Month = add_Month * 1;

    long  int add_Day = this->m_Day - _T.m_Day;
    (add_Day < 0) ? add_Day = add_Day * -1 : add_Day = add_Day * 1;

    _Date new_DateTime(add_Day, add_Month, add_Year);

    _T.~_Date();
    new_DateTime.~_Date();

    return new_DateTime;
}

bool  
DateTime::_Date::operator >(_Date& _T) {
    using namespace boost::posix_time;
    using namespace boost::gregorian;

    date this_Date(this->m_Year, this->m_Month, this->m_Day);
    date that_Date ( _T.m_Year , _T.m_Month , _T.m_Day);

    _T.~_Date();

    return this_Date > that_Date;
}
bool 
DateTime::_Date::operator <(_Date& _T) {
    using namespace boost::posix_time;
    using namespace boost::gregorian;

    date this_Date(this->m_Year, this->m_Month, this->m_Day);
    date that_Date(_T.m_Year, _T.m_Month, _T.m_Day);

    _T.~_Date();

    return this_Date < that_Date;
}

bool 
DateTime::_Date::operator==(_Date& _T) {
    using namespace boost::posix_time;
    using namespace boost::gregorian;

    date this_Date(this->m_Year, this->m_Month, this->m_Day);
    date that_Date(_T.m_Year, _T.m_Month, _T.m_Day);

    _T.~_Date();

    return this_Date == that_Date;
}
bool 
DateTime::_Date::operator!=(_Date& _T) {
    using namespace boost::posix_time;
    using namespace boost::gregorian;

    date this_Date(this->m_Year, this->m_Month, this->m_Day);
    date that_Date(_T.m_Year, _T.m_Month, _T.m_Day);

    _T.~_Date();

    return this_Date != that_Date;
}
// End of class _Date ************************************************************************************************


DateTime::_DateTime::_DateTime(long int day, long int month, long int year, long int min, long int hour) : _Date(day, month, year), _Time(min, hour) { }
DateTime::_DateTime::~_DateTime(){ }

bool 
DateTime::_DateTime::compare_local_DateTime(std::shared_ptr<_DateTime>  _DT) {
    if(compare_local_Date(_DT)==false || compare_local_Time(_DT)==false)
        return false;
}

DateTime::_DateTime
DateTime::_DateTime::operator+( _DateTime _T) {
    long  int add_Year = this->get_Year() + _T.get_Year();
    long int add_Month = this->get_Month() + _T.get_Month();
    long  int add_Day = this->get_Day() + _T.get_Day();

    long  int add_Hour = this->get_Hour() + _T.get_Hour();
    long  int add_Minute = this->get_Minute() + _T.get_Minute();
  
   _DateTime new_DateTime(add_Year, add_Month, add_Day, add_Hour,
       add_Minute);

    _T.~_DateTime();
    new_DateTime.~_DateTime();

    return new_DateTime;
}

DateTime::_DateTime 
DateTime::_DateTime::operator -( _DateTime _T) {
    long  int add_Year = this->get_Year() - _T.get_Year();
    (add_Year < 0) ? add_Year = add_Year * -1 : add_Year = add_Year * 1;

    long  int add_Month = this->get_Month()- _T.get_Month();
    (add_Month < 0) ? add_Month = add_Month * -1 : add_Month = add_Month * 1;

    long  int add_Day = this->get_Day() - _T.get_Day();
    (add_Day < 0) ? add_Day = add_Day * -1 : add_Day = add_Day * 1;

    long  int add_Hour = this->get_Hour() - _T.get_Hour();
    (add_Hour < 0) ? add_Hour = add_Hour * -1 : add_Hour = add_Hour * 1;

    long  int add_Minute = this->get_Minute() - _T.get_Minute();
    (add_Minute < 0) ? add_Minute = add_Minute * -1 : add_Minute = add_Minute * 1;
    
   

    _DateTime new_DateTime(add_Day, add_Month, add_Year, add_Minute, add_Hour);

    _T.~_DateTime();
    new_DateTime.~_DateTime();

    return new_DateTime;
}

bool  
DateTime::_DateTime::operator >(_DateTime& _T) {
    using namespace boost::posix_time;
    using namespace boost::gregorian;

    ptime this_DateTime(date(this->get_Year(), this->get_Month(), this->get_Day()), hours(this->get_Hour()) +
        minutes(this->get_Minute()));
    ptime that_DateTime(date(_T.get_Year(), _T.get_Month(), _T.get_Day()), hours(_T.get_Hour()) +
        minutes(_T.get_Minute()));
  
    _T.~_DateTime();

    return this_DateTime > that_DateTime;
}

bool 
DateTime::_DateTime::operator < (_DateTime& _T) {
    using namespace boost::posix_time;
    using namespace boost::gregorian;

    ptime this_DateTime(date(this->get_Year(), this->get_Month(), this->get_Day()), hours(this->get_Hour()) +
        minutes(this->get_Minute()) );
    ptime that_DateTime(date(_T.get_Year(), _T.get_Month(), _T.get_Day()), hours(_T.get_Hour()) +
        minutes(_T.get_Minute()) );

    _T.~_DateTime();

    return this_DateTime < that_DateTime;
}

bool 
DateTime::_DateTime::operator==(_DateTime& _T) {
    using namespace boost::posix_time;
    using namespace boost::gregorian;

    ptime this_DateTime(date(this->get_Year(), this->get_Month(), this->get_Day()), hours(this->get_Hour()) +
        minutes(this->get_Minute()) );
    ptime that_DateTime(date(_T.get_Year(), _T.get_Month(), _T.get_Day()), hours(_T.get_Hour()) +
        minutes(_T.get_Minute()) );

    _T.~_DateTime();

    return this_DateTime == that_DateTime;
}

bool 
DateTime::_DateTime::operator !=(_DateTime& _T) {
    using namespace boost::posix_time;
    using namespace boost::gregorian;

    ptime this_DateTime(date(this->get_Year(), this->get_Month(), this->get_Day()), hours(this->get_Hour()) +
        minutes(this->get_Minute()) );
    ptime that_DateTime(date(_T.get_Year(), _T.get_Month(), _T.get_Day()), hours(_T.get_Hour()) +
        minutes(_T.get_Minute()) );

    _T.~_DateTime();

    return this_DateTime != that_DateTime;
}



