#include "Net.h"


void Net::Print()const{
    std::cout << "Net ID: " << idx << std::endl;
    std::cout << "Net Name: " << name << std::endl; 
    std::cout << "pinCount:"<< getPinCount() << std::endl;
}

void Net::PrintDetails()const{
    std::cout << "Net ID: " << idx << std::endl;
    std::cout << "Net Name: " << name << std::endl; 
    std::cout << "pinCount:"<< getPinCount() << std::endl;
    std::cout << "Net Pins:"<< std::endl;
    for(auto pin : netPins){
        pin->Print();
    }

}