#pragma once
#include <string>
#include "Airport.h"
class Route{
    // Need to figure out weight
    private:
    Airport source_;
    Airport destination_;
    std::string airline_ICAO;
    int stops_;

    public:
    Route();
    Route(Airport source, Airport destination, std::string airline_code, int stops);
};