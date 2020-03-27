#include<iostream>
#include <fstream>
#include "Image.h"
#include <opencv.hpp>
#include <string.h>
#include <Windows.h>
#include <fstream>

using namespace cv;


ImageVerarbeitung::Image::Image():m_filename("Türschild.png"), txt("Deichstrasse"){  }
ImageVerarbeitung::Image::Image(std::string f):txt(f), m_filename("Türschild.png") {  }
ImageVerarbeitung::Image::~Image() { std::cout << "dis"; }

void ImageVerarbeitung::Image::showErrormsg(std::string msg, std::string bezeichnung) {
	std::cout << "Error: " << msg << bezeichnung << std::endl;
	exit(0);
}

void ImageVerarbeitung::Image::readImg()
{
	image = imread(m_filename);
	if (image.data == 0)
	{
		showErrormsg("Check if ",m_filename + " exists in the folder.");
	}
	/*putText(image, *_name, Point(90, 50), FONT_HERSHEY_DUPLEX, 1, Scalar(102, 20, 0), 2);
	*/
	std::string txt1 = "20.01.2020";
	std::string txt2 = "Aktuell - ";
	std::string txt3 = "23:30 - 23:59";
	std::string txt4 = "Naechste Termine";
	std::string txt5 = "-";
	putText(image, txt, Point(2, 50/*+(i*60)*/), FONT_HERSHEY_DUPLEX, 1.4, Scalar(0, 0, 0), 2);
	putText(image, txt1, Point(160, 110), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 0, 0), 2);
	putText(image, txt2, Point(2, 110), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 0, 0), 2);
	putText(image, txt3, Point(2, 150), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 0, 0), 1);
	putText(image, txt4, Point(2, 200), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 0, 0), 2);

	putText(image, txt5, Point(200, 200), FONT_HERSHEY_DUPLEX, 15, Scalar(0, 0, 0), 12);
	for (int i=0;i<3;i++)
		putText(image, txt1+"     " +txt3, Point(2, 240 +(40*i)), FONT_HERSHEY_DUPLEX, 1, Scalar(102, 20, 0), 1);

}

void ImageVerarbeitung::Image::showWin(){
namedWindow("DoorPlate", WINDOW_AUTOSIZE);
imshow("DoorPlate", image);
if (waitKey(0) == 7)
{
	exit(0);
} 
 destroyAllWindows();
}


void ImageVerarbeitung::Image::convImg() {
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
	std::string str;
	__if_not_exists(imgpath) {
		perror("Image wurde nicht: ");
		return -1;
	}
	__if_exists(imgpath) {
		system(re);
		std::rename("image.xbm", hfile);
	}
	while (getline(file, buffer)) {		
		wfile << buffer;
		std::cout << buffer;
	}
	file.close();

}


void ImageVerarbeitung::Image::findAndReplaceAll(std::string& data, std::string toSearch, std::string replaceStr)
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


