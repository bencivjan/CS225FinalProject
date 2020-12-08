#include "Graph.h"

using std::cout;
using std::endl;

int main() {
    std::cout << "Program is running\n";

    // Graph FlightMap("Data/test_airport_data.csv",
    //                 "Data/test_cycle_route_data.csv");
    Graph FlightMap("Data/airport_data.csv", "Data/route_data.csv");
    std::unordered_map<std::string, std::pair<Airport, std::vector<Route>>>
        airports = FlightMap.get_airports();
    std::vector<Route> routes = FlightMap.get_routes();

    // std::cout << FlightMap.get_adjacent_routes_by_ID("2990").size()
    //           << std::endl;
    // std::cout << "Left constructor\n";
    // std::unordered_map<std::string,
    //                    std::pair<Airport, std::vector<Route>>>::iterator it;
    // std::cout << "Pointer: " << &it;

    // std::cout << FlightMap.get_adjacent_routes_by_ID("20").size() <<
    // std::endl;

    // Routes
    int length = routes.size();
    // int i = 0;
    cout << length << endl;
    // for (i = 0; i < length; i++) {
    //     std::cout << "Source name = " << routes[i].get_source().get_name()
    //               << " Destination = " <<
    //               routes[i].get_destination().get_name()
    //               << " Code = " << routes[i].get_code()
    //               << " Stops = " << routes[i].get_stops() << "\n";
    // }
    return 0;
}