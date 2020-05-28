#include "Reservation.h"
#include <string>

_Reservation::_Reservation(int s_Day, int s_Month, int s_Year, int s_Sec, int s_Minute, int s_Hour,	int e_Day, int e_Month, int e_Year, int e_Sec, int e_Minute, int e_Hour) :
	m_StartDateTime{ std::make_shared<DateTime::_DateTime>(s_Day, s_Month, s_Year, s_Sec, s_Minute, s_Hour) },
	m_EndDateTime(std::make_shared<DateTime::_DateTime>(e_Day, e_Month, e_Year, e_Sec, e_Minute, e_Hour)) {}

_Reservation::~_Reservation() { }

bool 
_Reservation::check_Rreservation() {
		//überprüffen, ob raum reserviert ist;
	if (m_StartDateTime->equal_local_Date(m_StartDateTime) == false && m_EndDateTime->equal_local_Date(m_EndDateTime) == false)//end > start
		if (m_StartDateTime->compare_local_Time(m_StartDateTime) == false && m_EndDateTime->compare_local_Time(m_EndDateTime) != false)//end > start
			return true;
		else
			return false;
}

bool 
_Reservation::check_ReservationDateTime_Validity() {
	
		if (m_StartDateTime->compare_local_Date(m_StartDateTime) == false || m_EndDateTime->compare_local_Date(m_EndDateTime) == false) 
			return  true;

		else if (m_StartDateTime->equal_local_Date(m_StartDateTime) == false && m_EndDateTime->equal_local_Date(m_EndDateTime) == true)
			return true;

		else if (m_StartDateTime->equal_local_Date(m_StartDateTime) == true && m_EndDateTime->equal_local_Date(m_EndDateTime) == false)
			return true;

		else if (m_StartDateTime->equal_local_Date(m_StartDateTime) == false && m_EndDateTime->equal_local_Date(m_EndDateTime) == false && m_EndDateTime->compare_local_Time(m_EndDateTime) == false)
			return true;

		else if (m_EndDateTime->compare_local_Date(m_EndDateTime) == false && m_EndDateTime->compare_local_Time(m_EndDateTime) == false) 
			return  true;

		else if (m_EndDateTime->compare_Date(m_StartDateTime) == false && m_EndDateTime->compare_Time(m_StartDateTime) == false) 
			return  true;

		else if (m_EndDateTime->compare_Date(m_StartDateTime) == false)
			return  true;

		else if (m_StartDateTime->compare_Date(m_EndDateTime)==false)
			return  true;

		else
			return false;
}

 std::list<std::string>
_Reservation::get_Next_Reservation_StartDate() {
	std::list <std::string>Date;
		Date.push_back(m_StartDateTime->get_Date());
	return Date;
}
 
 std::list<std::string>
 _Reservation::get_Next_Reservation_EndDate() {
	 std::list <std::string>Date;
	 Date.push_back(m_EndDateTime->get_Date());
	 return Date;
 }
 std::list<std::string> 
_Reservation::get_Next_Reservation_StartTime() {
	 std::list <std::string>StartTime;
	 StartTime.push_back(m_StartDateTime->get_Time());
	 return StartTime;
 }
 std::list<std::string> 
_Reservation::get_Next_Reservation_EndTime() {
	 std::list <std::string>EndTime;
	 EndTime.push_back(m_EndDateTime->get_Time());
	 return EndTime;
 }
