#ifndef D_DBConn
#define D_DBConn
#include <iostream>
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
#include <string.h>

class DBConn {
private:
	SQLCHAR SQLState[1024];
	SQLCHAR message[1024];
	SQLHANDLE SQLEnvHandle;
	SQLHANDLE SQLConnectionHandle;
	SQLHANDLE SQLStatementHandle;
	SQLRETURN retCode;
	char SQLQuery[];
public:
	DBConn() {
		SQLEnvHandle = NULL;
		SQLConnectionHandle = NULL;
		SQLStatementHandle = NULL;
		retCode = 0;
	}
	SQLHANDLE getconn();
	void statment();
	void showSQLError(unsigned int handleType, const SQLHANDLE& handle);
};






#endif // !D_DBConn
