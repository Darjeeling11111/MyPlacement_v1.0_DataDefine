#include "Pin.h"



Pin::Pin(std::unique_ptr<PinDO> &pinDO,const std::shared_ptr<INet> &net){
    setIdx(pinDO->getPinIndex());
    setModuleName(pinDO->getName());
    setNet(net);
    module.reset();
    string direction = pinDO->getDirection();
    if(direction == "I"){
        setDirection(PinDirection::INPUT);
    }else if(direction == "O"){
        setDirection(PinDirection::OUTPUT);
    }else {
        setDirection(PinDirection::UNDEFINED);
    }
    setOffset(POS_2D(pinDO->getX(), pinDO->getY()));
}

void Pin::Print()const {
    std::cout << "Pin:  idx: " << getIdx() << std::endl;
    //std::cout << "Pin:  direction: " << getDirection() << std::endl;
    std::cout << "Pin:  net: " << getNet()->getName() << std::endl;
    std::cout << "pin:  offset: " << getOffset() << std::endl;
} 

