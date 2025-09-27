#pragma once
#include "../../Common/common.h"
#include "SiteOrient.h"
#include "CoreRowOrient.h"
#include <memory>


class ISiteRow{
    public:
        virtual ~ISiteRow() = default;
        ISiteRow(const ISiteRow &)=default;
        ISiteRow& operator=(const ISiteRow &)=default;
        ISiteRow(ISiteRow &&)=default;
        ISiteRow& operator=(ISiteRow &&)=default;
    protected:
        int numSites;
        double siteWidth;           
        double bottom;             
        double height;             
        double step;                
        POS_2D start;               
        POS_2D end;  
        SiteOrient siteOrientation;   
        CoreRowOrient coreRowOrient;
    /**
    * @brief 构造函数
    *
    * 初始化ISiteRow对象，设置其属性为默认值。
    *
    * @details 该构造函数将对象的底部(bottom)、高度(height)、步长(step)属性初始化为0，
    *          方向(orientation)初始化为水平方向(SiteRowOrient::H)，起始点(start)和结束点(end)
    *          的坐标初始化为零。
    */
        ISiteRow()
        {
            numSites = 0;
            bottom = 0;
            height = 0;
            step = 0;
            siteWidth = 0;
            siteOrientation = SiteOrient::N;
            coreRowOrient = CoreRowOrient::HORIZONTAL;
            start.SetZero();
            end.SetZero();
        }
    public:
        int getNumSites() const { return numSites; }
        void setNumSites(int value) { numSites = value; }
        double getSiteWidth() const { return siteWidth; }
        void setSiteWidth(double value) { siteWidth = value; }
        double getBottom() const { return bottom; }
        void setBottom(double value) { bottom = value; }
        double getHeight() const { return height; }
        void setHeight(double value) { height = value; }
        double getStep() const { return step; }
        void setStep(double value) { step = value; }
        const POS_2D &getStart() const { return start; }
        void setStart(const POS_2D &value) { start = value; }
        const POS_2D &getEnd() const { return end; }
        void setEnd(const POS_2D &value) { end = value; }
        SiteOrient getSiteOrientation() const { return siteOrientation; }
        void setSiteOrientation(const SiteOrient &value) { siteOrientation = value; }
        CoreRowOrient getCoreRowOrient() const { return coreRowOrient; }
        void setCoreRowOrient(const CoreRowOrient &value) { coreRowOrient = value; }
};