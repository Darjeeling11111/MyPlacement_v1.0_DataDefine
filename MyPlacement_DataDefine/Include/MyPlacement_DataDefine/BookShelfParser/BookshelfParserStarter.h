#pragma once
#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include "../Pojo/IPojo/IModule.h"


class BookshelfParserStarter{
    private:
        std::string baseName;
        std::string dir;
        std::map<std::string,std::string> requiredFiles;
    public:
        BookshelfParserStarter(const std::string& baseName,const std::string &dir): baseName(baseName), dir(dir) {
            requiredFiles.clear();
        }
        std::string getBaseName() const{
            return baseName;
        }
        std::string getDir() const{
            return dir;
        }
        const std::map<std::string,std::string> & getRequiredFiles() const{
            return requiredFiles;
        }
        bool parseAux();

        bool hasRequiredFile(const std::string &suffix) const{
            return requiredFiles.find(suffix) != requiredFiles.end();
        }

        bool hasAllRequiredFiles();
        void setSiteWidthAndHeight(int width,int height);
        
};


