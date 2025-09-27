#pragma once
#include "IPojo/IPin.h"
#include "IPojo/INet.h"
#include "IPojo/IModule.h"
#include "PinDO.h"

class Pin : public IPin
{
    public: 
       Pin(): IPin() {} 
       Pin(int idx): IPin(idx) {}
       Pin(int idx,const shared_ptr<INet> &net): IPin(idx,net) {}
       Pin(std::unique_ptr<PinDO> &pinDO,const shared_ptr<INet> &net);
       void Print()const override;
};

