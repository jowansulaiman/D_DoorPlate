#include "DateTime.h"
#include <iostream>
#include <time.h>
#include <sstream>
#include <sys/timeb.h>
#include <string>
DateTime::_Time::_Time( int Sec,  int Min,  int Uhr):m_Sec(Sec), m_Minute(Min), m_Uhr(Uhr) {}
DateTime::_Time::~_Time(){}

std::pair<std::string, std::string> DateTime::_Time::check_Time (){
    time_t now = time(0);
    tm* ltm = localtime(&now);
    
    std::string time_string_now = std::to_string(ltm->tm_hour) + ":" + std::to_string(ltm->tm_min);
    std::string time_string_stated = std::to_string(m_Uhr) + ":" + std::to_string(m_Minute);
    std::pair<std::string, std::string>time_compare(time_string_now, time_string_stated);

    return time_compare;
}

std::string  DateTime::_Time::get_Time() {
    std::string complete_time = std::to_string(m_Uhr) + ":" + std::to_string(m_Minute);
    return complete_time;
}

//End of class _Time ********************************************************************


DateTime::_Date::_Date( int d,   int mo,  int y) :  m_Tag(d), m_Monat(mo),m_Jahr(y) {}
DateTime::_Date::~_Date() {}

std::pair<std::string, std::string> DateTime::_Date::check_Date() {
    time_t now = time(0);
    tm* ltm = localtime(&now);

    std::string date_string_now = std::to_string(ltm->tm_mday) + "." + std::to_string(1+ltm->tm_mon) + "." + std::to_string(1900+ltm->tm_year);
    std::string date_string_stated = std::to_string(m_Tag) + "." + std::to_string(m_Monat) + "." + std::to_string(m_Jahr);
    std::pair <std::string, std::string> date_compare(date_string_now, date_string_stated);

    return date_compare;
}

std::string DateTime::_Date::get_date() {
    std::string complete_date =std::to_string(m_Tag) + "." + std::to_string(m_Monat) + "." + std::to_string(m_Jahr);
    return complete_date;
}

// End of class _Date ************************************************************************************************

DateTime::ZeitStempel::ZeitStempel():m_start_Date(2,03,2019),m_end_Date(12,05,2020),m_start_Time(20,20,16), m_end_Time(20,12,17) {}
DateTime::ZeitStempel::~ZeitStempel(){}

void DateTime::ZeitStempel::check_DateTime(){
    time_t now = time(0);
    tm* ltm = localtime(&now);

    std::string ltm_string_now = std::to_string(ltm->tm_mday) + "." + std::to_string(1 + ltm->tm_mon) + "." + 
        std::to_string(1900 + ltm->tm_year) + " " + std::to_string(ltm->tm_hour) + ":" + std::to_string(ltm->tm_min);

    std::string complete_string_startTime_stated = m_start_Date.get_date()+" "+ m_start_Time.get_Time();
    std::string complete_string_endTime_stated = m_end_Date.get_date() + " " + m_end_Time.get_Time();

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


std::pair<std::string, std::string> DateTime::ZeitStempel::get_Start_End_DateTime() {
    std::string start_DateTime = m_start_Date.get_date() + " " + m_start_Time.get_Time();
    std::string end_DateTime = m_end_Date.get_date() + " " + m_end_Time.get_Time();

    std::pair<std::string, std::string>return_DateTime(start_DateTime, end_DateTime);
    return return_DateTime;
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

