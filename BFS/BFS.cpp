#include "BFS.h"

void BFS::traversal(Graph g, Airport start) {
    start_airport = g.start_airport;
    queue<Airport> q;
    std::unordered_map<string, bool> visited;

    visited[start.get_OpenFlightID()] = true;
    q.push(start);
    visited_airport_ids.push_back(q.front().get_OpenFlightID());

    while (!q.empty()) {
        count++;
        Airport& curr = q.front();
        q.pop();
        vector<Route> routes =
            g.get_adjacent_routes_by_ID(curr.get_OpenFlightID());
        for (auto& route : routes) {
            Airport adjacent = route.get_destination();
            if (visited.find(adjacent.get_OpenFlightID()) == visited.end()) {
                q.push(adjacent);
                visited_airport_ids.push_back(q.front().get_OpenFlightID());
                visited[adjacent.get_OpenFlightID()] = true;
            }
        }
        if (q.empty()) {
            end_airport = curr;
        }
    }
}
// procedure BFS(G, root) is
//        let Q be a queue
//        label root as discovered
//        Q.enqueue(root)
//        while Q is not empty do
//            v := Q.dequeue()
//            if v is the goal then
//                return v
//           for all edges from v to w in G.adjacentEdges(v) do
//               if w is not labeled as discovered then
//                   label w as discovered
//                   Q.enqueue(w)