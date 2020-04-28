#include "Reservation.h"

#include <string>
_Reservation::_Reservation(int s_Day, int s_Month, int s_Year, int s_Sec, int s_Minute, int s_Hour,	int e_Day, int e_Month, int e_Year, int e_Sec, int e_Minute, int e_Hour) :
	m_StartDateTime(std::make_unique<DateTime::_DateTime>(s_Day, s_Month, s_Year, s_Sec, s_Minute, s_Hour)),
	m_EndDateTime(std::make_unique<DateTime::_DateTime>(e_Day, e_Month, e_Year, e_Sec, e_Minute, e_Hour)),
	m_cancelled(false), m_deleted(false) {}

_Reservation::~_Reservation() { }

bool _Reservation::check_Rreservation() {
	while (m_deleted != true && m_cancelled !=true)
	{
		if (m_StartDateTime->compare_local_Date(m_StartDateTime) == false || m_EndDateTime->compare_local_Date(m_EndDateTime) == false) {
			m_deleted = true;
			return false;
		}
		//überprüffen, ob raum reserviert ist;
		if (m_StartDateTime->compare_local_Time(m_StartDateTime) == false && m_EndDateTime->compare_local_Time(m_EndDateTime) != false)//end > start
			return false;
		else
			return true;
	} 
}
void _Reservation::check_Validity() {
	if (m_StartDateTime->compare_local_Date(m_StartDateTime) == false || m_EndDateTime->compare_local_Date(m_EndDateTime) == false) {
		m_deleted = true;
	}
	if (m_EndDateTime->compare_local_Time(m_EndDateTime) == false ) {
		m_deleted = true;
	}
	if (m_EndDateTime->compare_Date(m_StartDateTime) == false || m_EndDateTime->compare_Time(m_StartDateTime)==false) {
		m_deleted = true;
	}
}

bool _Reservation::get_deleted() {
	return m_deleted;
}

std::pair<std::list<std::string>, std::list<std::string>>  _Reservation::get_Next_StartDateTime_Reservations() {
	
	std::list <std::string>Date, Time;
		while (check_Rreservation()!=false)
		{
			check_Validity();
			if (m_cancelled != true && m_deleted != true)
				if (Time.empty()) {
					Date.push_back(m_StartDateTime->get_Date());
					Time.push_back(m_StartDateTime->get_Time());
				}
				else
					break;
			else
				break;
		}
	return std::make_pair(Date, Time);
}
std::pair<std::list<std::string>, std::list<std::string>>  _Reservation::get_Next_EndDateTime_Reservations() {

	std::list <std::string>Date, Time;

	while (check_Rreservation() != false)
	{
		if (Time.empty()) {
			Date.push_back(m_EndDateTime->get_Date());
			Time.push_back(m_EndDateTime->get_Time());
		}
		else
			break;
	}

	return std::make_pair(Date, Time);
}
//
//int _Reservation::get_TimeSpan(){
//	using namespace boost::gregorian;
//	using namespace boost::posix_time;
//
//	//time_duration td(from_simple_string(m_StartDateTime->get_Time()));
//
//	 
//	 return 1;
//	}