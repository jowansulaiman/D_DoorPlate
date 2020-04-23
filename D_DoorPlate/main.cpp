
#include <stdio.h>
#include <iostream>
#include <ostream>
#include <string>
#include <iterator>
#include <iostream>
#include "Image.h"
#include "Query.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <array>
#include "DateTime.h"
#include "reservation.h"
#include <cassert>
#include <boost/date_time.hpp>
#include <boost/format.hpp>

class dt
{
public:
    int year;
    int month;
    int day;
    int hour;
    int min;
    int sec;
    int millisec;
    void set(int year, int month, int day, int hour, int min, int sec, int millisec) {
        this->year = year;
        this->month = month;
        this->day = day;
        this->hour = hour;
        this->min = min;
        this->sec = sec;
        this->millisec = millisec;
    }
    void print() {
        std::cout << "y: " << year << " m: " << month << " d: " << day << " h: " << hour << " m: " << min << std::endl;
    }
    bool operator<(const dt& dt_);
    bool operator==(const dt& dt_);
    dt operator+(const dt& dt_);

};
dt dt::operator + (const dt& dt_)
{
    using namespace boost::posix_time;
    using namespace boost::gregorian;

    date thisDate(this->year, this->month, this->day);
    date newDate = thisDate + years(dt_.year) + months(dt_.month) + days(dt_.day);

    ptime newDateTime(newDate, hours(this->hour) + hours(dt_.hour) + minutes(this->min) + minutes(dt_.min) + seconds(this->sec) + seconds(dt_.sec) +
        boost::posix_time::millisec(int(this->millisec)) + boost::posix_time::millisec(int(dt_.millisec)));

    dt dateTime;

    date t1_date = newDateTime.date();

    dateTime.year = t1_date.year();
    dateTime.month = t1_date.month();
    dateTime.day = t1_date.day();

    time_duration t1_time = newDateTime.time_of_day();

    dateTime.hour = t1_time.hours();
    dateTime.min = t1_time.minutes();
    dateTime.sec = t1_time.seconds();
    dateTime.millisec = t1_time.fractional_seconds() / 1000.0f;

    return dateTime;
}
int main() {

    //std::ifstream file1;
    //file1.open("image.xbm", std::ios::in);

    //std::string txt;
    //std::stringstream ss;
    //if (file1.is_open()) {

    //    while (getline(file1, txt))
    //        ss << txt;
    //    std::string txt1 = ss.str();
    //    boost::replace_all_copy(txt1, "#define image_width 640#define image_height 384static char image_bits[] =", " ");
    //    //boost::replace_all(txt1, ",", " ");
    //        std::cout << txt1;


    //   file1.close();
    //}


    //std::string tyt = "jowans, is sd f g g}";
    //boost::replace_all(tyt, "}", " ");

    //std::cout << tyt; 
    DateTime::_Time t(20, 12, 18);
    DateTime::_Time t1(20, 12, 17);
    //_DateTime new_DateTime(add_Year, add_Month, add_Day, add_Hour, add_Minute, add_Second);
    //DateTime::_Time t2 = t1 + t;
    if(t == t1)
        std::cout << t.get_Time() << " " <<"";
    //using namespace boost::posix_time;
    //using namespace boost::gregorian;

    //DateTime::_DateTime t(20, 10, 2020, 21, 25, 14);
    //DateTime::_DateTime t1(20, 10, 2020, 21, 25, 14);
    //DateTime::_DateTime t2 = t1 + t;

    //std::cout << t2.get_Date() << " " <<  t2.get_Time();
    //DateTime::_Date t1(20, 12, 2022);
   
    //if(t<t1)
      //std::cout << t.get_Time();
    //if (t > t1)
    //    std::cout << "True";//DateTime::_Time t2= t - t1;

  //std::cout << format("(t2)=(%Y,%M,%D)");

  //  
  //  std::cout /*<< to_simple_string(t2) << " - "
  //      << to_simple_string(t1) << " = "*/
  //      << ss.str() << std::endl;


   /* dt dat;
    dt dat1;
    dat.set(0, 0, 0, 17, 35, 25, 15);
    dat1.set(0, 0, 0, 18, 35, 25, 15);


    dt dt3 = dat + dat1;
    dt3.print();*/

    
    /*
    std::shared_ptr<Database::_Statement>s(new Database::_Statement("select  * from reservation limit 3")) ;

    for (auto& n : s->Query()) {
        std::cout << n << std::endl;
    }*/
    return 0;

}

   

   /* _Reservation r(20, 04, 2020, 25, 20, 17); 
    std::cout << r.get_StartDateTime().first << " " << r.get_StartDateTime().second;*/
   

    //DateTime::_DateTime t(20, 04, 2021, 12, 27, 9 /*end*/, 20, 05, 2021, 20, 28, 17);
    //if (t.check_DateTime() == false) {

    //    std::cerr << "feler datum" << std::endl;
    //}


//int main(int argc, char* argv[]) {

//    //system("magick image.png image.xbm");
//
//    std::ifstream file1;
//    file1.open("imagee.xbm", std::ios::in)
//    std::string txt;
//  
//    std::ostream ofile();
//    if (file.is_open()) {
//        //std::cout << "geoffnet";
//        for (size_t i = 0; i < 3; i++)
//        {
//            getline(file, txt);
//            txt.replace(1, 4, "");
//        } 
//        
//        while (getline(file, txt))
//            std::cout << txt;
//
//       file1.close();
   /* }
    else { std::cout << "´konnte nicht geoffnet werden"; }*/
    
   




    // << std::get<1>(conn->Query()) << std::endl;
  /*while (true){

    std::shared_ptr <Database::Statement> s(new Database::Statement());

    const char* re= s->Query().second;
    if (re==NULL) {
        re= "Leer";
    }
 
    
    std::shared_ptr< ImageVerarbeitung::Image> i(new ImageVerarbeitung::Image(re));
    i->readImg();
    i->showWin();
    std::this_thread::sleep_for(std::chrono::seconds(12));
  }*/

bool dt::operator < (const dt& dt_)
{
    using namespace boost::posix_time;
    using namespace boost::gregorian;

    ptime thisTime(date(this->year, this->month, this->day), hours(this->hour) + minutes(this->min) + seconds(this->sec) + boost::posix_time::millisec(int(this->millisec)));
    ptime thatTime(date(dt_.year, dt_.month, dt_.day), hours(dt_.hour) + minutes(dt_.min) + seconds(dt_.sec) + boost::posix_time::millisec(int(dt_.millisec)));

    return thisTime < thatTime;
}
bool dt::operator == (const dt& dt_)
{
    using namespace boost::posix_time;
    using namespace boost::gregorian;

    ptime thisTime(date(this->year, this->month, this->day), hours(this->hour) + minutes(this->min) + seconds(this->sec) + boost::posix_time::millisec(int(this->millisec)));
    ptime thatTime(date(dt_.year, dt_.month, dt_.day), hours(dt_.hour) + minutes(dt_.min) + seconds(dt_.sec) + boost::posix_time::millisec(int(dt_.millisec)));

    return thisTime == thatTime;
}

