#include "Astar/astar.h"
#include "BFS/BFS.h"
#include "Graph.h"

using std::cout;
using std::endl;
using std::string;

int main(int argc, char* argv[]) {
    std::cout << "Program is running\n";

    if (argc <= 1) {
        cout << "Please run map with one argument" << endl;
        cout << "Select from: bfs, dijkstra, astar, or all" << endl;
        return 1;
    }
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
        cout << "Select from: bfs, dijkstra, astar, or all" << endl;
    }

    return 0;
}