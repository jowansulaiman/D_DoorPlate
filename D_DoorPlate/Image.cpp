#include<iostream>
#include <fstream>
#include "Image.h"
#include <opencv.hpp>


using namespace cv;


Imagehandling::Image::Image():m_filename("Türschild.png"), txt1("Deichstrasse"){  }
Imagehandling::Image::Image(std::string f):txt1(f), m_filename("Türschild.png") {  }
Imagehandling::Image::~Image() { std::cout << "dis"; }

void Imagehandling::Image::showErrormsg(std::string msg, std::string bezeichnung) {
	std::cout << "Error: " << msg << bezeichnung << std::endl;
	exit(0);
}

void Imagehandling::Image::readImg()
{
	m_Image = imread(m_filename);
	if (m_Image.data == 0)
	{
		showErrormsg("Check if ",m_filename + " exists in the folder.");
	}
	/*putText(image, *_name, Point(90, 50), FONT_HERSHEY_DUPLEX, 1, Scalar(102, 20, 0), 2);
	*/
	std::string txt = "Deichstrasse";
	std::string txt2 = "Aktuell - ";
	std::string txt3 = "23:30 - 23:59";
	std::string txt4 = "Naechste Termine";
	std::string txt5 = ".";
	putText(m_Image, txt, Point(2, 50/*+(i*60)*/), FONT_HERSHEY_DUPLEX, 1.4, Scalar(0, 0, 0), 2);
	putText(m_Image, txt1, Point(160, 110), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 0, 0), 2);
	putText(m_Image, txt2, Point(2, 110), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 0, 0), 2);
	putText(m_Image, txt3, Point(2, 150), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 0, 0), 1);
	putText(m_Image, txt4, Point(2, 200), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 0, 0), 2);

	putText(m_Image, txt5, Point(500, 55), FONT_HERSHEY_DUPLEX, 15, Scalar(0, 0, 0), 12);
	for (int i=0;i<3;i++)
		putText(m_Image, txt1+"     " +txt3, Point(2, 240 +(40*i)), FONT_HERSHEY_DUPLEX, 1, Scalar(102, 20, 0), 1);
	imwrite("ima.jpg",m_Image);
	//C:/Users/jowan/source/repos/killuahh/D_DoorPlate/D_DoorPlate/
	system("magick ima.jpg ima.xbm");
}

void Imagehandling::Image::showWin(){
namedWindow("DoorPlate", WINDOW_AUTOSIZE);
imshow("DoorPlate", m_Image);
if (waitKey(0) == 7)
{
	exit(0);
} 
 destroyAllWindows();
}


void Imagehandling::Image::convImg() {
	char hfile[]= "BitmapExamples.h";
	char re[]= "magick image.png image.xbm";
	std::string old_txt = "#define image_width 640\n" 
						  " #define image_height 384\n" 
						  "static char image_bits[] = {";
		
	std::string buffer;
	std::ifstream file;
	file.open(hfile, std::ios::in);
	std::ofstream wfile;
	wfile.open("BitmapExamples2.h");

	char imgpath[] = "image.png";
	
	while (getline(file, buffer)) {		
		wfile << buffer;
		std::cout << buffer;
	}
	file.close();

}


void Imagehandling::Image::findAndReplaceAll(std::string& data, std::string toSearch, std::string replaceStr)
{
	// Get the first occurrence
	size_t pos = data.find(toSearch);

	// Repeat till end is reached
	while (pos != std::string::npos)
	{
		// Replace this occurrence of Sub String
		data.replace(pos, toSearch.size(), replaceStr);
		// Get the next occurrence from the current position
		pos = data.find(toSearch, pos + replaceStr.size());
	}
}


