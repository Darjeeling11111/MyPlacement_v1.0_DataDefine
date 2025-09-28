#pragma once
#include "../../Common/common.h"
#include "../../Enum/ModuleOrient.h"
#include "../../Enum/ModuleType.h"
#include <vector>
#include <memory>

class IPin;
class INet;
class PlDO;
//向前声明



class IModule
{   public:
      virtual ~IModule() = default;
      IModule(const IModule &)=default;
      IModule& operator=(const IModule &)=default;
      IModule(IModule &&)=default;
      IModule& operator=(IModule &&)=default;
      static void setSiteDimensions(int width, int height) {
          siteWidth = width;
          siteHeight = height;
      }

    private:
      void setIdxNameWidthHeightAreaMacro(int idx,const string &name,int width,int height){
          this->idx = idx;
          this->name = name;
          this->width = width;
          this->height = height;
          this->area = width * height;
          initIsMacro();      
        }
        void setIsMacro(bool _isMacro) { isMacro = _isMacro; }
        void setIsFiller(bool _isFiller) { isFiller = _isFiller; }
    protected:

        int idx;
        string name;
        int width;
        int height;
        static int siteHeight ;
        static int siteWidth;
        ModuleType moduleType;
        long area;
        ModuleOrient orientation;
        bool isMacro;
        bool isFixed;
        bool isFiller;
        vector<std::shared_ptr<IPin>> modulePins;
        vector<std::shared_ptr<INet>> nets;
        POS_2D center; 
/**
* @brief 初始化函数
*
* 初始化对象的状态，包括索引、中心点、宽度、高度、面积、方向、宏定义标志、填充标志和固定标志。
*
* 初始化步骤如下：
* 1. 将索引设置为 -1。
* 2. 将中心点设置为零向量。
* 3. 将宽度设置为 0。
* 4. 将高度设置为 0。
* 5. 将面积设置为 0。
* 6. 将方向设置为 ModuleOrient::N（北方向）。
* 7. 将宏定义标志设置为 false。
* 8. 将填充标志设置为 false。
* 9. 将固定标志设置为 false。
*/
      virtual void Init()
      {   
          // 初始化索引为-1
          idx = -1;
          // 将中心点设置为零向量
          center.SetZero();
          // 初始化宽度为0
          width = 0;
          // 初始化高度为0
          height = 0;
          // 初始化面积为0
          area = 0;
          // 初始化模块类型为 STANDARD
          moduleType = ModuleType::STANDARD;
          // 初始化方向为N
          orientation = ModuleOrient::N;
          // 初始化宏定义标志为false
          isMacro = false;
          // 初始化填充标志为false
          isFiller = false;
          // 初始化固定标志为false
          isFixed = false;     

          modulePins.clear();
          nets.clear();
      }
      virtual void Init(int width,int height){
          setSiteDimensions(width,height);
          Init();
      }
      virtual void Init(int idx,const std::string &name,int width,int height){
          Init();
          setIdxNameWidthHeightAreaMacro(idx,name,width,height);
      }

      IModule()
      {
          Init();
      }
      IModule(int width,int height){
          Init(width,height);
      }
      IModule(int idx,const std::string &name,int width,int height,int siteWidth,int siteHeight)
      {
          Init(siteWidth,siteHeight);
          setIdxNameWidthHeightAreaMacro(idx,name,width,height);  
      }
      IModule(int idx,const std::string &name,int width,int height)
      {
          Init(idx,name,width,height);
      }
      
    public:
      // getter and setter functions
      int getIdx() const { return idx; }
      const std::string& getName() const { return name; }
      float getWidth() const { return width; }
      float getHeight() const { return height; }
      float getArea() const { return area; }
      static float getSiteHeight()  { return siteHeight; }
      static float getSiteWidth()  { return siteWidth; }
      static bool ifIsMacro(const int width,const int height){
        return (height != siteHeight || width%siteWidth != 0);
      }
      ModuleOrient getOrientation() const { return orientation; }
      bool getIsMacro() const { return isMacro; }
      bool getIsFixed() const { return isFixed; }
      bool getIsFiller() const { return isFiller; }
      ModuleType getModuleType() const { return moduleType; }


      const vector<std::shared_ptr<IPin>>& getModulePins() const { return modulePins; }
      const vector<std::shared_ptr<INet>>& getNets() const { return nets; }
      POS_2D getCenter() const { return center; }

      void setIdx(int _idx) { idx = _idx; }
      void setName(const string &_name) { name = _name; }
      void setWidth(float _width) { width = _width; }
      void setHeight(float _height) { height = _height; }
      void setArea(float _area) { area = _area; }
      void setOrientation(ModuleOrient _orientation) { orientation = _orientation; }
     
      void setModuleType(ModuleType _moduleType) { 
        moduleType = _moduleType;
        if(_moduleType == ModuleType::MACRO){
            setIsMacro(true);
            setIsFiller(false);
        }else if(_moduleType == ModuleType::FILLER){
            setIsFiller(true);
            setIsMacro(false);
        }else if(this->isMacro == true || this->isFiller == true){
            setIsMacro(false);
            setIsFiller(false);
        }
     }
      void setIsFixed(bool _isFixed) { isFixed = _isFixed; }
      
      void addModulePin(const std::shared_ptr<IPin> &pin) { modulePins.push_back(pin); }
      void addModulePin(std::shared_ptr<IPin> && pin){
        modulePins.push_back(std::move(pin));
      }
      void addNet(const std::shared_ptr<INet> &net) { nets.push_back(net); }
      void addNet(std::shared_ptr<INet> && net){
        nets.push_back(std::move(net));
      }

      void initIsMacro(){
          if(ifIsMacro(this->width,this->height)){
              this->moduleType = ModuleType::MACRO;
              this->isMacro = true;
          }else{
              this->moduleType = ModuleType::STANDARD;
              this->isMacro = false;
          }
      }
      void initArea(){
          this->area = this->width * this->height;
      }
      void setCenter(const POS_2D &_center) { center = _center; }
      virtual void Print()const = 0;
      virtual void PrintName()const;
      virtual void PrintIndex()const;
      virtual void PrintPins()const;
      virtual void PrintNets()const;
      virtual bool updateFromPlDO(std::unique_ptr<PlDO> pldo)=0;
};



