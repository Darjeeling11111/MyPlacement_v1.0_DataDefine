#include "Module.h"
#include "Net.h"
#include "Pin.h"


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