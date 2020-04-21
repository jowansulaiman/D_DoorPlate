#include <iostream>
#include "Room.h"

_Room::_Room(int ID, std::string Description, int BoardID):m_RoomID(ID), m_Description(Description), m_BoardID(BoardID){}
_Room::_Room(std::string Description, int BoardID): m_RoomID(NULL), m_Description(Description), m_BoardID(BoardID) { }
_Room::_Room(int BoardID) : m_RoomID(NULL), m_Description(NULL), m_BoardID(BoardID) { }


_Room::~_Room() {}


std::map<int, std::string>_Room::get_Room() {

	std::map<int, std::string>returMap;
	returMap[m_RoomID] = (m_Description);
	return returMap;
}

int _Room::get_BoardID() {
	return m_BoardID;
}