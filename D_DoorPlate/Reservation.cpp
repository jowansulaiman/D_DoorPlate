#include "Reservation.h"

#include <string>
_Reservation::_Reservation(int Day, int Month, int Year, int Sec, int Minute, int Hour) :
	m_Start(std::make_shared<DateTime::_DateTime>(Day, Month, Year, Sec, Minute, Hour)), 
	m_End(std::make_shared<DateTime::_DateTime>(Day, Month, Year, Sec, Minute, Hour)), m_ReservationState(NULL) , room(1,"wqe",3){

}

_Reservation::~_Reservation() {

}

bool _Reservation::is_Reservation_Deleted(DateTime::_DateTime &D) {
	
	return m_ReservationState;
}
std::pair<std::string, std::string>  _Reservation::get_StartDateTime() {
	std::string Date_String = std::to_string(std::get<0>(m_Start->get_Date())) +"."+ std::to_string(std::get<1>(m_Start->get_Date())) + "." + std::to_string(std::get<2>(m_Start->get_Date()));
	std::string Time_String = std::to_string(std::get<0>(m_Start->get_Time())) + ":" + std::to_string(std::get<1>(m_Start->get_Time())) + ":" + std::to_string(std::get<2>(m_Start->get_Time()));

	return std::make_pair(Date_String, Time_String);
}