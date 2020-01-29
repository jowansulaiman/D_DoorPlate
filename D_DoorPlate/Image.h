#ifndef D_Image
#define D_Image

#include <iostream>
#include<opencv2/opencv.hpp>
#include <string.h>

class image
{
private:
	std::string* filename;
	std::string* name;
	std::string* raum;
	std::string* datum;

public:
	image() {
		filename = new std::string;
		name = new std::string;
		raum = new std::string;
		datum = new std::string;


		//*std::cout << "\nGeben Sie den Namen einer Bilddatei mit der Extension ein: ";
		//std::cin >> */
		//*filename = "wor.jpg";
		//std::cout << "\ngibt der Name: ";
		//std::cin >> *name;
		//std::cout << "\nwelcher Raum: ";
		//std::cin >> *raum;
		//std::cout << "\nDasDAtum: ";
		//std::cin >> *datum;
	}

	image(std::string f, std::string n, std::string r, std::string d) {
		filename = new std::string;
		name = new std::string;
		raum = new std::string;
		datum = new std::string;

		*filename = f;
		*name = n;
		*raum = r;
		*datum = d;
	}

	void readImg();
	void convImg();
	void findAndReplaceAll(std::string&, std::string, std::string);


	~image() {
		delete filename;
		delete name;
		delete raum;
		delete datum;
	}


};









#endif // !D_Image
