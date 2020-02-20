//#include<iostream>
//#include <fstream>
//#include "Image.h"
//#include <opencv2/opencv.hpp>
//#include <string.h>
//#include <Windows.h>
//#include <fstream>
//
//using namespace cv;
//
//
//Image::Image():m_filename("image.png"){  }
////Image::Image(std::string f) : m_filename(f) {  }
//Image::~Image() { }
//
//void Image::showErrormsg(std::string msg, std::string bezeichnung) {
//	std::cout << "Error: " << msg << bezeichnung << std::endl;
//	exit(0);
//}
//
//void Image::readImg()
//{
//	image = imread(m_filename);
//	if (image.data == 0)
//	{
//		showErrormsg("Check if ",m_filename + " exists in the folder.");
//	}
//	/*putText(image, *_name, Point(90, 50), FONT_HERSHEY_DUPLEX, 1, Scalar(102, 20, 0), 2);
//	putText(image, *_raum, Point(350, 50), FONT_HERSHEY_DUPLEX, 1, Scalar(102, 20, 0), 2);*/
//	std::string txt[4] = { "test","test1", "test2", "test3" };
//	for (int i = 0; i < 3; i++)
//	putText(image, txt[i], Point(110, 250+(i*60)), FONT_HERSHEY_DUPLEX, 2, Scalar(0, 0, 0), 2);
//}
//
//void Image::showWin(){
//namedWindow("DoorPlate", WINDOW_AUTOSIZE);
//imshow("DoorPlate", image);
//if (waitKey(0) == 7)
//{
//	exit(0);
//} 
// destroyAllWindows();
//}
//
//
//void Image::convImg() {
//	char hfile[]= "BitmapExamples.h";
//	char re[]= "magick image.png image.xbm";
//	std::string old_txt = "#define image_width 640\n" 
//						  " #define image_height 384\n" 
//						  "static char image_bits[] = {";
//		
//	std::string buffer;
//
//	std::ifstream file;
//	file.open(hfile, std::ios::in);
//	std::ofstream wfile;
//	wfile.open("BitmapExamples2.h");
//
//
//
//	char imgpath[] = "image.png";
//	std::string str;
//
//
//	__if_not_exists(imgpath) {
//		perror("Image wurde nicht: ");
//		return -1;
//	}
//	__if_exists(imgpath) {
//		system(re);
//		std::rename("image.xbm", hfile);
//	}
//
//	while (getline(file, buffer)) {
//		findAndReplaceAll(buffer, old_txt, "");
//		wfile << buffer;
//		std::cout << buffer;
//	}
//	
//
//	 file.close();
//
//}
//void Image::findAndReplaceAll(std::string& data, std::string toSearch, std::string replaceStr)
//{
//	// Get the first occurrence
//	size_t pos = data.find(toSearch);
//
//	// Repeat till end is reached
//	while (pos != std::string::npos)
//	{
//		// Replace this occurrence of Sub String
//		data.replace(pos, toSearch.size(), replaceStr);
//		// Get the next occurrence from the current position
//		pos = data.find(toSearch, pos + replaceStr.size());
//	}
//}
//
//
