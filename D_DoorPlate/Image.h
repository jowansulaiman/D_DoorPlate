#ifndef D_Image
#define D_Image
#include <opencv.hpp>

namespace ImageVerarbeitung {

class Image 
{
private:
	std::string m_filename;
	cv::Mat image;
	void convImg();
	void showErrormsg(std::string, std::string);
	void findAndReplaceAll(std::string&, std::string, std::string);
	std::string txt ;
	int id;
public:
	Image();
	Image(std::string);
	~Image();

	void readImg();
	void showWin();
};

}

#endif // !D_Image
