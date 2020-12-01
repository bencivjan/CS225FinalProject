#include "Graph.h"

int main(){
    std::cout << "Program is running\n";

    Graph FlightMap;
    std::unordered_map<std::string, std::pair<Airport, std::vector<Route>>> airports = FlightMap.data();
    std::vector<Route> routes = FlightMap.edge_data();
    //std::cout << "Left constructor\n";
    std::unordered_map<std::string, std::pair<Airport, std::vector<Route>>>::iterator it;
    std::cout << "Pointer: " << &it;
    /*for(it = airports.begin(); it != airports.end(); it++){
        std::cout << "Name: " << it->second.first.get_name() << " Abbreviation: " << it->second.first.get_abbreviation() << " Coords: " << it->second.first.get_coords().first << ", " << it->second.first.get_coords().second
                    << " ID = " << it->second.first.get_OpenFlightID() << "\n";
    }*/
    int length = routes.size();
    int i = 0;
    for(i = 0; i < length; i++){
        std::cout << "Source name = " << routes[i].get_source().get_name() << " Destination = " << routes[i].get_destination().get_name() << " Code = " << routes[i].get_code() << "\n";
    }
    return 0;
}