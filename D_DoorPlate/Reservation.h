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

	bool m_cancelled;
	bool m_deleted;

public:
	_Reservation(int Day, int Month, int Year, int Sec, int Minute, int Hour,
		int e_Day, int e_Month, int e_Year, int e_Sec, int e_Minute, int e_Hour);

	~_Reservation();

	bool check_Rreservation();
	void check_Validity();
	bool get_deleted();
	//int get_TimeSpan();

	std::pair<std::list<std::string>, std::list<std::string>> get_Next_StartDateTime_Reservations();
	std::pair<std::list<std::string>, std::list<std::string>> get_Next_EndDateTime_Reservations();
};


#endif // !DTS_Reservation_H

