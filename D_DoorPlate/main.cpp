
#include <stdio.h>
#include <iostream>
#include <ostream>
#include <string>
#include <iterator>
#include <iostream>
#include "Image.h"
#include "Query.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <array>
#include "reservation.h"
#include "room.h"
#include <cassert>
#include <boost/date_time.hpp>
#include <boost/format.hpp>
void print(std::list<std::string>  list)
{
    for (auto const& i : list) {
        std::cout  << i << "\n";
    }
}  
int main() {
    //std::shared_ptr<DateTime::_DateTime> t(new DateTime::_DateTime(12,11,2020,21,23,14));
    //if (t->check_local_Time(t)==false)
    //    std::cout << "kleiner ";
    Database::_Statement s("select start from reservation, meetingroom where reservation.room_id = meetingroom.room_id and reservation.room_id = 4");
    Database::_Statement y();

    for (auto i : s.Query())
    {
        std::cout << i << std::endl;
    }
   



//_Reservation r(27, 04, 2020, 23, 59, 17, 27, 04, 2020, 23, 59, 18);
//  //print(r.get_Next_StartDateTime_Reservations().first);_
//_Room re(1, "kulle", 3);
//if (re.is_Reserved() == false) {
//    std::cout << "false";
//}
        //print(r.get_Next_StartDateTime_Reservations().second);
        //print(r.get_Next_Time_Reservations().first);





   
   //std::ifstream file1;
    //file1.open("image.xbm", std::ios::in);

    //std::string txt;
    //std::stringstream ss;
    //if (file1.is_open()) {

    //    while (getline(file1, txt))
    //        ss << txt;
    //    std::string txt1 = ss.str();
    //    boost::replace_all_copy(txt1, "#define image_width 640#define image_height 384static char image_bits[] =", " ");
    //    //boost::replace_all(txt1, ",", " ");
    //        std::cout << txt1;


    //   file1.close();
    //}


    //std::string tyt = "jowans, is sd f g g}";
    //boost::replace_all(tyt, "}", " ");

    //std::cout << tyt; 
    //DateTime::_Date t(20, 11, 2021);
    //DateTime::_Date t1(20, 12, 2022);
    ////_DateTime new_DateTime(add_Year, add_Month, add_Day, add_Hour, add_Minute, add_Second);
    //DateTime::_Date t2 = t1 + t;
    ////if(t == t1)
    //    std::cout << t2.get_Date() << " " <<"";
    //using namespace boost::posix_time;
    //using namespace boost::gregorian;

    //DateTime::_Time t(21, 25, 13);
    //DateTime::_Time t1( 21, 25, 14);
    //std::cout << t.get_LocalDate().get_Year();
    //DateTime::_DateTime t2 = t1 + t;

    //std::cout << t2.get_Date() << " " <<  t2.get_Time();
    //DateTime::_Date t1(20, 12, 2022);
   /*
    if(t!=t1)
        std::cout << t.get_Time();*/
    //if (t > t1)
    //    std::cout << "True";//DateTime::_Time t2= t - t1;

  //std::cout << format("(t2)=(%Y,%M,%D)");

  //  
  //  std::cout /*<< to_simple_string(t2) << " - "
  //      << to_simple_string(t1) << " = "*/
  //      << ss.str() << std::endl;


   /* dt dat;
    dt dat1;
    dat.set(0, 0, 0, 17, 35, 25, 15);
    dat1.set(0, 0, 0, 18, 35, 25, 15);


    dt dt3 = dat + dat1;
    dt3.print();*/

    
    /*
    std::shared_ptr<Database::_Statement>s(new Database::_Statement("select  * from reservation limit 3")) ;

    for (auto& n : s->Query()) {
        std::cout << n << std::endl;
    }*/
    return 0;

}

   

   /* _Reservation r(20, 04, 2020, 25, 20, 17); 
    std::cout << r.get_StartDateTime().first << " " << r.get_StartDateTime().second;*/
   

    //DateTime::_DateTime t(20, 04, 2021, 12, 27, 9 /*end*/, 20, 05, 2021, 20, 28, 17);
    //if (t.check_DateTime() == false) {

    //    std::cerr << "feler datum" << std::endl;
    //}


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


