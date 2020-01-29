#include<iostream>
#include <fstream>
#include "Image.h"
#include <opencv2/opencv.hpp>
#include <string.h>
#include <Windows.h>
#include <fstream>

using namespace std;
using namespace cv;
void image::readImg()
{
	Mat image;
	string file;
	file = *filename;
	image = imread(file);
	if (image.data == 0)
	{
		cout << "\n\nError..!!\n";
		cout << "\nCheck=>";
		cout << "\n1. Desired image is in the folder of the project";
		cout << "\n2. You have mentioned extension of an image file\n";
		exit(0);
	}


	putText(image, *name, Point(90, 50), FONT_HERSHEY_DUPLEX, 1, Scalar(102, 20, 0), 2);
	putText(image, *raum, Point(350, 50), FONT_HERSHEY_DUPLEX, 1, Scalar(102, 20, 0), 2);
	putText(image, *datum, Point(110, 250), FONT_HERSHEY_DUPLEX, 1, Scalar(102, 20, 0), 2);


	namedWindow("T�rschild", WINDOW_AUTOSIZE);
	imshow("T�rschild", image);
	if (waitKey(0) == 27)
	{
		exit(0);
	}
	destroyAllWindows();
}
void image::convImg() {
	char hfile[]= "BitmapExamples.h";
	char re[]= "magick image.png image.xbm";
	std::string old_txt = "#define image_width 640 #define image_height 384 static char image_bits[] = {";
		
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
		rename("image.xbm", hfile);
	}

	while (getline(file,buffer)) {
		wfile << buffer;
		findAndReplaceAll(buffer, old_txt, "");
		wfile << buffer;
		std::cout << buffer;
	}
	

	 file.close();

}
void image::findAndReplaceAll(std::string& data, std::string toSearch, std::string replaceStr)
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


