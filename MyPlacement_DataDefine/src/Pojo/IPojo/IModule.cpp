#include "IModule.h"
#include "IPin.h"  
#include "INet.h" 


int IModule::siteWidth = 1;
int IModule::siteHeight = 1;

void IModule::PrintName()const{
    std::cout << "Module name:"<< this->getName()<< std::endl;
    // 输出模块名称
}
void IModule::PrintIndex()const{
    std::cout << "Module index:"<< this->getIdx()<< std::endl;
    // 输出模块索引
}


void IModule::PrintPins()const{
    std::cout << "Module pins:"<< std::endl;
    for(auto pin : this->getModulePins()){
        pin->Print();
    }
}


void IModule::PrintNets()const{
    std::cout << "Module nets:"<< std::endl;
    for(auto net : this->getNets()){
        net->PrintDetails();
    }
}