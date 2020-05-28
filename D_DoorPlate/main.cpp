
#include <iostream>
#include "Image.h"
#include "Room.h"
#include "Reservation.h"
#include "Query.h"
#include <list>
#include <vector>
#include "boost/date_time.hpp"


void Hide_Console()
{
	HWND Stealth;
	AllocConsole();
	Stealth = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(Stealth, 1);
}

using namespace boost::gregorian;
using namespace boost::posix_time;

int main(){
	Hide_Console();

	std::shared_ptr<Database::_Query> Abfragen(new Database::_Query);
	std::shared_ptr<_Room> room(new _Room(1, "bille", 234));
	std::shared_ptr<Imagehandling::Image> image(new Imagehandling::Image("Doorplate.png", "C:\\Users\\jowan\\source\\repos\\killuahh\\D_DoorPlate\\D_DoorPlate\\"));

	int incre = 0;
	std::vector<std::string> firstResrvationTime, secondReservationTime;
	do
	{
		image->read_Img();
		image->Write_Img_Room_Designstion(room->get_Room_name());
		
		std::pair<std::vector<std::string>, std::vector<std::string >> get_DateTime;
		
		for (auto firstValeus : Abfragen->get_StartDateTime(room->get_Room_ID()))
			get_DateTime.first.push_back(firstValeus);
		for (auto secondValues : Abfragen->get_EndDateTime(room->get_Room_ID()))
			get_DateTime.second.push_back(secondValues);
		
		for (size_t i = 0; i < get_DateTime.first.size(); i++)
		{
			date startReservation(from_simple_string(get_DateTime.first[i]));
			date endReservation(from_simple_string(get_DateTime.second[i]));
			
			time_duration startTime(time_from_string(get_DateTime.first[i]).time_of_day());
			time_duration endTime(time_from_string(get_DateTime.second[i]).time_of_day());
			
			_Reservation *reservation = new _Reservation(startReservation.day().as_number(), startReservation.month().as_number(), startReservation.year(), startTime.seconds(), startTime.minutes(), startTime.hours(),
				endReservation.day().as_number(), endReservation.month().as_number(), endReservation.year(), endTime.seconds(), endTime.minutes(), endTime.hours());
			
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
						image->Write_Img_DateSequence(n.get_Next_Reservation_StartDate());
						image->Write_Img_TimeDifference(n.get_Next_Reservation_StartTime(), n.get_Next_Reservation_EndTime());
						image->Write_Img_TimeSequence(n.get_Next_Reservation_StartTime(), n.get_Next_Reservation_EndTime());
						break;
					}
				}
				else
				{
					std::pair<std::vector<std::string>, std::vector<std::string>> invalidly_Value;

					for (auto get_invalidly_Start_DateTime:n.get_Next_Reservation_StartDate())
					{
						date start_Date_Reservation(from_uk_string(get_invalidly_Start_DateTime));

						std::string start_DateTime_invalidly;

						start_DateTime_invalidly = std::to_string(start_Date_Reservation.year()) + "-" + 
							std::to_string(start_Date_Reservation.month().as_number()) + "-" + std::to_string(start_Date_Reservation.day().as_number());
						
						for (auto deleteStart : n.get_Next_Reservation_StartTime())
						{
							start_DateTime_invalidly = start_DateTime_invalidly + " " + deleteStart;
							break;
						}
						invalidly_Value.first.push_back(start_DateTime_invalidly);
					} 

					for (auto get_invalidly_End_DateTime: n.get_Next_Reservation_EndDate())
					{
						date end_Date_Reservation(from_uk_string(get_invalidly_End_DateTime));

						std::string  End_DateTime_invalidly;

						End_DateTime_invalidly = std::to_string(end_Date_Reservation.year()) + "-" +
							std::to_string(end_Date_Reservation.month().as_number()) + "-" + std::to_string(end_Date_Reservation.day().as_number());
						

						for (auto deleteEnd : n.get_Next_Reservation_EndTime())
						{
							End_DateTime_invalidly = End_DateTime_invalidly + " " + deleteEnd;
							break;
						}

						invalidly_Value.second.push_back(End_DateTime_invalidly);
					}

					for (size_t i = 0; i < invalidly_Value.first.size(); i++)
					{
						Abfragen->delete_reservation(room->get_Room_ID(), true, invalidly_Value.first[i], invalidly_Value.second[i]);
					}
				}
			}
			if (n.check_Rreservation() == true)
			{
				for (auto s : n.get_Next_Reservation_StartTime())
				{
					firstResrvationTime.push_back(s);
				}
				for (auto e : n.get_Next_Reservation_EndTime())
				{
					secondReservationTime.push_back(e);
				}
			}
		}
		if (!firstResrvationTime.empty() && !secondReservationTime.empty())
		{ image->Write_Img_Room_StateTime(firstResrvationTime, secondReservationTime, true);  }
		else
		{ image->Write_Img_Room_StateTime(firstResrvationTime, secondReservationTime, false); }
		
	image->Convert_Img();
	image->set_place(0, 0);

	for (auto cle: room->get_Reservation())
	{
		cle.get_Next_Reservation_StartDate().clear();
		cle.get_Next_Reservation_EndTime().clear();
		cle.get_Next_Reservation_StartTime().clear();
	}

	get_DateTime.first.clear(); 	get_DateTime.second.clear();
	room->clear_total();	room->get_Reservation().clear();
	
	Abfragen->get_StartDateTime(room->get_Room_ID()).clear(); 	Abfragen->get_EndDateTime(room->get_Room_ID()).clear();
	Abfragen->Disconnect();
	
	incre = 0;
	image->show_img();
	firstResrvationTime.clear(); 	secondReservationTime.clear();

	std::this_thread::sleep_for(std::chrono::seconds(2));
	} while (true);

	return 0;
}