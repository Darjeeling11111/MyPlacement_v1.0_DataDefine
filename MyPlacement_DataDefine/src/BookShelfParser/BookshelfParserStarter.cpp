//#include "../../Include/MyPlacement_DataDefine/BookShelfParser/BookshelfParserStarter.h"
#include "BookshelfParserStarter.h"




bool BookshelfParserStarter::parseAux() {
    if(dir.substr(dir.length()-1) != "/"){
        dir += "/";
    }
    std::string auxFilePath = dir + baseName + ".aux";
    std::ifstream auxFile(auxFilePath);
    if(!auxFile.is_open()){
        return false;
    }
    std::string word;
    int length = 0;
    while(auxFile >> word){
        if(word == "RowBasedPlacement" || word == ":"){
            continue;
        }
        length = word.length();
        std::string temp = word.substr(length-2);
        std::string temp2 = word.substr(length-3);
        if(temp == "pl"){
            requiredFiles.try_emplace(".pl",dir + word);
        }else if(temp == "cl"){
            requiredFiles.try_emplace(".scl",dir + word);
        }else if(temp == "es"){
            requiredFiles.try_emplace(".nodes",dir + word);
        }else if(temp2 == "wts"){
            requiredFiles.try_emplace(".wts",dir + word);
        }else if(temp2 == "ets"){
            requiredFiles.try_emplace(".nets",dir + word);
        }
        continue;
    }
    auxFile.close();
    return true;
}


bool BookshelfParserStarter::hasAllRequiredFiles(){
    if(!hasRequiredFile(".nodes")){
        std::cout << "Error: .nodes file is required!" << std::endl;
        return false;
    }else if(!hasRequiredFile(".nets")){
        std::cout << "Error: .nets file is required!" << std::endl;
        return false;
    }else if(!hasRequiredFile(".pl")){
        std::cout << "Error: .pl file is required!" << std::endl;
        return false;
    }else if(!hasRequiredFile(".scl")){
        std::cout << "Error: .scl file is required!" << std::endl;
        return false;
    }else if(!hasRequiredFile(".wts")){
        std::cout << "Warning: .wts file is missing, all modules will have the same weight!" << std::endl;
    }
    return true;
}


void BookshelfParserStarter::setSiteWidthAndHeight(int width,int height){
    IModule::setSiteDimensions(width,height);
}