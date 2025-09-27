//#include "../Include/MyPlacement_DataDefine/BookShelfParser/BookshelfParserStarter.h"
#include "BookshelfParserStarter.h"



int main(int argc, char *argv[]){
    BookshelfParserStarter parser("adaptec1","/opt/MyPlacement_v1.0_DataDefine/MyPlacement_DataDefine/bookshelf/adaptec1");
    parser.parseAux();
    std::cout << parser.getBaseName();
    return 0;
}