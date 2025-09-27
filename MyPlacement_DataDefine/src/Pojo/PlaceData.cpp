#include "PlaceData.h"


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