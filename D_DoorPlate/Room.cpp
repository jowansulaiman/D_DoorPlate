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
//std::list<std::string>
//_Room::get_NextReservation(std::shared_ptr<_Reservation> m_Reservation) {
//
//	std::list<std::string> resultList;
//	if (is_Reserved() != true) {
//		while (!(m_Reservation->get_Next_ReservationDate().empty()))
//		{
//			//resultList.push_back = (m_Reservation->get_Next_ReservationDate());
//		}
//	}
//	return resultList;
//}
//
//
//std::list<std::string> 
//_Room::get_StartTime(std::shared_ptr<_Reservation> m_Reservation) {
//	std::list<std::string> ResultList;
//	if (is_Reserved() != true) {
//		while (!(m_Reservation->get_Next_ReservationStartEndTime().first.empty()))
//		{
//			//ResultList.push_back (m_Reservation->get_Next_ReservationStartEndTime().first);
//		}
//	}
//	return ResultList;
//}
//std::list<std::string> 
//_Room::get_EndTime(std::shared_ptr<_Reservation> m_Reservation) {
//	std::list<std::string> ResultList;
//	if (is_Reserved() != true) {
//		while (!(m_Reservation->get_Next_ReservationStartEndTime().second.empty()))
//		{
//			//ResultList.push_back = (m_Reservation->get_Next_ReservationStartEndTime().second);
//		}
//	}
//	return ResultList;
//}
