#include "Database.h"



Database::Connection::Connection()
    : m_Server("localhost"),
      m_User("root"),
      m_Pass("test112"),
      m_DB("db"),
      m_Connect(mysql_init(m_Connect)) {}


Database::Connection::Connection(const char* Server, const char* User, const char* Pass,
                     const char* DB)
    : m_Server(Server),
      m_User(User),
      m_Pass(Pass),
      m_DB(DB),
      m_Connect(mysql_init(m_Connect)) {}

Database::Connection::~Connection() { std::cout << "dis"; }


void Database::Connection::Check_Error() {
  if (mysql_errno(m_Connect) != NULL) {
    std::cout << "Fehler: " << mysql_errno(m_Connect) << " " << mysql_error(m_Connect)
              << std::endl;
    exit(EXIT_FAILURE);
  }
}

void inline Database::Connection::Connect() {
  Check_Error();     /* mit dem Server verbinden */
  mysql_real_connect(m_Connect, m_Server, m_User, m_Pass, m_DB, 0, 0, 0);
  Check_Error();
 }
void Database::Connection::Disconnect() {
   if (m_Connect > 0) {
     mysql_close(m_Connect);
   } 
}
  

// end of class Conn


Database::Statement::Statement()
    : Connection(),
      m_Query("select * from kunde") { }

Database::Statement::Statement(const char* Query) : m_Query(Query) {}
Database::Statement::~Statement() { }
std::pair<char const*, char const*> Database::Statement::Query() {

    Connect();
    int state;
    state = mysql_query(m_Connect, "SELECT  * FROM kunde order by id desc");
    if (state != 0) {
        printf(mysql_error(m_Connect));
        exit(EXIT_SUCCESS);
    }
    /* must call mysql_store_result() before we can issue any * other query
         calls */
    result = mysql_store_result(m_Connect);
    /*std::cout << "Rows: " << mysql_num_rows(result)
              << std::endl;*/ /* process each row in the result set */
    const char* arr[3];
    while ((row = mysql_fetch_row(result)) != NULL) {
        return std::make_pair(row[0], row[1]);
    }
    // {
    // /* std::cout << "id: " << (row[0] ? row[0] : "NULL") << " "
    //            << "val : " << (row[1] ? row[1] : "NULL") << std::endl;*/    

    //    arr[] = row[1];
    //
    //}       
    /* free the result set */
    mysql_free_result(result);


    printf("Done.\n");
}