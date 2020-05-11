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
	_Reservation(int Day, int Month, int Year, int Minute, int Hour,
		int e_Day, int e_Month, int e_Year, int e_Minute, int e_Hour);

	~_Reservation();

	bool check_Rreservation();
	bool check_ReservationDateTime_Validity();

	std::list<std::string> get_Next_ReservationDate();
	std::list<std::string> get_Next_ReservationEndTime();
	std::list<std::string> get_Next_ReservationStartTime();
};


#endif // !DTS_Reservation_H

