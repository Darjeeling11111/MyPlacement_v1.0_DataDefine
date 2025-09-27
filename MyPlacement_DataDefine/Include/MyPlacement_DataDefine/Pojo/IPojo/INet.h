#pragma once
#include "../../Common/common.h"
#include <memory>

class IPin;


class INet{
    public:
        virtual ~INet()=default;
        INet(const INet &)=default;
        INet& operator=(const INet &)=default;
        INet(INet &&)=default;
        INet& operator=(INet &&)=default;
    protected:
        int idx;
        string name;
        vector<std::shared_ptr<IPin>> netPins;
        int pinCount;
        virtual void Init(){
            name="";
            idx = 0;
            netPins.clear();
        }
        INet()
        {
            Init();
        }
        INet(int idx) : idx(idx){
            name="";
            netPins.clear();
        }
    public:
        int getIdx() const { return idx; }  
        const string &getName() const { return name; }
        void setName(const string &value) { name = value; }
        const vector<std::shared_ptr<IPin>> &getNetPins() const { return netPins; }
        void addNetPin(const std::shared_ptr<IPin> &pin) { netPins.push_back(pin); }
        void addNetPin(std::shared_ptr<IPin> && pin){
            netPins.push_back(std::move(pin));
        }
        void setNetPins(const vector<std::shared_ptr<IPin>> &value) { netPins = value; }
        void setPinCount(int pinCount){this->pinCount = pinCount;}
        int getPinCount() const { return pinCount; }
        virtual void Print()const=0;
        virtual void PrintDetails()const=0;
    private:
        void setIdx(int value) { idx = value; }
};
