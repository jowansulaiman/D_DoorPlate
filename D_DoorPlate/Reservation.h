#ifndef DTS_Reservation_H
#define DTS_Reservation_H

#include "DateTime.h"
#include <string>
#include<list>
#include <boost/date_time.hpp>
class _Reservation
{
private:
	std::shared_ptr<DateTime::_DateTime> m_StartDateTime;
	std::shared_ptr<DateTime::_DateTime> m_EndDateTime;

public:
	_Reservation(int s_Day, int s_Month, int s_Year, int s_Sec, int s_Minute, int s_Hour,
		int e_Day, int e_Month, int e_Year, int e_Sec, int e_Minute, int e_Hour);

	~_Reservation();

	bool check_Rreservation();
	bool check_ReservationDateTime_Validity();

	std::list<std::string> get_Next_Reservation_StartDate();
	std::list<std::string> get_Next_Reservation_EndDate();
	std::list<std::string> get_Next_Reservation_EndTime();
	std::list<std::string> get_Next_Reservation_StartTime();
};


#endif // !DTS_Reservation_H

