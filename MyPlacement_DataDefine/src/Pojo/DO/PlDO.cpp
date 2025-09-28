#include "PlDO.h"
#include "sstream"
#include <vector>



std::unique_ptr<PlDO> PlDO::createPlDOFormString(std::string &line,bool &isFixed){
    std::istringstream iss(line);
    std::vector<std::string> words;
    std::string word;
    while(iss >> word){
        words.push_back(word);
    }
    if(words.empty() || words.size() < 6 || words[5] != "/FIXED"){
        isFixed = false;
        return nullptr;
    }else{
        isFixed = true;
        return std::make_unique<PlDO>(PlDO(words[0], std::stof(words[1]),std::stof(words[2]), words[4], words[5]));
    }
}