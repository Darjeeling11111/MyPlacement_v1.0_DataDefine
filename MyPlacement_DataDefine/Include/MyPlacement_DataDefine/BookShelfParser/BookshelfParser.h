#pragma once
#include <string>
#include <memory>
#include "BookshelfParserStarter.h"
#include "../Pojo/PlaceData.h"
#include "../Pojo/Module.h"
#include "../Pojo/Net.h"
#include "../Pojo/Pin.h"
#include "../Pojo/SiteRow.h"
#include <sstream>


class BookshelfParser{
    private:
        std::unique_ptr<BookshelfParserStarter> starter;
        std::shared_ptr<PlaceData> placeData;

    public:
        BookshelfParser(const BookshelfParserStarter &starter)
        :starter(std::make_unique<BookshelfParserStarter>(starter)) {
            placeData = std::make_shared<PlaceData>();
        }    
        const std::shared_ptr<PlaceData>& getPlaceData() const{
            return placeData;
        }
        bool parse();
    private:
        bool parseNodes();
        bool parseNets();
        bool parsePl();
        bool parseScl();
        
};