#ifndef  DTS_Raum_H
#define DTS_Raum_H

#include <iostream>
#include "Reservation.h"
#include <map>



class _Room {
private:
	int m_RoomID;
	int m_BoardID;
	std::string m_Description;

	std::list <_Reservation> m_totalReservation;
public:
	_Room(int ID, std::string Description, int BoardID);
	~_Room();	

	int get_Room_ID();
	int get_Board_ID();
	std::string get_Room_name();

public:
	bool is_Reserved();
	void set_Reservation(_Reservation reservation);
	std::list<_Reservation> get_Reservation();
	void clear_total();
};


#endif // ! DTS_Raum_H
