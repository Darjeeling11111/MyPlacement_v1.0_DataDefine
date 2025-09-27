//#include "PlaceData/placedata.h"
//#include "MyPlace/myplace.h"
//#include "../PlaceData/plot.h"
#include <iostream>
//using namespace std;
//#include "Include/MyPlacement_DataDefine/BookShelfParser/BookshelfParserStarter.h"
#include "BookshelfParser.h"




int main(int argc, char *argv[]){   
std::cout << "Hello, MyPlacement!" << std::endl;
    // PlaceData *placedata = new PlaceData();
    // MyPlacer *myplacer = new MyPlacer(placedata);
    BookshelfParserStarter parserStarter("adaptec1","/opt/source/adaptec1");
    parserStarter.parseAux();
    std::cout << parserStarter.getBaseName()<< std::endl;
    std::cout << parserStarter.getDir()<< std::endl;
    for(const auto &file : parserStarter.getRequiredFiles()){
        std::cout << file.first << " : " << file.second << std::endl;
    }
    parserStarter.setSiteWidthAndHeight(1,12);
    BookshelfParser parser(parserStarter);
    parser.parse();
    parser.getPlaceData()->Print();       
       return 0;
}
