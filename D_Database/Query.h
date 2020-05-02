#ifndef DST_Query_H
#define DST_Query_H
#include "Connection.h"
#include <iostream>
#include <list>
#include <string>
#include <malloc.h>
#include <stdlib.h>

namespace Database {

    //template <typename T>
    
    class _Statement : public _Connection {
    private:
        const char* m_Query;
        MYSQL_RES* m_Result;
        MYSQL_ROW m_Row;

    public:
        std::list<char const*> StartDateTime();
        std::list<char const*> EndDateTime();
        bool is_cancelled();
        std::pair<std::list<int>, std::list<const char*>> rooms();
        _Statement(const char*);
        virtual ~_Statement();
    };  // end of class Statement


}  // namespace Database

#endif // !DST_Query_H
