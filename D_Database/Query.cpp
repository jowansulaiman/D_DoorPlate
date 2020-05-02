#include "Query.h"
#include <vector>

Database::_Statement::_Statement(const char* Query) : m_Query(Query) {}
Database::_Statement::~_Statement() { }


std::list<char const*> 
Database::_Statement::StartDateTime() {
    Connect();
    std::list<char const*>result_List;
    const char*  Query = "select Start_DateTime from reservation";

    int state = mysql_real_query(m_Connect, Query, strlen(Query));
    Check_Error();

    if (state) {
        std::cout << ("Die Anweisung(en) Konnte(n) nicht ausgeführt werden. ") << std::endl;
        mysql_close(m_Connect);
        exit(0);
    }
    m_Result = mysql_store_result(m_Connect);
    while ((m_Row = mysql_fetch_row(m_Result))) {
        result_List.push_back(m_Row[0]);
    }
    mysql_free_result(m_Result);
    return result_List;
}

std::list<char const*>
Database::_Statement::EndDateTime() {
    Connect();
    std::list<char const*>result_List;
    const char* Query = "select Start_DateTime from reservation";

    int state = mysql_real_query(m_Connect, Query, strlen(Query));
    Check_Error();

    if (state) {
        std::cout << ("Die Anweisung(en) Konnte(n) nicht ausgeführt werden. ") << std::endl;
        mysql_close(m_Connect);
        exit(0);
    }
    m_Result = mysql_store_result(m_Connect);
    while ((m_Row = mysql_fetch_row(m_Result))) {
        result_List.push_back(m_Row[0]);
        //i++;
    }
    mysql_free_result(m_Result);
    return result_List;
}

bool
Database::_Statement::is_cancelled() {
    Connect();
    bool result_List = false;
    const char* Query = "select id_cancelled from reservation";

    int state = mysql_real_query(m_Connect, Query, strlen(Query));
    Check_Error();

    if (state) {
        std::cout << ("Die Anweisung(en) Konnte(n) nicht ausgeführt werden. ") << std::endl;
        mysql_close(m_Connect);
        exit(0);
    }
    m_Result = mysql_store_result(m_Connect);
    while ((m_Row = mysql_fetch_row(m_Result))) {
        result_List=m_Row[0];
    }
    mysql_free_result(m_Result);
    return result_List;
}

std::pair<std::list<int>, std::list<const char*>>
Database::_Statement::rooms() {
  
    
   Connect();
   std::list<int>room_id;
   std::list<const char*>room_name;
   const char* Query = "select room_id, Designstion from meetingroom";
   int state = mysql_real_query(m_Connect, Query, strlen(Query));
   Check_Error();

   if (state) {
       std::cout << ("Die Anweisung(en) Konnte(n) nicht ausgeführt werden. ") << std::endl;
       mysql_close(m_Connect);
       exit(0);
   }
   m_Result = mysql_store_result(m_Connect);
   while ((m_Row = mysql_fetch_row(m_Result))) {
       room_id.push_back(std::stoi(m_Row[0]));
       room_name.push_back(m_Row[1]);
   }
   
   mysql_free_result(m_Result);
   return std::make_pair(room_id, room_name);
}

