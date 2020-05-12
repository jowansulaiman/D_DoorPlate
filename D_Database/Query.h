#ifndef DST_Query_H
#define DST_Query_H
#include "Connection.h"
#include <iostream>
#include <list>
#include <string>

namespace Database {

    //template <typename T>
    
    class _Query : public _Connection {
    private:
        const char* m_Query;
        MYSQL_RES* m_Result;
        MYSQL_ROW m_Row;

    public:
        std::list<std::string> get_StartDateTime(int room_id);
        std::list<std::string> get_EndDateTime(int room_id);
        std::pair<std::list<int>, std::list<const char*>> rooms();
        void delete_reservation(int roomid, int delevla, std::string start, std::string end);

     std::string get_BoardID(int room_id);
    public:
        _Query();
        virtual ~_Query();
    };  // end of class Statement


}  // namespace Database


#endif // !DST_Query_H
