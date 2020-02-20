#include <iostream>

#include "DateTime.h"
#include "Image.h"
#include <mysql.h>


#define SERVER "localhost"
#define USER "root"
#define PASSWORD "test112"
#define DATABASE "db"

using namespace std;
int main() {

  int qstate;
 
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
          if (txt == "jowan") {
            printf("ID: %s, name: %s\n", row[0], row[1]);
          }
        }
      } else {
        puts("faild");
      }
    } else {
      cout << "Connection Failed\n";
    }
  }
  // Replace MySQL query with your query
 
  ////std::string old_txt = "#define image_width 640\n#define image_height
   /// 384";//static char image_bits[] = {
   // std::string old_txt2 = "static char image_bits[] = {";//
   // char hfile[] = "BitmapExamples.h";

// std::string txt;
// std::ifstream file;
// file.open(hfile, std::ios::in);
//

// while (getline(file, txt))
//{
//
//	findAndReplaceAll(txt,old_txt, "");
//	//replaceWord(txt, old_txt, "");
//	std::cout << txt;
//}

// std::cout << "Old: " << old_txt << std::endl;
// old_txt.replace(0, 12, "as", 3);
// std::cout << "New: 2 " << old_txt << std::endl;
// old_txt1.replace(0, 12, "");
// std::cout << "New: " << old_txt1 << std::endl;

void findAndReplaceAll(std::string& data, std::string toSearch,
                       std::string replaceStr) {
  // Get the first occurrence
  size_t pos = data.find(toSearch);

  // Repeat till end is reached
  while (pos != std::string::npos) {
    // Replace this occurrence of Sub String
    data.replace(pos, toSearch.size(), replaceStr);
    // Get the next occurrence from the current position
    pos = data.find(toSearch, pos + replaceStr.size());
  }
}