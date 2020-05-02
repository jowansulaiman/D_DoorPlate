#include <iostream>
#include "Room.h"

_Room::_Room(int ID, std::string Description, int BoardID):m_RoomID(ID), m_Description(Description), m_BoardID(BoardID){
	
}

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
	
		return true;
}

void 
_Room::add_Room(int roomID, boost::posix_time::ptime start, boost::posix_time::ptime end) {
	std::vector<int> rooms;
	for (size_t i = 0; i < m_RoomID; i++)
	{
		rooms.push_back(m_RoomID);
	}
	std::vector<int>::iterator itr = std::find(rooms.begin(), rooms.end(), roomID);

	for (size_t i = 0; i < sizeof(itr); i++)
	{
		m_TotalReservations.push_back(new _Reservation(start.date().day(), start.date().month(), start.date().year(), start.time_of_day().minutes(), start.time_of_day().hours(), 
			end.date().day(), end.date().month(), end.date().year(), end.time_of_day().minutes(), end.time_of_day().hours()));

	}

}