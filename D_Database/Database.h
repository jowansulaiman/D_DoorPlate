#ifndef D_Database
#define D_Database
#include <iostream>

#include "mysql.h"

namespace Database {

class Connection {
 private:
  const char *m_Server;
  const char *m_User;
  const char *m_Pass;
  const char *m_DB;
  MYSQL *m_Connect;
  friend class Statement;

 public:
  Connection();
  Connection(const char *, const char *, const char *, const char *);
  void inline Connect();
  std::pair<char const *, char const *> Query();
  void Check_Error();
  void Disconnect();

 virtual ~Connection();
};  // end of class Conn

class Statement : public Connection {
 private:
  const char *m_Query; 
  MYSQL_RES *result;
  MYSQL_ROW row;
  MYSQL *m_Connect;
  int state;

 public:
  Statement();
  Statement(const char *);
  void get_Data();

  virtual ~Statement();
};  // end of class Statement

}  // namespace Database

#endif  // !D_Database
