#ifndef  D_Raum
#define D_Raum
#include "Image.h"



class Raum {
private:
	int m_RaumNr;
	std::string m_Description;
	bool checkRaum();

public:
	Raum();
	Raum(int, std::string);
	~Raum();
	
};
#endif // ! D_Raum
