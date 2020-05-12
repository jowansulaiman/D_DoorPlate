#ifndef D_Image
#define D_Image
#include <iostream>
#include <opencv.hpp>
#include<boost/algorithm/string.hpp>
#include <istream>
#include <ostream>
#include <boost/range/adaptors.hpp>
#include<boost/iostreams/seek.hpp>
#include <boost/range/algorithm.hpp>

namespace Imagehandling {
	
	class Image 
	{
	private:
		std::string m_Path;
		std::string m_filename;
		cv::Mat m_Img;
		int m_Dateincrement_place;
		int m_Timeincrement_place;
		void Check_Error();
		
	public:
	Image(std::string filename, std::string path);
	Image();

	~Image();

	void Convert_Img();
	void read_Img();
	void Write_Img_DateSequence(std::list<std::string> DateSequence);
	void Write_Img_TimeSequence(std::list<std::string> Start_TimeSequence, std::list<std::string> End_TimeSequence);
	void Write_Img_Room_Designstion(std::string RoomDesignstion);
	void Write_Img_Room_StateTime(std::string  Start_Time,std::string End_Time, bool state);

	void set_place(int first, int second);
	void save_Img();
	void show_img();

};


}

#endif // !D_Image
