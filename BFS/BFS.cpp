#include "BFS.h"

std::vector<Airport> BFS::traversal(Graph g, Airport start) {
    count = 0;
    start_airport = g.start_airport;
    queue<Airport> q;
    std::unordered_map<string, bool> visited;
    std::vector<Airport> path;

    visited[start.get_OpenFlightID()] = true;
    q.push(start);

    while (!q.empty()) {
        count++;
        Airport& curr = q.front();
        visited_airport_ids.push_back(q.front().get_OpenFlightID());
        path.push_back(q.front());
        q.pop();
        vector<Route> routes =
            g.get_adjacent_routes_by_ID(curr.get_OpenFlightID());
        for (auto& route : routes) {
            Airport adjacent = route.get_destination();
            if (visited.find(adjacent.get_OpenFlightID()) == visited.end()) {
                q.push(adjacent);
                visited[adjacent.get_OpenFlightID()] = true;
            }
        }
        if (q.empty()) {
            end_airport = curr;
        }
    }

    return path;
}