
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

template <class T>
void print(std::list<T>  list)
{
    for (auto const& i : list) {
        std::cout  << i << "\n";
    }
}  

class a {
private:
    int x;
    int b;
public:
    a(int x, int y):x(x),b(y)  {
       
    }
    void print() {
#ifndef print_
#define print_
        std::cout << x << " " << b << std::endl;
#endif // !print_

    }

    void check() {
#ifdef print_
        std::cout << "erfolg";  
#endif // print_

    }

};

class b {
private:
    std::vector<a*>c;
    int b_id;
public:
    b(int aa) :b_id(aa) {

    }
    void add_a(a &s) {
     
            c.push_back(new a(2,3));
      
    }
    void print() {
        for (auto i:c)
        {
            i->print();
        }
    }
};
using namespace cv;
using namespace std;

int main() {

    Imagehandling::Image Img("DoorPlate.png", "C:/Users/jowan/OneDrive/Desktop/");
    Img.read_Img();
    Img.Convert_Img();
}
    


    //Img.save_Img();
   /* Database::_Statement s("");

    print(s.rooms().first);
    print(s.rooms().second);



    using namespace boost::gregorian;
    using namespace boost::posix_time;*/
   
    //for (auto i : s.StartDateTime())
    //{
    //    std::cout << i << std::endl;

    //    //ptime dt(time_from_string(i));
    //    //date d(from_simple_string(i));
    //    //time_duration t(hours(d));
    //    //std::cout << dt.date().year() << " " << (int)d.month() << " " << d.day() << std::endl;
    //    //std::cout << dt.time_of_day().hours() << std::endl;
    //}
 




