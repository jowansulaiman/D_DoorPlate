#include <iostream>
#include "DateTime.h"
#include "DBConn.h"
#include <io.h>
#include <Windows.h>
#include "Image.h"
#include <fstream>
#include <ostream>
#include <string.h>
#include <stdio.h>
void findAndReplaceAll(std::string&, std::string, std::string);

int main()
{
	std::string old_txt = "#define image_width 640";
	std::string old_txt1 = "image_height 384";//static char image_bits[] = {
	std::string old_txt2 = "static char image_bits[] = {";//
	char hfile[] = "BitmapExamples.h";
	std::string txt;
	std::ifstream file;
	file.open(hfile, std::ios::in);
	while (getline(file, txt))
	{
		findAndReplaceAll(txt, old_txt, "");
		findAndReplaceAll(txt, old_txt1, "");
		findAndReplaceAll(txt, old_txt1, "");
		std::cout << txt;
	}
}

void findAndReplaceAll(std::string& data, std::string toSearch, std::string replaceStr){
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
