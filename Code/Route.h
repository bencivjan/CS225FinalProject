#pragma once
#include <string>
#include "Airport.h"
class Route{
    // Need to figure out weight
    private:
    const Airport& source_;
    const Airport& destination_;
    std::string airline_ICAO;
    int stops_;

    public:
    Route(const Airport& source, const Airport& destination, std::string airline_code, int stops);
};