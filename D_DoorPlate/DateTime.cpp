#include "DateTime.h"
#include <iostream>
#include <time.h>
#include <sstream>
#include <sys/timeb.h>
#include <string>
DateTime::_Time::_Time( int Sec,  int Min,  int Uhr):m_Sec(Sec), m_Minute(Min), m_Uhr(Uhr) {}
DateTime::_Time::~_Time(){ std::cout << " time dis."; }

std::tuple<int, int, int>  DateTime::_Time::get_Time() {    return std::make_tuple(m_Sec, m_Minute, m_Uhr); }
//End of class _Time ********************************************************************


DateTime::_Date::_Date( int d,   int mo,  int y) :  m_Tag(d), m_Monat(mo),m_Jahr(y) {}
DateTime::_Date::~_Date() { std::cout << " date dis."; }

std::tuple<int, int, int>  DateTime::_Date::get_Date() { return std::make_tuple(m_Tag, m_Monat, m_Jahr); }

// End of class _Date ************************************************************************************************


DateTime::_DateTimeController::_DateTimeController(int day, int month, int year, int sec, int min, int hour):
    m_start_Date(std::make_shared<_Date>(day, month, year)),
    m_end_Date(std::make_shared<_Date>(day, month, year)),
    m_start_Time(std::make_shared<_Time>(sec, min, hour)),
    m_end_Time(std::make_shared<_Time>(sec, min, hour)) {}

DateTime::_DateTimeController::~_DateTimeController(){}

void DateTime::_DateTimeController::check_DateTime(){
    time_t now = time(0);
    tm* ltm = localtime(&now);

    std::string ltm_string_now = std::to_string(ltm->tm_mday) + "." + std::to_string(1 + ltm->tm_mon) + "." + 
        std::to_string(1900 + ltm->tm_year) + " " + std::to_string(ltm->tm_hour) + ":" + std::to_string(ltm->tm_min);

    std::string complete_string_startTime_stated = m_start_Date->get_Date()+" "+ m_start_Time->get_Time();
    std::string complete_string_endTime_stated = m_end_Date->get_Date() + " " + m_end_Time->get_Time();

    int compare_start_end_DateTime{ complete_string_startTime_stated.compare(complete_string_endTime_stated) };
    int compare_start_local_DateTime{ ltm_string_now.compare(complete_string_startTime_stated) };


    if (compare_start_local_DateTime < 0) {
        std::cerr << "Das Startdatum darf nicht kleiner als jetziges Datum sein" << std::endl;
        exit(0);
    }
    if (compare_start_end_DateTime < 0) {
        std::cerr << "das Enddatum darf nicht kleiner als Startdatum sein" << std::endl;
        exit(0);
    }
}


std::pair<std::string, std::string> DateTime::_DateTimeController::get_Start_End_DateTime() {
    std::string start_DateTime = m_start_Date->get_Date() + " " + m_start_Time->get_Time();
    std::string end_DateTime = m_end_Date->get_Date() + " " + m_end_Time->get_Time();

    return std::make_pair(start_DateTime, end_DateTime);
}




//if (date_string_stated < date_string_now)
//{
//    std::cerr << "Das angegebene Datum stimmt leider nicht mit der Jetzigen" << std::endl;
//    exit(0);
//    delete ltm;
//}


//if (time_string_stated < time_string_now) {
//    std::cerr << "Die angegebene Zeit stimmt leider nicht mit der Jetzigen" << std::endl;
//    exit(0);
//    delete ltm;
//}

