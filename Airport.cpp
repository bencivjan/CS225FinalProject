#include "Airport.h"

Airport::Airport() {
    OpenFlightID = "";
    name_ = "";
    location = std::pair<std::string, std::string>();
    coordinates = std::pair<double, double>();
    abbreviation = "";
}

Airport::Airport(std::string name) {
    OpenFlightID = name;
    name_ = "";
    location = std::pair<std::string, std::string>();
    coordinates = std::pair<double, double>();
    abbreviation = "";
}

Airport::Airport(std::string ID, std::string name, std::string city,
                 std::string country, double latitude, double longitude,
                 std::string code) {
    OpenFlightID = ID;
    name_ = name;
    location.first = city;
    location.second = country;
    coordinates.first = latitude;
    coordinates.second = longitude;
    abbreviation = code;
}

Airport::Airport(const Airport& other) {
    OpenFlightID = other.OpenFlightID;
    name_ = other.name_;
    location.first = other.location.first;
    location.second = other.location.second;
    coordinates.first = other.coordinates.first;
    coordinates.second = other.coordinates.second;
    abbreviation = other.abbreviation;
}

std::pair<double, double> Airport::get_coords() const { return coordinates; }

std::pair<std::string, std::string> Airport::get_location() const {
    return location;
}

std::string Airport::get_name() const { return name_; }

std::string Airport::get_abbreviation() const { return abbreviation; }

std::string Airport::get_OpenFlightID() const { return OpenFlightID; }
bool Airport::operator==(const Airport& other) const {
    if (OpenFlightID == other.OpenFlightID) {
        return true;
    }
    return false;
}
