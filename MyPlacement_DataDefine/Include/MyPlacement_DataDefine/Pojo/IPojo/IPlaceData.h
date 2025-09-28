#pragma once
#include <memory>
#include <vector>
#include <map>
#include <string>
#include  <iostream>




class IModule;
class INet;
class IPin;
class ISiteRow;
class PlDO;

class IPlaceData{
    public:
        virtual ~IPlaceData()=default;
        IPlaceData(const IPlaceData &)=default;
        IPlaceData& operator=(const IPlaceData &)=default;
        IPlaceData(IPlaceData &&)=default;
        IPlaceData& operator=(IPlaceData &&)=default;
    protected:
        int moduleCount; 
        int terminalCount; 
        int macroCount;
        int netCount;
        int pinCount;
        int SiteRowCount;
        std::vector<std::shared_ptr<IModule>> Nodes;
        std::vector<std::shared_ptr<IModule>> Terminals;
        std::vector<std::shared_ptr<IPin>> Pins;
        std::vector<std::shared_ptr<INet>> Nets;
        std::vector<std::shared_ptr<ISiteRow>> SiteRows;    
        std::map<std::string,std::shared_ptr<IModule>> moduleMap;

        IPlaceData(){Init();}

        virtual void Init(){
            moduleCount=0;
            macroCount=0;
            terminalCount=0;
            netCount=0;
            pinCount=0;
            Nodes.clear();
            Terminals.clear();
            Pins.clear();
            Nets.clear();
            SiteRows.clear();
            moduleMap.clear();
        }
        
    public:
        virtual void Print()const =0;
        void setSiteRowCount(int value) {SiteRowCount = value;}
        int getSiteRowCount() const {return SiteRowCount;}
        int getModuleCount() const {return moduleCount;}
        void setModuleCount(int value) {moduleCount = value;}
        int getMacroCount() const {return macroCount;}
        void setMacroCount(int value) {macroCount = value;}
        int getNetCount() const {return netCount;}
        void setNetCount(int value) {netCount = value;}
        void setTerminalCount(int value) {terminalCount = value;}
        int getTerminalCount() const {return terminalCount;}
        int getPinCount() const {return pinCount;}
        void setPinCount(int value) {pinCount = value;}
        const std::vector<std::shared_ptr<IModule>> &getNodes() const {return Nodes;}
        void addNode(const std::shared_ptr<IModule> &node) {Nodes.push_back(node);}
        void addNode(std::shared_ptr<IModule> && node){
            Nodes.push_back(std::move(node));
        }
        const std::vector<std::shared_ptr<IModule>> &getTerminals() const {return Terminals;}
        void addTerminal(const std::shared_ptr<IModule> &terminal) {Terminals.push_back(terminal);}
        void addTerminal(std::shared_ptr<IModule> && terminal){
            Terminals.push_back(std::move(terminal));
        }       
        const std::vector<std::shared_ptr<IPin>> &getPins() const {return Pins;}
        void addPin(const std::shared_ptr<IPin> &pin) {Pins.push_back(pin);}
        void addPin(std::shared_ptr<IPin> && pin){
            Pins.push_back(std::move(pin));
        }
        const std::vector<std::shared_ptr<INet>> &getNets() const {return Nets;}
        void addNet(const std::shared_ptr<INet> &net) {Nets.push_back(net);}
        void addNet(std::shared_ptr<INet> && net){
            Nets.push_back(std::move(net));
        }
        const std::vector<std::shared_ptr<ISiteRow>> &getSiteRows() const {return SiteRows;}
        void addSiteRow(const std::shared_ptr<ISiteRow> &siteRow) {SiteRows.push_back(siteRow);}
        void addSiteRow(std::shared_ptr<ISiteRow> && siteRow){
            SiteRows.push_back(std::move(siteRow));
        }   
        const std::map<std::string,std::shared_ptr<IModule>> &getModuleMap() const{
            return moduleMap;
        }
        bool addModuleMap(const std::string &name,const std::shared_ptr<IModule> &module){
            if(!module){
                return false;
            }
            auto it = moduleMap.find(name);
            if(it == moduleMap.end()){
                moduleMap.try_emplace(name,module);
                return true;
            }else {
                return false;
            }            
        }
        bool addModuleMap(const std::string &name,std::shared_ptr<IModule> && module){
            if(!module){
                return false;
            }
            auto it = moduleMap.find(name);
            if(it == moduleMap.end()){
                try{moduleMap.try_emplace(name,std::move(module));}
                catch(const std::exception &e){
                    std::cerr << "Error inserting module with name " << name << ": " << e.what() << std::endl;
                    return false;
                }
                return true;
            }else {
                return false;
            }
        }
        virtual bool updateFromPLDO(std::unique_ptr<PlDO> pldo) =0;
};