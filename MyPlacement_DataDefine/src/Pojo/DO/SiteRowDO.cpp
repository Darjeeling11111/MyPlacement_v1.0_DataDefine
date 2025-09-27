#include "SiteRowDO.h"
#include <iostream>
#include <fstream>


std::unique_ptr<SiteRowDO> SiteRowDO::createSiteRowDOFomFile(std::ifstream &sclFile){
    std::string line;
    std::string word;
    int s = 0;
    std::string CoreRow;
    double Coordinate;
    double Height;
    double SiteWidth;
    double SitesSpacing;
    double SubrowOrigin;
    int NumSites;
    int Siteorient;
    while(s<1 && std::getline(sclFile, line)){
        if(line.empty() || line[0] == '#'){
            continue;
        }
        if(line.back() == '\r'){
            line.pop_back();
        }
        std::istringstream iss(line);
        iss >> word;
        if(word == "CoreRow"){
            iss>> CoreRow;
        }else if(word == "Coordinate"){
            iss >> word;
            iss >> Coordinate;
        }else if(word == "Height"){
            iss >> word;
            iss >> Height;
        }else if(word =="Sitewidth"){
            iss >> word;
            iss >> SiteWidth;
        }else if(word == "Sitespacing"){
            iss >> word;
            iss >> SitesSpacing;
        }else if(word == "Siteorient"){
            iss >> word;
            iss >> Siteorient;
        }else if(word == "Sitesymmetry"){
            continue;
        }else if(word == "SubrowOrigin"){
            iss >> word;
            iss >> SubrowOrigin;
            iss >> word;
            if(word == "NumSites"){
                iss >> word;
                iss >> NumSites;
            }
        }else if(word == "End"){
            s = 2;
        }
    }
    return std::make_unique<SiteRowDO>(SiteRowDO(CoreRow, Coordinate, Height, SiteWidth,
         SitesSpacing, SubrowOrigin, NumSites, Siteorient));
}