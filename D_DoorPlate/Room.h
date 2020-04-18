#ifndef  D_Raum
#define D_Raum
#include "Image.h"



class _Room {
private:
	int m_RaumNr;
	std::string m_Description;
	
public:
	_Room();
	_Room(int, std::string);
	std::pair<std::int64_t, std::string>getRoom_ID_Name();
	~_Room();
	
};
#endif // ! D_Raum
