//#include "../../Include/MyPlacement_DataDefine/BookShelfParser/BookshelfParser.h"
#include "BookshelfParser.h"
#include "SiteRowDO.h"

bool BookshelfParser::parse(){
    if(!starter->hasAllRequiredFiles()){
        return false;
    }
    if(!parseNodes()){
        return false;
    }
    if(!parseNets()){
        return false;
    }
    // if(!parsePl()){
    //     return false;
    // }
    if(!parseScl()){
        return false;
    }
    return true;
}

bool BookshelfParser::parseNodes(){
    std::string path = starter->getRequiredFiles().at(".nodes");
    std::ifstream nodesFile(path);
    if(!nodesFile.is_open()){
        nodesFile.close();
        return false;
    }
    std::string line;
    std::string word;
    int s = 0;
    while(s<1 && std::getline(nodesFile, line)){
        if(line.empty() || line[0] == '#'){
            continue;
        }
        if(line.back() == '\r'){
            line.pop_back();
        }
        std::istringstream iss(line);
        while(iss >> word){
            if(word == "UCLA"){
                break;
            }else if(word == "NumNodes"){
                iss >> word;
                iss >> word;
                placeData->setModuleCount(std::stoi(word));
            }else if(word == "NumTerminals"){
                iss >> word;
                iss >> word;
                placeData->setTerminalCount(std::stoi(word));
                s=2;
            }
        }
      
    }
    int macroCount = 0;
    int terminalCount = 0;
    int siteWidth = IModule::getSiteWidth();
    int siteHeight = IModule::getSiteHeight();
    int ptr=0;
    int index=0;
    while(std::getline(nodesFile,line)){
        if(line.empty() || line[0] == '#'){
            continue;
        }
        ptr=0;
        auto module = std::make_shared<Module>();
        module->setIdx(index);
        index++;
        std::istringstream iss(line);
        while( iss >> word){
            if(word == "terminal"){
                module->setModuleType(ModuleType::TERMINAL);
                placeData->addTerminal(module);
                break;
            }else if(ptr == 0){
                module->setName(word);
            }else if(ptr == 1){
                module->setWidth(std::stoi(word));
            }else if(ptr == 2){
                module->setHeight(std::stoi(word));
            }
            ptr++;
        }
        module->initIsMacro();
        module->initArea();        
        //placeData->addModuleMap(module->getName(),std::move(module));
        placeData->addNode(module);
        placeData->addModuleMap(module->getName(), module);
    }
    nodesFile.close();
    return true;
}

bool BookshelfParser::parseNets(){
    std::string path = starter->getRequiredFiles().at(".nets");
    std::ifstream netsFile(path);
    if(!netsFile.is_open()){
        netsFile.close();
        return false;
    }
    std::string line;
    std::string word;
    int s = 0;
    while(s<2 && std::getline(netsFile, line)){
        if(line.empty() || line[0] == '#'){
            continue;
        }
        if(line.back() == '\r'){
            line.pop_back();
        }
        std::istringstream iss(line);
        while(iss >> word){
            if(word == "UCLA"){
                break;
            }else if(word == "NumNets"){
                iss >> word;
                iss >> word;
                this->placeData->setNetCount(std::stoi(word));
                s++;
            }else if(word == "NumPins"){
                iss >> word;
                iss >> word;
                this->placeData->setPinCount(std::stoi(word));
                s++;
            }  
        }
    }
    int netIndex = 0;
    int pinIndex = 0;
    while(std::getline(netsFile,line)){
        if(line.empty() || line[0] == '#'){
            continue;
        }
        if(line.back() == '\r'){
            line.pop_back();
        }
        auto net = std::make_shared<Net>(netIndex++);
        std::istringstream iss(line);
        while(iss >> word){
            if(word == "NetDegree"){
                iss >> word;
                iss >> word;
                net->setPinCount(std::stoi(word));
                iss >> word;
                net->setName(word);
            }
        }
        int pinCount = net->getPinCount();
        int i=0;
        while(i < pinCount && std::getline(netsFile,line)){
            if(line.empty() || line[0] == '#'){
                continue;
            }
            std::istringstream iss(line);
            auto pinDO = std::make_unique<PinDO>(pinIndex++,iss);
            auto pin = std::make_shared<Pin>(pinDO,net);
            net->addNetPin(pin);
            placeData->addPin(pin);
            auto module = placeData->getModuleMap().at(pin->getModuleName());
            if(module == nullptr){
                std::cout << "error: module not found" << std::endl;
            }
            module->addModulePin(pin);
            module->addNet(net);
            pin->setModule(module);
            i++;
        }
        placeData->addNet(net);
    }
    netsFile.close();
    return true;
}


bool BookshelfParser::parsePl(){


    return true;
}

bool BookshelfParser::parseScl(){
    std::string path = starter->getRequiredFiles().at(".scl");
    std::ifstream sclFile(path);
    if(!sclFile.is_open()){
        return false;
    }
    std::string line;
    std::string word;
    int s =0;
    while(s<1 && std::getline(sclFile,line)){
        if(line.empty() || line[0] == '#'){
            continue;
        }
        if(line.back() == '\r'){
            line.pop_back();
        }
        std::istringstream iss(line);
        while(iss >> word){
            if(word == "UCLA"){
                break;
            }else if(word == "NumRows"){
                iss >> word;
                iss >> word;
                placeData->setSiteRowCount(std::stoi(word));
                s=2;
            } 
        }
    }
    while(std::getline(sclFile,line)){
        if(line.empty() || line[0] == '#'){
            continue;
        }
        if(line.back() == '\r'){
            line.pop_back();
        }
        std::streampos pos = sclFile.tellg();
        std::istringstream iss(line);
        iss >> word;
        if(word == "CoreRow"){
            sclFile.clear();
            sclFile.seekg(pos);
            auto siteRowDO = SiteRowDO::createSiteRowDOFomFile(sclFile);
            auto siteRow = std::make_shared<SiteRow>(siteRowDO);
            placeData->addSiteRow(siteRow);
        }
    }
    sclFile.close();
    return true;
}
