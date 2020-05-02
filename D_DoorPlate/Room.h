#ifndef  DTS_Raum_H
#define DTS_Raum_H

#include <iostream>
#include "Reservation.h"
#include <map>



class _Room {
private:
	int m_RoomID;
	int m_BoardID;
	
	std::vector<_Reservation*> m_TotalReservations;

	//_Reservation reservation;
	std::string m_Description;
public:

	_Room(int ID, std::string Description, int BoardID);
	~_Room();	

	bool is_Reserved();
	void add_Room(int roomID, boost::posix_time::ptime start, boost::posix_time::ptime end);
	std::string get_Room_name();
	int get_Room_ID();
	int get_Board_ID();
};
#endif // ! DTS_Raum_H
