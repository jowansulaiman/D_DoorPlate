#ifndef DTS_Reservation_H
#define DTS_Reservation_H
#include "Room.h"
#include "DateTime.h"
#include <string>

class _Reservation
{
private:
	_Room room;

	std::shared_ptr<DateTime::_DateTime> m_Start;
	std::shared_ptr<DateTime::_DateTime> m_End;
	
	bool m_ReservationState;

public:
	_Reservation(int Day, int Month, int Year, int Sec, int Minute, int Hour);
	~_Reservation();

	bool is_Reservation_Deleted(DateTime::_DateTime& D);
	std::pair<std::string, std::string>  get_StartDateTime();
};


#endif // !DTS_Reservation_H

