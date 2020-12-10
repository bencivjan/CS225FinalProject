#include "astar.h"

vector<Airport> Astar::astarPath(Graph graph, const Airport start,
                                 const Airport end) {
    open.clear();
    closed.clear();
    h.clear();
    g.clear();
    f.clear();
    parent.clear();
    vector<Airport> path;
    Airport final = runAstar(graph, start, end);
    Airport current = final;
    string current_ID = current.get_OpenFlightID();

    while (parent.find(current_ID) != parent.end()) {
        path.insert(path.begin(), current);
        current = parent[current_ID];
        current_ID = current.get_OpenFlightID();
    }
    path.insert(path.begin(), current);

    return path;
}

Airport Astar::runAstar(Graph graph, const Airport start, const Airport end) {
    Airport current;

    h[start.get_OpenFlightID()] = graph.get_dist(start, start);
    g[start.get_OpenFlightID()] = graph.get_dist(start, end);

    open.push_back(start);
    count_open = 1;
    count_closed = 0;

    while (open.size() > 0) {
        // current is node with smallest f cost in open list
        int index = min_fcost(open);
        current = open[index];
        string current_ID = current.get_OpenFlightID();
        // Remove current from the open list
        open.erase(open.begin() + index);
        // Push current onto the closed list
        closed.push_back(current);
        count_closed++;

        // If the current node is the end node, we are done
        if (current_ID == end.get_OpenFlightID()) {
            return current;
        }

        // Iterate through neighbors
        vector<Route> neighbors = graph.get_adjacent_routes_by_ID(current_ID);

        for (auto& route : neighbors) {
            Airport neighbor = route.get_destination();
            string neighbor_ID = neighbor.get_OpenFlightID();
            // If neighbor is not walkable or in the closed list, skip to
            // next neighbor
            if (exists(closed, neighbor)) continue;

            // If path to neighbor (g cost) is shorter than current
            if (g.find(neighbor_ID) == g.end()) g[neighbor_ID] = INT_MAX;
            if (g[current_ID] + graph.get_dist(current, neighbor) <
                g[neighbor_ID]) {
                // Set f cost (through g and h)
                g[neighbor_ID] =
                    g[current_ID] + graph.get_dist(current, neighbor);
                h[neighbor_ID] = graph.get_dist(neighbor, end);
                // Set parent of neighbor to current
                parent[neighbor_ID] = current;
            }
            // If neighbor is not in open list, add it to open list
            if (!exists(open, neighbor)) {
                open.push_back(neighbor);
                count_open++;
            }
        }
    }
    return Airport();
}

int Astar::fcost(const Airport a) {
    string name = a.get_OpenFlightID();

    if (f.find(name) != f.end()) {
        return f[name];
    } else if (h.find(name) == h.end()) {
        f[name] = INT_MAX;
        return INT_MAX;
    } else if (g.find(name) == g.end()) {
        g[name] = INT_MAX;
        return INT_MAX;
    } else {
        f[name] = g[name] + h[name];
        return f[name];
    }
}

int Astar::min_fcost(const vector<Airport> v) {
    if (v.size() == 0) return 0;
    int min = 0;
    int index = 0;
    for (auto& a : v) {
        if (fcost(a) < min) {
            min = index;
        }
        index++;
    }
    return min;
}

bool Astar::exists(const vector<Airport> v, const Airport check) {
    for (auto& airport : v) {
        if (airport == check) {
            return true;
        }
    }
    return false;
}
