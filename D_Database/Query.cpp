#include "Query.h"
#include <vector>

Database::_Statement::_Statement(const char* Query) : m_Query(Query) {}
Database::_Statement::~_Statement() { }

std::pair<char const*, char const*> Database::_Statement::Query() {

    Connect();
   /* select_database("db");*/

    int state = mysql_real_query(m_Connect, m_Query, strlen(m_Query));
    Check_Error();

    if (state) {
        std::cout << ("Die Anweisung(en) Konnte(n) nicht ausgeführt werden. ") << std::endl;
        mysql_close(m_Connect);
        exit(0);
    }
    m_Result = mysql_store_result(m_Connect);

    while ((m_Row = mysql_fetch_row(m_Result))) {
        mysql_free_result(m_Result);
        mysql_next_result(m_Connect);
        return std::make_pair(m_Row[0], m_Row[1]);

    }

}

//std::map<int, int, int, std::pair<int, int>> Database::Statement::getDateTime() {
//    Connect();
//    mysql_real_query(m_Connect, m_Query, strlen(m_Query));
//    Check_Error();
//    result = mysql_store_result(m_Connect);
//    Check_Error();
//
//}