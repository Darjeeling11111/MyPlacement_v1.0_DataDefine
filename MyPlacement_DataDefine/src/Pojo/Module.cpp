#include "Module.h"
#include "Net.h"
#include "Pin.h"
#include "PlDO.h"


void Module::Print()const {
    PrintIndex();
    PrintName();
    std::cout << "Module width:"<< this->getWidth()<< std::endl;
    std::cout << "Module height:"<< this->getHeight()<< std::endl;
    std::cout << "Module area:"<< this->getArea()<< std::endl;
    std::cout << "Module orientation:"<< static_cast<int>(this->getOrientation())<< std::endl; 
    PrintNets();
   // PrintPins();
}


bool Module::updateFromPlDO(std::unique_ptr<PlDO> pldo){
    std::string orient = pldo->getOrient();
    if(orient == "N"){
        this->setOrientation(ModuleOrient::N);
    }else if(orient == "S"){
        this->setOrientation(ModuleOrient::S);
    }else if(orient == "FS"){
        this->setOrientation(ModuleOrient::FS);
    }else{
        this->setOrientation(ModuleOrient::N);
    }
    float x = pldo->getX();
    float y = pldo->getY();
    POS_2D pos(x,y);
    this->setCenter(pos);
    std::string isFixed = pldo->getIsFixed();
    if(isFixed == "/FIXED"){
        this->setIsFixed(true);
    }
    return true;
}