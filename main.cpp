#include "Astar/astar.h"
#include "BFS/BFS.h"
#include "Dijkstra/Dijkstra.h"
#include "Graph.h"
#include "stdlib.h"
#include "time.h"
using std::cout;
using std::endl;
using std::string;

int main(int argc, char* argv[]) {
    std::cout << "Program is running\n";

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
    } else if (input == "dijkstra") {
        Graph g("Data/test_complex_airport_data.csv", "Data/test_complex_route_data.csv", "1");
        Dijkstra dijkstra = Dijkstra(g, g.start_airport);

        cout << "Dijkstras search started" << endl;
        cout << "Start airport: " << g.start_airport.get_name() << endl;

        std::unordered_map<std::string, double> output = dijkstra.algorithm();

        std::cout << output.size() << std::endl;

        for (auto const& key_val : output) {
            cout << "Airport name: "
                 << g.get_airport_by_ID(key_val.first).get_name()
                 << ", distance: " << key_val.second << endl;
        }

        cout << "Map is completely populated" << endl;
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

    return 0;
}