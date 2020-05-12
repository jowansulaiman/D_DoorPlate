#include "Connection.h"
#include <string.h>
#include <iostream>
#include <sstream>


Database::_Connection::_Connection(const char* Host, const char* User, const char* Pass,
                     const char* DB)
    : m_Host(Host),
      m_User(User),
      m_Pass(Pass),
      m_DB(DB),
      m_Connect(mysql_init(m_Connect)) {}

Database::_Connection::_Connection(const char* Host, const char* DB): m_Host(Host),m_DB(DB), m_Connect(mysql_init(m_Connect)) {}

Database::_Connection::_Connection() : m_Host("localhost"),
m_User("root"),
m_Pass("test112"),
m_DB("dts"),
m_Connect(mysql_init(m_Connect)) {}

Database::_Connection::~_Connection() { }

void
Database::_Connection::Check_Error() {
  if (mysql_errno(m_Connect) != NULL) {
    std::cout << "Fehler: " << mysql_errno(m_Connect) << " " << mysql_error(m_Connect)
              << std::endl;
    exit(EXIT_FAILURE);
  }
}

void 
Database::_Connection::Connect() {
  m_Connect = mysql_init(m_Connect);
  Check_Error();
  mysql_real_connect(m_Connect, m_Host, m_User, m_Pass, m_DB, 0, 0, 0);
 }

void 
Database::_Connection::Disconnect() {
   if (m_Connect > 0) {
     mysql_close(m_Connect);
     std::cout << std::endl  << "The connection to "<< m_DB <<" has been disconnected." << std::endl;
   } 
} 

void 
Database::_Connection::select_database(const char *db) {
    Connect();
    mysql_select_db(m_Connect, db);
    Check_Error();
}

// end of class Conn


