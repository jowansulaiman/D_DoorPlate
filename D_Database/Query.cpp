#include "Query.h"
#include <vector>

Database::_Statement::_Statement(const char* Query) : m_Query(Query) {}
Database::_Statement::~_Statement() { }

std::list<char const*> Database::_Statement::Query() {
    Connect();
    //const char* txt[3];
    std::list<char const*>result_List;
    int i = 0;
    int state = mysql_real_query(m_Connect, m_Query, strlen(m_Query));
    Check_Error();

    if (state) {
        std::cout << ("Die Anweisung(en) Konnte(n) nicht ausgeführt werden. ") << std::endl;
        mysql_close(m_Connect);
        exit(0);
    }
    m_Result = mysql_store_result(m_Connect);
    while ((m_Row = mysql_fetch_row(m_Result))) {
       result_List.push_back(m_Row[3]);
        //i++;
    }
    mysql_free_result(m_Result);
    return result_List;
}

//std::map<int, int, int, std::pair<int, int>> Database::Statement::getDateTime() {
//    Connect();
//    mysql_real_query(m_Connect, m_Query, strlen(m_Query));
//    Check_Error();
//    result = mysql_store_result(m_Connect);
//    Check_Error();
//
//}