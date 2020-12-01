#include "Graph.h"

int main(){
    std::cout << "Program is running\n";

    Graph FlightMap;
    int i = 0;
    std::unordered_map<Airport, std::vector<Route>> airports = FlightMap.data();
    std::unordered_map<Airport, std::vector<Route>>::iterator it;
    std::cout << "Pointer: " << &it;
    for(it = airports.begin(); it != airports.end(); it++){
        std::cout << "Name: " << it->first.get_name() << " Abbreviation: " << it->first.get_abbreviation() << "Coords: " << it->first.get_location().first << ", " << it->first.get_location().second << "\n";
    }
    return 0;
}