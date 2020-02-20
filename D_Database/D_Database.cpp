// D_Database.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <mysql.h>

using namespace std;
#define SERVER "localhost"
#define USER "root"
#define PASSWORD "test112"
#define DATABASE "db"
int qstate;
int main()
{
  MYSQL* connect;

  MYSQL_RES* res_set;
  MYSQL_ROW row;

  connect = mysql_init(0);
  connect = mysql_real_connect(connect, SERVER, USER, PASSWORD, DATABASE, 0, NULL, 0);

  if (connect) {
    cout << "Connection Succeeded\n";
    std::string query = "select * from kunde;";
    const char* q = query.c_str();
    qstate = mysql_query(connect, q);
    if (!qstate) {
      res_set = mysql_store_result(connect);
      while (row = mysql_fetch_row(res_set)) {
        std::string txt = row[0];
  
          printf("ID: %s, name: %s\n", row[0], row[1]);
      
      }
    } else {
      puts("faild");
    }
  } else {
    cout << "Connection Failed\n";
  }
}

// Programm ausführen: STRG+F5 oder "Debuggen" > Menü "Ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
