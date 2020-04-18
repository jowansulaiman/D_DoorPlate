
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


std::tuple<int, int, int> test(int a, int b, int c) {

    return std::make_tuple(a, b, c);
}

int main()
{
    std::string x = "23.23.43.5";

    int y = std::stoi(x);

    std::cout << y << std::endl;


     //std::shared_ptr<Database::Statement>s(new Database::Statement("select room_id, designation from MeetingRoom where room_id >2"));
     //std::cout << s->Query().first << " "; std::cout << s->Query().second;

    //std::pair<std::pair<int,int>, std::pair<int, int>>as=std::make_pair(std::make_pair(12,12), std::make_pair(12,23));
    //std::cout << as.first.first << as.first.second;
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
