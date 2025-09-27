#pragma once
#include "IPojo/INet.h"
#include "IPojo/IPin.h"

class Net : public INet{
    public:
        Net(): INet() {}
        Net(int idx): INet(idx) {}
        void Print()const override;
        void PrintDetails()const override;
};