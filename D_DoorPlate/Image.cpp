#include<iostream>
#include <fstream>
#include "Image.h"
#include <opencv.hpp>


using namespace cv;


Imagehandling::Image::Image():m_filename("Türschild.png"){  }

Imagehandling::Image::Image(std::string filename, std::string path):
	 m_filename(filename), m_Path(path), m_Dateincrement_place(0), m_Timeincrement_place(0){ }

Imagehandling::Image::~Image() { }

void 
Imagehandling::Image::Check_Error() {
	if (m_Img.empty()) {

		std::cerr << "Error: " << "Could not open or find the image!" << std::endl;
		std::cerr << "Path to Image: " << m_filename << std::endl;
		
		exit(0);
	}
}

void
Imagehandling::Image::Convert_Img() {
	std::string cpp_txt = "#ifndef _GxBitmapExamples_H_\n#define _GxBitmapExamples_H_\n#if defined(ESP8266) || "
		"defined(ESP32)\n#include <pgmspace.h>\n#else\n#include <avr/pgmspace.h>\n#endif\nconst unsigned char BitmapExample1[] PROGMEM =\n{";
	
	std::string old_txt = "#define Doorplate_width 640#define Doorplate_height 384static char Doorplate_bits[] = {";
	
	std::string convert_txt = "magick " + m_Path + m_filename + " Doorplate.xbm";
	system(convert_txt.data());

	std::fstream rfile;
	std::ofstream wfile;

	std::string get_txt , filepath;
	std::vector<std::string> Vectortxt;
	std::stringstream streamInput;
	std::string joinedtxt;

	filepath = "DoorPlate.xbm";
	rfile.open(m_Path + filepath, std::ios::in);
	wfile.open(m_Path + "DoorPlate.h", std::ios::out);
	
	if (rfile.is_open())
	{
		while (getline(rfile, get_txt)) 
			streamInput << get_txt;

		std::string replastring = streamInput.str();
		boost::replace_all(replastring, old_txt, " ");

		boost::split(Vectortxt, replastring, boost::is_any_of(","));
		std::reverse(Vectortxt.begin(), Vectortxt.end());

		joinedtxt= boost::algorithm::join(Vectortxt, ",");
		joinedtxt = joinedtxt + "\n}; \n#endif";

		boost::replace_all(joinedtxt, "};,", cpp_txt);
	}
	else
	{
		std::cerr << m_Path + m_filename << " does not exist" << std::endl;
	}

	if (wfile.is_open())
	{
		wfile << joinedtxt;
	}

	rfile.close();
	wfile.close();

	std::string removefile = m_Path + filepath;
	remove(removefile.c_str());
}

void
Imagehandling::Image::Write_Img_DateSequence(std::list<std::string> DateSequence) {
	Check_Error();
	if (DateSequence.empty())
	{
		putText(m_Img, "keine Reservierung vorhanden", Point(2, 240), FONT_HERSHEY_DUPLEX, 1, Scalar(0), 1);
	}
	for (auto resu: DateSequence)
	{
		putText(m_Img, resu, Point(2, 240 + (40 * m_Dateincrement_place++)), FONT_HERSHEY_DUPLEX, 1, Scalar(0), 1);
	}
	DateSequence.clear();
	
}

