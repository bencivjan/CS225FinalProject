#include <string>
class Airport{
    private:
    // Airport Dataset
    std::string name_;
    std::pair<std::string, std::string> location; // first = city, second = country
    std::pair<double, double> coordinates; // first = latitude, second = longitude

    std::string OpenFlightID; // might not need
    std::string abbreviation; // Decide which one (which code)

    public:
    // Constructor
    Airport(std::string ID, std::string name, std::string city, std::string country, double latitude, double longitude, std::string code);

    std::pair<double, double> get_coords();
    std::pair<std::string, std::string> get_location();
    std::string get_name();

    std::string get_OpenFlightID();
    std::string get_abbreviation();
};