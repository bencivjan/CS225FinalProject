#include "Graph.h"

int main() {
    std::cout << "Program is running\n";

    Graph FlightMap;
    std::unordered_map<std::string, std::pair<Airport, std::vector<Route>>>
        airports = FlightMap.get_airports();
    std::vector<Route> routes = FlightMap.get_routes();

    std::cout << FlightMap.get_adjacent_routues_by_ID("2990").size()
              << std::endl;
    // std::cout << "Left constructor\n";
    // std::unordered_map<std::string,
    //                    std::pair<Airport, std::vector<Route>>>::iterator it;
    // std::cout << "Pointer: " << &it;

    // Nodes
    /*
    for (it = airports.begin(); it != airports.end(); it++) {
        std::cout << "Name: " << it->second.first.get_name()
                  << " Abbreviation: " << it->second.first.get_abbreviation()
                  << " Coords: " << it->second.first.get_coords().first << ", "
                  << it->second.first.get_coords().second
                  << " ID = " << it->second.first.get_OpenFlightID() << "\n";
    }
    */

    // Routes
    // int length = routes.size();
    // int i = 0;
    // for (i = 0; i < length; i++) {
    //     std::cout << "Source name = " << routes[i].get_source().get_name()
    //               << " Destination = " <<
    //               routes[i].get_destination().get_name()
    //               << " Code = " << routes[i].get_code()
    //               << " Stops = " << routes[i].get_stops() << "\n";
    // }
    return 0;
}