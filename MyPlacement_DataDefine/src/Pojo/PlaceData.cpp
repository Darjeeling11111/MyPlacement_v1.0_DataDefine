#include "PlaceData.h"
#include "PlDO.h"
#include "Module.h"


void PlaceData::Print()const{
    std::cout << "Module count: " << this->getModuleCount() << std::endl;
    std::cout << "Macro count: " << this->getMacroCount() << std::endl;
    std::cout << "Terminal count: " << this->getTerminalCount() << std::endl;
    std::cout << "Net count: " << this->getNetCount() << std::endl;
    std::cout << "Pin count: " << this->getPinCount() << std::endl;
    for(const auto &module : this->getNodes()){
        module->Print();
    }
    // for(const auto &terminal : this->getTerminals()){
    //     terminal->Print();
    // }
    // for(const auto &net : this->getNets()){
    //     net->Print();
    // }
}   


bool PlaceData::updateFromPLDO(std::unique_ptr<PlDO> pldo){
    std::string pldoName = pldo->getName();
    if(moduleMap.find(pldoName) == moduleMap.end()){
        std::cout<<"Module not found"<<std::endl;
        return false;//没找到
    }
    moduleMap[pldoName]->updateFromPlDO(std::move(pldo));
    return true;
}