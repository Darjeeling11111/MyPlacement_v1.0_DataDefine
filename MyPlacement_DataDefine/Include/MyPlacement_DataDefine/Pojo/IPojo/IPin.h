#pragma once
#include "../../Common/common.h"
#include "PinDirection.h"
#include <memory>

class IModule;
class INet;

class IPin
{
    public:
      virtual ~IPin() = default;
      IPin(const IPin &)=default;
      IPin& operator=(const IPin &)=default;
      IPin(IPin &&)=default;  
      IPin& operator=(IPin &&)=default;
    protected:
      int idx;
      //string name;
      PinDirection direction;
      std::string moduleName;
      std::weak_ptr<IModule> module;
      std::weak_ptr<INet> net;
      POS_2D offset;
      virtual void init()
      {
          idx = -1;
          moduleName="";
          module.reset();
          net.reset();
          offset.SetZero();
          direction = PinDirection::INPUT;
          //direction = -1;
      }
      IPin()
      {
            init();
      }
      IPin(int idx) : idx(idx){
          moduleName="";
          module.reset();
          net.reset();
          offset.SetZero();
          direction = PinDirection::INPUT;
      }
      IPin(int idx,const shared_ptr<INet> &net) : idx(idx), net(net){
          moduleName="";
          module.reset();
          offset.SetZero();
          direction = PinDirection::INPUT;
      }

    public:
        std::string getModuleName()const{return moduleName; }
        void setModuleName(const std::string &value) { moduleName = value; }
        int getIdx() const { return idx; }
        void setIdx(int value) { idx = value; }
        PinDirection getDirection() const { return direction; }
        void setDirection(PinDirection value) { direction = value; }
        std::shared_ptr<IModule> getModule() const { return module.lock(); }
        bool hasModule() const {return !module.expired();}
        IModule* getModuleShared() const {
            if(hasModule()){
            return module.lock().get();
            }else{
                return nullptr;
            }
        }
        void setModule(const std::shared_ptr<IModule> &mod) { module = mod; }

        std::shared_ptr<INet> getNet() const { return net.lock(); }
        void setNet(const std::shared_ptr<INet> &n) { net = n; }
        bool hasNet() const { return !net.expired(); }
        INet* getNetShared() const {
            if(hasNet()){
                return net.lock().get();
            }else{
                return nullptr;
            }
        }
  
        POS_2D getOffset() const { return offset; }
        void setOffset(const POS_2D &value) { offset = value; }
        virtual void Print()const=0;
};
