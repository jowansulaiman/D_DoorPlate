#include <iostream>
#include "Room.h"

_Room::_Room(int ID, std::string Description, int BoardID):m_RoomID(ID), m_Description(Description), m_BoardID(BoardID){
	
}

_Room::~_Room() {}


std::string _Room::get_Room_name() {
	return m_Description;
}

int _Room::get_Room_ID() {
	return m_RoomID;
}

int _Room::get_Board_ID() {
	return m_BoardID;
}

bool _Room::is_Reserved() {
	//m_Reservation.assign(m_RoomID, _Reservation());
	//if (reservation[m_RoomID].check_Rreservation != 1)
		return true;
}