#include <iostream>
#include "Room.h"

_Room::_Room(int ID, std::string Description, int BoardID):
	m_RoomID(ID), m_Description(Description), m_BoardID(BoardID) { }

_Room::~_Room() {}


std::string
_Room::get_Room_name() {
	return m_Description;
}

int
_Room::get_Room_ID() {
	return m_RoomID;
}

int 
_Room::get_Board_ID() {
	return m_BoardID;
}

bool
_Room::is_Reserved() {
	for (auto& r : m_totalReservation) {
		if (r.check_Rreservation() == true)
			return true;
		else
			return false;
	}
}

void
_Room::set_Reservation(_Reservation reservation) {
	m_totalReservation.push_back(reservation);
}

std::list<_Reservation>
_Room::get_Reservation() {
	return m_totalReservation;
}
void
_Room::clear_total() {
	m_totalReservation.clear();
}
