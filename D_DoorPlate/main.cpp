
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
	std::shared_ptr<Database::_Query> Abfragen(new Database::_Query);
	std::shared_ptr<_Room> room(new _Room(1, "bille", 234));
	std::shared_ptr<Imagehandling::Image> image(new Imagehandling::Image("Doorplate.png", "C:\\Users\\jowan\\source\\repos\\killuahh\\D_DoorPlate\\D_DoorPlate\\"));

	bool state = false;
	int incre = 0;
	std::string firstResrvationTime, secondReservationTime;
	do
	{

	image->read_Img();
	image->Write_Img_Room_Designstion(room->get_Room_name());
	
	std::pair<std::vector<std::string>, std::vector<std::string >> pai;
	for (auto firstValeus : Abfragen->get_StartDateTime(room->get_Room_ID()))
		pai.first.push_back(firstValeus);
	for (auto secondValues : Abfragen->get_EndDateTime(room->get_Room_ID()))
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

		for (auto n : room->get_Reservation())
		{
			if (n.check_Rreservation() != true)
			{
				if (n.check_ReservationDateTime_Validity() == false) {
					incre++;
					while (incre < 5)
					{
						image->Write_Img_DateSequence(n.get_Next_ReservationDate());
						image->Write_Img_TimeSequence(n.get_Next_ReservationStartTime(), n.get_Next_ReservationEndTime());
						break;
					}
					
				}
			}
			if (n.check_Rreservation() == true)
			{
				for (auto s : n.get_Next_ReservationStartTime())
				{
					firstResrvationTime = s;
				}
				for (auto e : n.get_Next_ReservationEndTime())
				{
					secondReservationTime = e;
				}
			}
		}
		if (!firstResrvationTime.empty() && !secondReservationTime.empty())
		{
			state = true;
			if (state==true)
			{
				image->Write_Img_Room_StateTime(firstResrvationTime, secondReservationTime, state);
			}
		}
	
	image->Convert_Img();
	image->set_place(0, 0);

	for (auto cle: room->get_Reservation())
	{
		cle.get_Next_ReservationDate().clear();
		cle.get_Next_ReservationEndTime().clear();
		cle.get_Next_ReservationStartTime().clear();
	}

	pai.first.clear();
	pai.second.clear();
	room->clear_total();
	room->get_Reservation().clear();
	Abfragen->get_StartDateTime(room->get_Room_ID()).clear();
	Abfragen->get_EndDateTime(room->get_Room_ID()).clear();
	Abfragen->Disconnect();
	incre = 0;
	image->show_img();

	std::this_thread::sleep_for(std::chrono::seconds(5));
	} while (true);

	return 0;
}