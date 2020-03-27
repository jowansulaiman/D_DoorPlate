#include "DautmUhrzeit.h"
#include <iostream>

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/timeb.h>
#include <string.h>


DautmUhrzeit::UhrZeit::UhrZeit() {

}
DautmUhrzeit::UhrZeit::UhrZeit(unsigned int Sec, unsigned int Min, unsigned int Uhr):m_Sec(Sec), m_Minute(Min), m_Uhr(Uhr) {

}


DautmUhrzeit::Datum::Datum(unsigned int d, unsigned  int mo, unsigned int y)
    :  m_Tag(d), m_Monat(mo),m_Jahr(y) {}
DautmUhrzeit::Datum::Datum() { std::cout << std::endl << "Con" << std::endl; }
DautmUhrzeit::Datum::~Datum() { std::cout << std::endl << "Dis" << std::endl; }

bool DautmUhrzeit::Datum::chec_Time() {
	return true;
}

int DautmUhrzeit::Datum::_time() {
    
  // Anzeige von Uhrzeit im Stil des Betriebssystems.
    //_strtime_s(mpbuf, 128);
   // printf("OS time:\t%s\n", tmpbuf);
    //return (int)tmpbuf;
    return 1;
 }


void DautmUhrzeit::Datum::_date() {
    std::cout << "test erfolg." << std::endl;
}
void DautmUhrzeit::Datum::_day() {

}
void DautmUhrzeit::Datum::_month() {

}
void DautmUhrzeit::Datum::_year() {

}


DautmUhrzeit::ZeitStempel::ZeitStempel() {}
DautmUhrzeit::ZeitStempel::ZeitStempel(int d, int mo, int y)
    :start(d, mo, y),end(d, mo, y) {}

DautmUhrzeit::ZeitStempel::~ZeitStempel(){}




