#include <iostream>
#include "Raum.h"

Raum::Raum(int R_Nr, std::string Description):m_RaumNr(R_Nr), m_Description(Description){}
Raum::~Raum() {}
Raum::Raum() {
	m_RaumNr = NULL;
	m_Description = "";
}

bool Raum::checkRaum() {
	return true;
}