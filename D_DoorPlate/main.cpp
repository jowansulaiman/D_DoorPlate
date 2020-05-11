
#include <iostream>
#include "Image.h"
#include "Room.h"
#include "Reservation.h"
#include "Query.h"
#include <list>
#include "boost/date_time.hpp"


using namespace boost::gregorian;
using namespace boost::posix_time;

int main(){
	do
	{
	std::shared_ptr<Database::_Statement> Abfragen ( new Database::_Statement);
	std::shared_ptr<_Room> room(new _Room(1,"bille", 234));
	std::shared_ptr<Imagehandling::Image> image(new Imagehandling::Image("Doorplate.png", "C:\\Users\\jowan\\source\\repos\\killuahh\\D_DoorPlate\\D_DoorPlate\\"));
	
	image->read_Img();
	image->Write_Img_Room_Designstion(room->get_Room_name());
	
	std::pair<std::vector<std::string>, std::vector<std::string >> pai;
	for (auto firstValeus : Abfragen->StartDateTime(room->get_Room_ID()))
		pai.first.push_back(firstValeus);
	for (auto secondValues : Abfragen->EndDateTime(room->get_Room_ID()))
		pai.second.push_back(secondValues);

	for (size_t i = 0; i < pai.first.size(); i++)
	{
		date startReservation(from_simple_string(pai.first[i]));
		date endReservation(from_simple_string(pai.second[i]));
		
		time_duration startTime(time_from_string(pai.first[i]).time_of_day());
		time_duration endTime(time_from_string(pai.second[i]).time_of_day());
		
		_Reservation *reservation = new _Reservation(startReservation.day().as_number(), startReservation.month().as_number(), startReservation.year(), startTime.minutes(), startTime.hours(),
					endReservation.day().as_number(), endReservation.month().as_number(), endReservation.year(), endTime.minutes(), endTime.hours());
		
		room->set_Reservation(*reservation);
	}
	
	for (auto n: room->get_Reservation())
	{		
		if (n.check_Rreservation()==false)
		{
			if (n.check_ReservationDateTime_Validity() == false) {
				image->Write_Img_DateSequence(n.get_Next_ReservationDate());//
				image->Write_Img_TimeSequence(n.get_Next_ReservationStartTime(), n.get_Next_ReservationEndTime());
			}
		}
	
		image->Write_Img_Room_StateTime(n.get_Next_ReservationStartTime(), n.get_Next_ReservationEndTime(), n.check_Rreservation());

	}

	image->show_img();
	room->get_Reservation().clear();
	Abfragen->Disconnect();

	std::this_thread::sleep_for(std::chrono::seconds(5));
	} while (true);
	return 0;
}