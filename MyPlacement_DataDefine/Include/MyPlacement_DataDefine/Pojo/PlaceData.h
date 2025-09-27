#pragma once
#include "IPojo/IPlaceData.h"
#include "IPojo/IModule.h"
#include "IPojo/INet.h"
#include "IPojo/IPin.h"
#include "IPojo/ISiteRow.h"


class PlaceData : public IPlaceData{
    public:
        PlaceData(): IPlaceData() {};
        void Print()const override;         
};