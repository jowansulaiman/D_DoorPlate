#ifndef  DTS_Raum_H
#define DTS_Raum_H

#include <map>
#include <iostream>



class _Room {
private:
	int m_RoomID;
	int m_BoardID;

	std::string m_Description;
	
public:
	_Room(int ID, std::string Description, int BoardID);
	_Room(std::string Description, int BoardID);
	_Room(int BoardID);
	~_Room();	

	std::map<int, std::string>get_Room();
	int get_BoardID();
};
#endif // ! DTS_Raum_H
