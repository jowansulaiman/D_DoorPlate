#ifndef DTS_Database_H
#define DTS_Database_H

#include <sys/timeb.h>

#if defined(HAS_MSQL) 
#include <msql.h > 
#elif defined(HAS_MYSQL) 
#include <mysql.h>
#endif 

#include <iostream>
#include <map>
#include <mysql.h>

namespace Database {

    class  _Connection {

    private:
        const char* m_Host;
        const char* m_User;
        const char* m_Pass;
        const char* m_DB;


    protected:
        MYSQL* m_Connect;
        
        _Connection();
        virtual ~_Connection();
        _Connection(const char*, const char*, const char*, const char*);
        _Connection(const char*, const char*);

        void Check_Error();
        void virtual Connect();
    public:
        void Disconnect();
        void select_database(const char* db);
    };  // end of class Conn

}
#endif  // !DTS_Database_H
