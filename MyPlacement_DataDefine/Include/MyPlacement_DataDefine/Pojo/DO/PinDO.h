#pragma once
#include <string>
#include <iostream>
#include <sstream>


class PinDO{
    private:
        int pinIndex;
        std::string moduleName;
        std::string direction;
        float x;
        float y;
    public:
        PinDO(int index,std::istringstream& iss):pinIndex(index){
            iss >> moduleName >> direction; 
            // iss >> x;
            // iss >> y;
            std::string temp;
            iss >> temp;
            iss >> x;
            iss >> y;  
        }
        int getPinIndex() const{
            return pinIndex;
        }
        const std::string& getName() const{
            return moduleName;
        }
        const std::string& getDirection()const{
            return direction;
        }

        float getX() const{
            return x;
        }

        float getY() const{
            return y;
        }


};