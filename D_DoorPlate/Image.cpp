#include<iostream>
#include <fstream>
#include "Image.h"
#include <opencv.hpp>


using namespace cv;


Imagehandling::Image::Image():m_filename("Türschild.png"){  }

Imagehandling::Image::Image(std::string filename, std::string path):
	 m_filename(filename), m_Path(path)  { }

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
	remove(filepath.c_str());
}

void
Imagehandling::Image::Write_Img_DateSequence(std::string DateSequence) {
	Check_Error();
	if (DateSequence.empty())
	{
		DateSequence = "keine Reservierung vorhanden";
		putText(m_Img, DateSequence, Point(2, 240), FONT_HERSHEY_DUPLEX, 1, Scalar(0), 1);
	}
	else
	{
		for (int i = 0; i < 3; i++)
			putText(m_Img, DateSequence, Point(2, 240 + (40 * i)), FONT_HERSHEY_DUPLEX, 1, Scalar(0), 1);
	}
	
}

void
Imagehandling::Image::Write_Img_TimeSequence(std::string Start_TimeSequence, std::string End_TimeSequence) {
	Check_Error();
	std::string distance = " - ";
	putText(m_Img, "Naechste Termine", Point(2, 200), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 0, 0), 2);

	if (Start_TimeSequence.empty() || End_TimeSequence.empty())
	{
		Start_TimeSequence = " ";
		End_TimeSequence = " ";
		distance = "";
	}
	for (int i = 0; i < 3; i++) {
		putText(m_Img, Start_TimeSequence, Point(232, 240 + (40 * i)), FONT_HERSHEY_DUPLEX, 1, Scalar(0), 1);
		putText(m_Img, distance, Point(320, 240 + (40 * i)), FONT_HERSHEY_DUPLEX, 1, Scalar(0), 1);
		putText(m_Img, End_TimeSequence, Point(372, 240 + (40 * i)), FONT_HERSHEY_DUPLEX, 1, Scalar(0), 1);
	}
}

void 
Imagehandling::Image::Write_Img_Room_Designstion(std::string RoomDesignstion) {
	Check_Error();
	putText(m_Img, RoomDesignstion, Point(2, 50), FONT_HERSHEY_DUPLEX, 1.4, Scalar(0, 0, 0), 2);
}

void 
Imagehandling::Image::Write_Img_Room_StateTime(std::string Start_Time, std::string End_Time, bool state) {
	Check_Error();

	time_t now = time(0);
	tm* ltm = localtime(&now);
	std::string localTime = std::to_string(ltm->tm_mday) + "." + std::to_string(ltm->tm_mon + 1) + "." + std::to_string(ltm->tm_year + 1900);
	
	putText(m_Img, "Aktuell - " + localTime, Point(2, 110), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 0, 0), 2);
	switch (state)
	{
		case true:
			putText(m_Img, ".", Point(500, 55), FONT_HERSHEY_DUPLEX, 15, Scalar(0, 0, 255), 12);
			putText(m_Img, Start_Time + " - " + End_Time, Point(2, 150), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 0, 255), 1);
			break;
		case false:
			putText(m_Img, "Frei ", Point(2, 150), FONT_HERSHEY_DUPLEX, 1, Scalar(0), 1);
	default:
		break;
	}

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

