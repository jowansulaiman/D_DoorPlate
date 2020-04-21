
#include <stdio.h>
#include <map>
#include <iostream>
#include "Image.h"
#include "Query.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <vector>
#include <array>
#include "DateTime.h"
#include "reservation.h"

int main() {

    std::shared_ptr<Database::_Statement>s(new Database::_Statement("select * from Meetingroom"));
    for (size_t i = 0; i < 3; i++)
    {
        std::cout << s->Query();
    }

   /* _Reservation r(20, 04, 2020, 25, 20, 17); 
    std::cout << r.get_StartDateTime().first << " " << r.get_StartDateTime().second;*/
   

    //DateTime::_DateTime t(20, 04, 2021, 12, 27, 9 /*end*/, 20, 05, 2021, 20, 28, 17);
    //if (t.check_DateTime() == false) {

    //    std::cerr << "feler datum" << std::endl;
    //}
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
