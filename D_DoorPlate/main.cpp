
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
#include "DateTime.h"
#include "C:\Users\jowan\OneDrive\Dokumente\Arduino\libraries"

// Driver code
//class date {
//    int m, j, t;
//public:
//    date(int m_m, int m_j, int m_t):m(m_m), j(m_j), t(m_t) {
//
//    }
//    friend ostream& operator << (ostream& os, const date& dt);
//};
//
//ostream& operator << (ostream& os, const date& dt) {
//  
//    os << dt.t << "/" << dt.m << "/" << dt.j;
//    return os;
//}



int main()
{

    std::shared_ptr< DateTime::ZeitStempel>s(new DateTime::ZeitStempel());
    std::cout << s->get_Start_End_DateTime().first << " " << s->get_Start_End_DateTime().second;
    
}


//int main(int argc, char* argv[]) {

//    //system("magick image.png image.xbm");
//
//    std::ifstream file1;
//    file1.open("imagee.xbm", std::ios::in)
//    std::string txt;
//  
//    std::ostream ofile();
//    if (file.is_open()) {
//        //std::cout << "geoffnet";
//        for (size_t i = 0; i < 3; i++)
//        {
//            getline(file, txt);
//            txt.replace(1, 4, "");
//        } 
//        
//        while (getline(file, txt))
//            std::cout << txt;
//
//       file1.close();
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
