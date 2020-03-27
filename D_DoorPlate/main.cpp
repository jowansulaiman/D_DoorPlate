
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Image.h"
#include "Database.h"
#include <map>
#include <fstream>
#include <iostream>
#include <vector>
#include <thread>
#include <sql.h>
#include <http.h>




class artikel {
    int ley;
    std::string name;
public:
    artikel(int k):ley(k){}
  
    int getkez() {
        return ley;

    }
    void print() {
        std::cout << "key: " << ley << std::endl;
    }};
int artikel::id = 0;

// Driver code
int DisplayResourceNAMessageBox();
void print(int n) {
    std::cout << n;
}
int main()
{
    
    //DisplayResourceNAMessageBox();
}
int DisplayResourceNAMessageBox()
{
tetyt:
    HWND hwnf = FindWindow(NULL, "Calculator");
    int msgboxID = MessageBoxA(
        hwnf, (LPCSTR)L"Resource not available\nDo you want to try again?",
        (LPCSTR)L"Account Details",
        MB_ICONHAND | MB_CANCELTRYCONTINUE | MB_DEFBUTTON2
    );

    switch (msgboxID)
    {
    case IDCANCEL:
        exit(EXIT_SUCCESS);
        break;
    case IDTRYAGAIN:
        goto tetyt;
        break;
    case IDCONTINUE:
       std::this_thread::sleep_for(std::chrono::seconds(12));
       std::shared_ptr<ImageVerarbeitung::Image> i(new ImageVerarbeitung::Image());
       i->readImg();
       i->showWin();
        break;
    }

    return msgboxID;
}
//
//int main(int argc, char* argv[]) {
//    std::cout << functin("123456789");
//    //system("magick image.png image.xbm");
//
//    std::ifstream file1;
//    file1.open("imagee.xbm", std::ios::in);
//    std::string txt;
  
    //std::ostream ofile();
    //if (file.is_open()) {
    //    //std::cout << "geoffnet";
    //    for (size_t i = 0; i < 3; i++)
    //    {
    //        getline(file, txt);
    //        txt.replace(1, 4, "");
    //    } 
    //    
    //    while (getline(file, txt))
    //        std::cout << txt;

       //file1.close();
   /* }
    else { std::cout << "´konnte nicht geoffnet werden"; }*/
    
   




    // << std::get<1>(conn->Query()) << std::endl;
  /*while (true){

    std::shared_ptr <Database::Statement> s(new Database::Statement());

    const char* re= s->Query().second;
    if (re==NULL) {
        re= "Leer";
    }
 
    
    std::shared_ptr< ImageVerarbeitung::Image> i(new ImageVerarbeitung::Image(re));
    i->readImg();
    i->showWin();
    std::this_thread::sleep_for(std::chrono::seconds(12));
  }*/

