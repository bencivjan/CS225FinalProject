#include "Astar/astar.h"
#include "BFS/BFS.h"
#include "Graph.h"

using std::cout;
using std::endl;
using std::string;

int main(int argc, char* argv[]) {
    std::cout << "Program is running\n";

    if (argc >= 3) {
        cout << "Please only input one argument" << endl;
        cout << "Select from: bfs, dijkstra, astar, or all" << endl;
        return 1;
    }

    string input = string(argv[1]);

    if (input == "bfs") {
        BFS bfs;
        Graph g("Data/airport_data.csv", "Data/route_data.csv", "1");
        vector<Airport> output = bfs.traversal(g, g.start_airport);

        cout << "BFS traversal started" << endl;

        for (size_t i = 0; i < output.size(); i++) {
            cout << "Step: " << i << ", visited: " << output[i].get_name()
                 << endl;
        }
    }

    // Graph FlightMap("Data/test_airport_data.csv",
    //                 "Data/test_cycle_route_data.csv");
    // Graph FlightMap("Data/airport_data.csv", "Data/route_data.csv", "1");
    // std::unordered_map<std::string, std::pair<Airport, std::vector<Route>>>
    //     airports = FlightMap.get_airports();
    // std::vector<Route> routes = FlightMap.get_routes();

    // std::cout << FlightMap.get_adjacent_routes_by_ID("2990").size()
    //           << std::endl;
    // std::cout << "Left constructor\n";
    // std::unordered_map<std::string,
    //                    std::pair<Airport, std::vector<Route>>>::iterator it;
    // std::cout << "Pointer: " << &it;

    // std::cout << FlightMap.get_adjacent_routes_by_ID("20").size() <<
    // std::endl;

    // Routes
    // int length = routes.size();
    // int i = 0;
    // cout << length << endl;
    // for (i = 0; i < length; i++) {
    //     std::cout << "Source name = " << routes[i].get_source().get_name()
    //               << " Destination = " <<
    //               routes[i].get_destination().get_name()
    //               << " Code = " << routes[i].get_code()
    //               << " Stops = " << routes[i].get_stops() << "\n";
    // }
    return 0;
}