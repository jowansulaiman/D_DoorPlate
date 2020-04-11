#ifndef D_Database
#define D_Database
#include <iostream>

#include <mysql.h>

namespace Database {

 class  Connection{
 private:
  const char *m_Host;
  const char *m_User;
  const char *m_Pass;
  const char *m_DB;

  void Check_Error();
  void Disconnect();
  
 protected:
     
     MYSQL* m_Connect;
     Connection();
     Connection(const char*, const char*, const char*, const char*);
     void inline Connect();
     virtual ~Connection();

};  // end of class Conn

 //***************************************************************************************//
 //***************************************************************************************//
 //***************************************************************************************//
 
class Statement : public Connection{
 private:
  const char *m_Query; 
  MYSQL_RES *result;
  MYSQL_ROW row;

 public:
     std::pair<char const*, char const*> Query();
     Statement();
     Statement(const char *);
     virtual ~Statement();
};  // end of class Statement
}  // namespace Database

#endif  // !D_Database
