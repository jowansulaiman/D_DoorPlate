//#ifndef D_Database
//#define D_Database
//
//#include <iostream>
//#include <windows.h>
//#include <sqlext.h>
//#include <sqltypes.h>
//#include <sql.h>
//#include <tuple>
//
//namespace Database{
//	class Interconnect {
//	private:
//		SQLCHAR SQLState[1024];
//		SQLCHAR message[1024];
//		SQLRETURN retCode;
//		SQLCHAR retConString[1024]; // Conection string
//		const char* ConString[256];
//		SQLHANDLE SQLConnectionHandle;
//
//	protected: 
//		SQLHANDLE SQLEnvHandle;
//
//
//	public:
//		Interconnect();
//		virtual ~Interconnect();
//		virtual SQLHANDLE getconn();
//		virtual void showSQLError(unsigned int , const SQLHANDLE& );
//		//void statment();
//		
//	};
//	
//	class Stat: public Interconnect
//	{
//	private:
//		SQLHANDLE SQLStatementHandle;
//		const char* SQLQuery[266];
//		const char *m_name[256];
//		int m_id;
//
//	public:
//		Stat();
//		Stat(int id, const char *room);
//		~Stat() override;
//		void statment();
//		
//	};
//}
//
//#endif // !D_Database
