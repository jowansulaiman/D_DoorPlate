#include<iostream>
#include <fstream>
#include "Image.h"
#include<opencv2/opencv.hpp>


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
