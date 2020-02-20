//
//#include "Database.h"
//#include <iostream>
//#include <windows.h>
//#include <sqlext.h>
//#include <sqltypes.h>
//#include <sql.h>
//
//Database::Interconnect::Interconnect() {
//	*ConString = "DRIVER={SQL Server}; SERVER=localhost, 1433; DATABASE=DT_Schild; UID=sa; PWD=test112;";
//}
//Database::Interconnect::~Interconnect() { }
//Database::Stat::Stat() {
//	*SQLQuery = "select * from Room";
//	SQLStatementHandle = NULL;
//	m_id = 0;
//	*m_name = "test";
//}
//Database::Stat::Stat(int id, const char *room)  {
//	m_id = id;
//	*m_name = room;
//}
//Database::Stat::~Stat(){ }
//
//SQLHANDLE Database::Interconnect::getconn() {
//	 
//	do {
//		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &SQLEnvHandle))
//		// Ordnet die Umwelt an
//			break;
//
//		if (SQL_SUCCESS != SQLSetEnvAttr(SQLEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))
//			// Setzt Attribute, die Aspekte von Umgebungen regeln
//			break;
//
//		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, SQLEnvHandle, &SQLConnectionHandle))
//			// Ordnet die Verbindung zu
//			break;
//
//		if (SQL_SUCCESS != SQLSetConnectAttr(SQLConnectionHandle, SQL_LOGIN_TIMEOUT, (SQLPOINTER)5, 0))
//			// Setzt Attribute, die Aspekte von Verbindungen regeln
//			break;
//		
//		switch (SQLDriverConnect(SQLConnectionHandle, NULL, (SQLCHAR*)*ConString, SQL_NTS, retConString, 1024, NULL, SQL_DRIVER_NOPROMPT)) {
//			// Stellt Verbindungen zu einem Treiber und einer Datenquelle her
//		case SQL_SUCCESS:
//			break;
//		case SQL_SUCCESS_WITH_INFO:
//			break;
//		case SQL_NO_DATA_FOUND:
//			showSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);
//			retCode = -1;
//			break;
//		case SQL_INVALID_HANDLE:
//			showSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);
//			retCode = -1;
//			break;
//		case SQL_ERROR:
//			showSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);
//			retCode = -1;
//			break;
//		default:
//			break;
//		}
//		if (retCode == -1)
//			break;
//	} while (false);
//	return SQLConnectionHandle;
//}
//void Database::Stat::statment() {
//	
//	do {
//		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, getconn(), &SQLStatementHandle))
//			// Ordnet die Erklärung zu
//			break;
//		if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLCHAR*)*SQLQuery, SQL_NTS)) {
//			// Führt eine vorbereitbare Erklärung aus
//			showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);
//			break;
//		}
//		else {
//			
//			while (SQLFetch(SQLStatementHandle) == SQL_SUCCESS) {
//				
//				// Holt den nächsten Rowset von Daten aus dem Ergebnis
//				SQLGetData(SQLStatementHandle, 1, SQL_C_DEFAULT, &m_id, sizeof(m_id), NULL);
//				SQLGetData(SQLStatementHandle, 2, SQL_C_DEFAULT, &m_name, sizeof(m_name), NULL);
//				
//				//// Ruft Daten für eine einzelne Spalte in der Ergebnismenge ab
//				//std::cout << "ID: " << m_id << ", Raum: " << m_name << std::endl;
//			}
//		}
//	} while (false);
//
//	SQLFreeHandle(SQL_HANDLE_STMT, SQLStatementHandle);
//	SQLDisconnect(getconn());
//	SQLFreeHandle(SQL_HANDLE_DBC, getconn());
//	SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvHandle);
//
//}
//
//void  Database::Interconnect::showSQLError(unsigned int handleType, const SQLHANDLE& handle)
//{
//	if (SQL_SUCCESS == SQLGetDiagRec(handleType, handle, 1, SQLState, NULL, message, 1024, NULL))
//		// Gibt die aktuellen Werte mehrerer Felder eines Diagnosesatzes zurück, der Fehler-, Warn- und Statusinformationen enthält
//		std::cout << "SQL driver message: " << message << "\nSQL state: " << SQLState << "." << std::endl;
//}
