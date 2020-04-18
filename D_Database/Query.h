#ifndef DST_Query_H
#define DST_Query_H
#include "Connection.h"
#include <iostream>
#include <vector>

namespace Database {

    //template <typename T>
    
    class _Statement : public _Connection {
    private:
        const char* m_Query;
        MYSQL_RES* m_Result;
        MYSQL_ROW m_Row;

    public:
        std::pair<char const*, char const*> Query();
        _Statement(const char*);
        virtual ~_Statement();
    };  // end of class Statement


}  // namespace Database

#endif // !DST_Query_H
