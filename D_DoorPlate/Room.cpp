#include <iostream>
#include "Room.h"

_Room::_Room(int R_Nr, std::string Description):m_RaumNr(R_Nr), m_Description(Description){}
_Room::~_Room() {}
_Room::_Room() {
	m_RaumNr = NULL;
	m_Description = "";
}
std::pair<std::int64_t, std::string>_Room::getRoom_ID_Name() {
	int y = 2;
	return std::make_pair(y, "");
}