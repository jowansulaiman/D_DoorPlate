#ifndef DST_Query_H
#define DST_Query_H
#include "Connection.h"
#include <iostream>
#include <list>
#include <string>

namespace Database {

    //template <typename T>
    
    class _Statement : public _Connection {
    private:
        const char* m_Query;
        MYSQL_RES* m_Result;
        MYSQL_ROW m_Row;

    public:
        std::list<std::string> StartDateTime(int room_id);
        std::list<std::string> EndDateTime(int room_id);
        std::pair<std::list<int>, std::list<const char*>> rooms();
        void delete_reservation(int roomid, int delevla, std::string start, std::string end);

     std::string get_BoardID(int room_id);
    public:
        _Statement();
        virtual ~_Statement();
    };  // end of class Statement


}  // namespace Database


#endif // !DST_Query_H
