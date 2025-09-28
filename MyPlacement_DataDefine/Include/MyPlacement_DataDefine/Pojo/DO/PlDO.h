#pragma once
#include <string>
#include <memory>



class PlDO{
    private:
        std::string name;
        float x;
        float y;
        std::string orient;
        std::string isFixed;
        PlDO(const std::string &name, float x, float y, const std::string &orient, const std::string &isFixed):
            name(name), x(x), y(y), orient(orient), isFixed(isFixed){}
    public:
        static std::unique_ptr<PlDO> createPlDOFormString(std::string &line,bool &isFixed);
        std::string getName() const{ return name;}
        float getX()const{return x;}
        float getY()const{return y;}
        std::string getOrient()const{return orient;}
        std::string getIsFixed()const{ return isFixed;}
};
