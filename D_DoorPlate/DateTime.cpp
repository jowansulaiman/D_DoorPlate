#include "DateTime.h"
#include <iostream>
bool Date::chec_Time() {
	return true;
}

void Date::_time() {

  // Anzeige von Uhrzeit im Stil des Betriebssystems.
    _strtime_s(tmpbuf, 128);
    printf("OS time:\t%s\n", tmpbuf);
 }


void Date::_date() {
    // Anzeige von Datum im Stil des Betriebssystems.
    _strdate_s(tmpbuf, 128);
    printf("date:\t %s", tmpbuf);
    std::cout << std::endl;
}
void Date::_day() {

}
void Date::_month() {

}
void Date::_year() {

}
void Date::_hour() {

}
void Date::_min() {

}






