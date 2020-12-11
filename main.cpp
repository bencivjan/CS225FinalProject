#include "Astar/astar.h"
#include "BFS/BFS.h"
#include "Graph.h"
#include "Dijkstra/Dijkstra.h"
#include "time.h"
#include "stdlib.h"
using std::cout;
using std::endl;
using std::string;

int main(int argc, char* argv[]) {
    std::cout << "Program is running\n";

<<<<<<< HEAD
    // Graph FlightMap("Data/test_airport_data.csv",
    //                 "Data/test_cycle_route_data.csv");
    Graph FlightMap("Data/airport_data.csv", "Data/route_data.csv", "1");
    std::unordered_map<std::string, std::pair<Airport, std::vector<Route>>> airports = FlightMap.get_airports();
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

    //Dijkstra testing
    srand(time(NULL));
    std::unordered_map<std::string, std::pair<Airport, std::vector<Route>>>::iterator tester = airports.begin();
    int index = rand() % (int)airports.size();
    int i = 0;
    for(i = 0; i < index; i++){
        tester++;
    }
    std::string curr_id = (*tester).first;
    Airport test_port = FlightMap.get_airport_by_ID(curr_id);
    Dijkstra d(FlightMap, test_port);
    d.algorithm();
    std::cout << "SSSP Size = " << (int)d.SSSP.size() << "\n";
    std::unordered_map<std::string, double>::iterator SSSP_it = d.SSSP.begin();
    while(SSSP_it != d.SSSP.end()){
        std::cout << "ID = " << (*SSSP_it).first << " Cost = " << (*SSSP_it).second << "\n";
        SSSP_it++;
    }
    std::cout << "\n\n";
=======
    if (argc <= 1) {
        cout << "Please run map with one argument" << endl;
        cout << "Select from: bfs, dijkstra, or astar" << endl;
        return 1;
    }
    if (argc >= 3) {
        cout << "Please only input one argument" << endl;
        cout << "Select from: bfs, dijkstra, or astar" << endl;
        return 1;
    }

    string input = string(argv[1]);

    if (input == "bfs") {
        BFS bfs;
        Graph g("Data/airport_data.csv", "Data/route_data.csv", "3731");
        vector<Airport> output = bfs.traversal(g, g.start_airport);

        cout << "BFS traversal started" << endl;

        for (size_t i = 0; i < output.size(); i++) {
            cout << "Step: " << i << ", visited: " << output[i].get_name()
                 << endl;
        }
    } else if (input == "astar") {
        Astar astar;
        Graph g("Data/airport_data.csv", "Data/route_data.csv", "3731");

        Airport end = g.get_airport_by_ID("3135");

        cout << "Astar search started" << endl;
        cout << "Start airport: " << g.start_airport.get_name() << endl;
        cout << "End airport: " << end.get_name() << endl;

        vector<Airport> output = astar.astarPath(g, g.start_airport, end);

        for (size_t i = 0; i < output.size(); i++) {
            cout << "Step: " << i << ", visited: " << output[i].get_name()
                 << endl;
        }
        cout << "Reached destination" << endl;
    } else {
        cout << "Select from: bfs, dijkstra, or astar" << endl;
    }

>>>>>>> 04aaae88209d269f073dedfc90ee6afec2623c8a
    return 0;
}