#include <iostream>
#include "DateTime.h"
#include "DBConn.h"

int main()
{
	DBConn db;
	db.getconn();
	db.statment();

}