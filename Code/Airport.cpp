#include "Airport.h"

Airport::Airport(std::string ID, std::string name, std::string city, std::string country, double latitude, double longitude, std::string code){
    OpenFlightID = ID;
    name_ = name;
    location.first = city;
    location.second = country;
    coordinates.first = latitude;
    coordinates.second = longitude;
    abbreviation = code;
}

std::pair<double, double> Airport::get_coords(){
    return coordinates;
}

std::pair<std::string, std::string> Airport::get_location(){
    return location;
}

std::string Airport::get_name(){
    return name_;
}

std::string Airport::get_abbreviation(){
    return abbreviation;
}