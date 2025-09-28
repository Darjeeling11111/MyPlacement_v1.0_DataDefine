#pragma once
#include "IPojo/IModule.h"
#include "IPojo/IPin.h"


class PlDO;


class Module : public IModule{
    public:
        Module(): IModule() {}
        Module(int width,int height): IModule(width,height) {}
        Module(int idx,const std::string &name,int width,int height,int siteWidth,int siteHeight): IModule(idx,name,width,height,siteWidth,siteHeight) {}
        Module(int idx,const std::string &name,int width,int height): IModule(idx,name,width,height) {}
        void Print()const override;
        bool updateFromPlDO(std::unique_ptr<PlDO> pldo)override;
};

