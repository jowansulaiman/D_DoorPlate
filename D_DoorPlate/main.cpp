
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Image.h"
#include "Database.h"
#include <map>



int main(int argc, char *argv[]) {
    

    
    std::map<std::string, std::string> capital
    {
      { "Syrien", "Dmaskus" },
      { "Polen", "Warschau" },
      { "Schweden", "Stockholm" },
      { "Italien", "Rom" }
    };
    //std::cout << capital["Syrien"] << std::endl;
    std::cout << capital["Warschau"] << std::endl;



        // << std::get<1>(conn->Query()) << std::endl;

    //std::shared_ptr< ImageVerarbeitung::Image> i(new ImageVerarbeitung::Image);
    //i->readImg();
    //i->showWin();

}