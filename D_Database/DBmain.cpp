

#include <iostream>

#include "Database.h"
int main(int argc, char *argv[]) {
  Database::Connection c;
  //c.Connect();

  std::cout << c.Query().second;
 /*
              

  Database::Statement st;
  st.get_Data();*/
}