void
Imagehandling::Image::Write_Img_TimeSequence(std::list<std::string> Start_TimeSequence, std::list<std::string> End_TimeSequence) {
	Check_Error();
	std::string distance = " - ";

	if (Start_TimeSequence.empty() || End_TimeSequence.empty())
	{
		putText(m_Img, " ", Point(232, 240), FONT_HERSHEY_DUPLEX, 1, Scalar(0), 1);
		distance = "";
	}
	else
	{
		int incre = m_Timeincrement_place++;
		for (auto resuStart : Start_TimeSequence) {
			resuStart = "1900.01.01 " + resuStart;
			boost::posix_time::time_duration get_StartTime(boost::posix_time::time_from_string(resuStart).time_of_day());

			std::string houhr_to_string = std::to_string(get_StartTime.hours());
			std::string minute_to_string = std::to_string(get_StartTime.minutes());

			for (int i = 2 - houhr_to_string.size(); i > 0; i--) { houhr_to_string = "0" + houhr_to_string; }
			for (int i = 2 - minute_to_string.size(); i > 0; i--) { minute_to_string = "0" + minute_to_string; }

			std::string s_Time = houhr_to_string + ":" + minute_to_string;

			putText(m_Img, s_Time, Point(232, 240 + (40 * incre)), FONT_HERSHEY_DUPLEX, 1, Scalar(0), 1);

			for (auto resuEnd : End_TimeSequence) {
				resuEnd = "1900.01.01 " + resuEnd;
				boost::posix_time::time_duration get_EndTime(boost::posix_time::time_from_string(resuEnd).time_of_day());

				std::string e_houhr_to_string = std::to_string(get_EndTime.hours());
				std::string e_minute_to_string = std::to_string(get_EndTime.minutes());

				for (int i = 2 - e_houhr_to_string.size(); i > 0; i--) { e_houhr_to_string = "0" + e_houhr_to_string; }
				for (int i = 2 - e_minute_to_string.size(); i > 0; i--) { e_minute_to_string = "0" + e_minute_to_string; }

				std::string e_Time = e_houhr_to_string + ":" + e_minute_to_string;

				putText(m_Img, e_Time, Point(372, 240 + (40 * incre)), FONT_HERSHEY_DUPLEX, 1, Scalar(0), 1);
				break;
			}
		}
		Start_TimeSequence.clear();
		End_TimeSequence.clear();
		putText(m_Img, distance, Point(320, 240 + (40 * incre)), FONT_HERSHEY_DUPLEX, 1, Scalar(0), 1);
	}

}
void
Imagehandling::Image::Write_Img_TimeDifference(std::list<std::string> Start_TimeSequence, std::list<std::string> End_TimeSequence) {

	if (Start_TimeSequence.empty() || End_TimeSequence.empty())
	{
		putText(m_Img, " ", Point(480, 240), FONT_HERSHEY_DUPLEX, 1, Scalar(0), 1);
	}
	else
	{
		for (auto resuStart : Start_TimeSequence) {
			resuStart = "1900-01-01 " + resuStart;
			boost::posix_time::ptime get_StartTime(boost::posix_time::time_from_string(resuStart));

			for (auto resuEnd : End_TimeSequence) {
				resuEnd = "1900-01-01 " + resuEnd;
				boost::posix_time::ptime get_EndTime(boost::posix_time::time_from_string(resuEnd));

				boost::posix_time::time_duration TimeDifference = get_EndTime - get_StartTime;
				
				std::string houhr_to_string = std::to_string(TimeDifference.hours());
				std::string minute_to_string = std::to_string(TimeDifference.minutes());

				for (int i = 2 - houhr_to_string.size(); i > 0; i--) { houhr_to_string = "0" + houhr_to_string; }
				for (int i = 2 - minute_to_string.size(); i > 0; i--) { minute_to_string = "0" + minute_to_string; }

				std::string TimeDifference_to_string =  "(" + houhr_to_string + "," + minute_to_string + "Std.)";

				putText(m_Img, TimeDifference_to_string, Point(475, 240 + (40 * m_Timeincrement_place)), FONT_HERSHEY_DUPLEX, 0.8, Scalar(0), 0);
				break;
			}
		}
		Start_TimeSequence.clear();
		End_TimeSequence.clear();
	}

}

void 
Imagehandling::Image::Write_Img_Room_Designstion(std::string RoomDesignstion) {
	Check_Error();
	putText(m_Img, "Naechste Termine", Point(2, 200), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 0, 0), 2);
	putText(m_Img, RoomDesignstion, Point(2, 50), FONT_HERSHEY_DUPLEX, 1.4, Scalar(0, 0, 0), 2);
}

