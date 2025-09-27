#include "SiteRow.h"
#include "SiteRowDO.h"



SiteRow::SiteRow(const std::unique_ptr<SiteRowDO> &siteRowDO){
    if(siteRowDO->getCoreRow() == "Horizontal"){
        setCoreRowOrient(CoreRowOrient::HORIZONTAL);
    }else{
        setCoreRowOrient(CoreRowOrient::VERTICAL);
    }
    if(siteRowDO->getSiteorient() == 1){
        setSiteOrientation(SiteOrient::N);
    }else if(siteRowDO->getSiteorient() == 0){
        setSiteOrientation(SiteOrient::S);
    }
    int numSites = siteRowDO->getNumSites();
    double coordinate = siteRowDO->getCoordinate();
    double siteSpacing = siteRowDO->getSitesSpacing();
    setBottom(coordinate);
    setNumSites(numSites);
    setHeight(siteRowDO->getHeight());
    setStep(siteSpacing);
    setSiteWidth(siteRowDO->getSiteWidth());
    double subrowOrigin = siteRowDO->getSubrowOrigin();
    POS_2D start(subrowOrigin, coordinate);
    setStart(start);
    POS_2D end(subrowOrigin + numSites * siteSpacing , coordinate);
    setEnd(end);
}