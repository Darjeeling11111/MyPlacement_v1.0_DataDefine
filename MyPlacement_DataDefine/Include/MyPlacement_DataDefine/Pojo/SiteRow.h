#pragma once
#include "IPojo/ISiteRow.h"
class SiteRowDO;


class SiteRow : public ISiteRow
{
    public: 
        SiteRow(): ISiteRow() {};
        SiteRow(const std::unique_ptr<SiteRowDO> &siteRowDO);
    private:
    
};