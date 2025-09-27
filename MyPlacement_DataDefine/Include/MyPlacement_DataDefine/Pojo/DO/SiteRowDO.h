#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <memory>


class SiteRowDO{
    private:
        std::string CoreRow;
        double Coordinate;
        double Height;
        double SiteWidth;
        double SitesSpacing;
        double SubrowOrigin;
        int NumSites;
        int Siteorient;
        SiteRowDO(const std::string &coreRow, double coordinate, double height,
        double siteWidth, double sitesSpacing, double subrowOrigin,int numSites, int siteorient):
        CoreRow(coreRow), Coordinate(coordinate), Height(height), SiteWidth(siteWidth),
        SitesSpacing(sitesSpacing), SubrowOrigin(subrowOrigin), NumSites(numSites), Siteorient(siteorient){}
    public:

        std::string getCoreRow(){
            return CoreRow;
        }
        double getCoordinate(){
            return Coordinate;
        }
        double getHeight(){
            return Height;
        }
        double getSiteWidth(){
            return SiteWidth;
        }
        double getSitesSpacing(){
            return SitesSpacing;
        }
        double getSubrowOrigin(){
            return SubrowOrigin;
        }
        int getNumSites(){
            return NumSites;
        }
        int getSiteorient(){
            return Siteorient;
        }
        static std::unique_ptr<SiteRowDO> createSiteRowDOFomFile(std::ifstream &sclFile);
};