#include "Query.h"
#include <vector>


Database::_Query::_Query() {}
Database::_Query::~_Query() { }


std::list<std::string>
Database::_Query::get_StartDateTime(int room_id) {
    Connect();
    std::list<std::string>result_List;
    std::string Query = "select Start_DateTime from reservation where _room_id = " + std::to_string(room_id) + 
        "  and is_deleted != 1 and id_cancelled !=1 GROUP BY Start_DateTime, end_DateTime  order by  Start_DateTime asc ";

    int state = mysql_real_query(m_Connect, Query.c_str(), strlen(Query.c_str()));
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

std::list<std::string>
Database::_Query::get_EndDateTime(int room_id) {
    Connect();
    std::list<std::string> result_List;
    std::string Query = "select end_DateTime from reservation where _room_id = " + std::to_string(room_id) +
        "  and is_deleted != 1 and id_cancelled !=1 GROUP BY Start_DateTime, end_DateTime order by  Start_DateTime asc ";
  
    int state = mysql_real_query(m_Connect, Query.c_str(), strlen(Query.c_str()));
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

std::string
Database::_Query::get_BoardID(int room_id) {
    Connect();
    std::string first_result;

    std::string Query =  " select board_id from meetingroom where room_id="+ std::to_string(room_id);

    int state = mysql_real_query(m_Connect, Query.c_str(), strlen(Query.c_str()));
    Check_Error();

    if (state) {
        std::cout << ("Die Anweisung(en) Konnte(n) nicht ausgeführt werden. ") << std::endl;
        mysql_close(m_Connect);
        exit(0);
    }
    m_Result = mysql_store_result(m_Connect);
    while ((m_Row = mysql_fetch_row(m_Result))) {
        first_result= std::stoi(m_Row[0]);
    }
    mysql_free_result(m_Result);
    return first_result;
}

std::pair<std::list<int>, std::list<const char*>>
Database::_Query::rooms() {
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

void
Database::_Query::delete_reservation(int roomid, int deleval, std::string start, std::string end) {
    Connect();
    int first_result;
    int second_result;

    std::string Query = "update reservation set is_deleted =" + std::to_string(deleval) + " where _Room_ID =" + std::to_string(roomid) + " and Start_DateTime = '" + start + "' and end_DateTime =' " + end + "'";
     
    int state = mysql_real_query(m_Connect, Query.c_str(), strlen(Query.c_str()));
    Check_Error();

    if (state) {
        std::cout << ("Die Anweisung(en) Konnte(n) nicht ausgeführt werden. ") << std::endl;
        mysql_close(m_Connect);
        exit(0);
    }
}