void 
Imagehandling::Image::Write_Img_Room_StateTime(std::vector<std::string>  Start_Time, std::vector<std::string>  End_Time, bool state) {
	Check_Error();

	std::pair<std::vector<std::string>, std::vector<std::string>>pair_st_en;
	std::list<std::string> mergen_st_en;
	std::string end_result;
	{
	time_t now = time(0);
	tm* ltm = localtime(&now);

	std::string day_to_string = std::to_string(ltm->tm_mday);
	std::string monath_to_string = std::to_string(ltm->tm_mon + 1);
	std::string year_to_string = std::to_string(ltm->tm_year + 1900);

	for (int i = 2 - day_to_string.size(); i > 0; i--) { day_to_string = "0" + day_to_string; }
	for (int i = 2 - monath_to_string.size(); i > 0; i--) { monath_to_string = "0" + monath_to_string; }
	for (int i = 2 - year_to_string.size(); i > 0; i--) { year_to_string = "0" + year_to_string; }

	std::string localTime = day_to_string + "." + monath_to_string + "." + year_to_string;
	putText(m_Img, "Aktuell - " + localTime, Point(2, 110), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 0, 0), 2);
	}

	std::vector<std::string> s_Time, e_Time;

	if (!Start_Time.empty() && !End_Time.empty())
	{
		std::string s_houhr_to_string;
		std::string s_minute_to_string;

		std::string e_houhr_to_string ;
		std::string e_minute_to_string;

		for (size_t i = 0; i < Start_Time.size(); i++)
		{
			boost::posix_time::time_duration get_StartTime(boost::posix_time::time_from_string("1900.01.01 " + Start_Time[i]).time_of_day());
			s_houhr_to_string = std::to_string(get_StartTime.hours());
			s_minute_to_string = std::to_string(get_StartTime.minutes());

			for (int i = 2 - s_houhr_to_string.size(); i > 0; i--) { s_houhr_to_string = "0" + s_houhr_to_string; }
			for (int i = 2 - s_minute_to_string.size(); i > 0; i--) { s_minute_to_string = "0" + s_minute_to_string; }
			s_Time.push_back(s_houhr_to_string + ":" + s_minute_to_string);
		}
		for (size_t i = 0; i < End_Time.size(); i++)
		{
			boost::posix_time::time_duration get_EndtTime(boost::posix_time::time_from_string("1900.01.01 " + End_Time[i]).time_of_day());
			e_houhr_to_string = std::to_string(get_EndtTime.hours());
			e_minute_to_string = std::to_string(get_EndtTime.minutes());


			for (int i = 2 - e_houhr_to_string.size(); i > 0; i--) { e_houhr_to_string = "0" + e_houhr_to_string; }
			for (int i = 2 - e_minute_to_string.size(); i > 0; i--) { e_minute_to_string = "0" + e_minute_to_string; }
			e_Time.push_back(e_houhr_to_string + ":" + e_minute_to_string);
		}
		
	}	
	pair_st_en = std::make_pair(s_Time, e_Time);
	for (size_t i = 0; i < pair_st_en.first.size(); i++) { mergen_st_en.push_back(pair_st_en.first[i] + " - " + pair_st_en.second[i]); }
	mergen_st_en.sort();
	
	for (auto result : mergen_st_en) { end_result = result; break; }
	switch (state)
	{
		case true:
			putText(m_Img, ".", Point(500, 55), FONT_HERSHEY_DUPLEX, 15, Scalar(0, 0, 255), 12);
			putText(m_Img, end_result , Point(2, 150), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 0, 255), 1);
			break;
		case false:
			putText(m_Img, "Frei ", Point(2, 150), FONT_HERSHEY_DUPLEX, 1, Scalar(0), 1);
			putText(m_Img, " ", Point(2, 150), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 0, 255), 1);
			break;
	default:
		break;
	}

}
void
Imagehandling::Image::set_place(int first, int second) {
	m_Dateincrement_place = first;
	m_Timeincrement_place = second;
}
void 
Imagehandling::Image::save_Img()
{
	Check_Error();
	if (m_Path.empty())
	{
		m_Path = "unknown.jpg";
	}
	bool savestate = imwrite(m_Path, m_Img);

	if (savestate == false) {
		std::cout << "Mission - Saving the image, FAILED" << std::endl;
		exit(0);
	}
}

void 
Imagehandling::Image::read_Img() {
	m_Img = imread(m_Path + m_filename);
	Check_Error();
}

void 
Imagehandling::Image::show_img(){
	Check_Error();
	namedWindow("DoorPlate", WINDOW_AUTOSIZE);
	imshow("DoorPlate", m_Img);
	
	if (waitKey(0) == 7)
	{
		exit(0);
	}
	
	destroyAllWindows();
}

