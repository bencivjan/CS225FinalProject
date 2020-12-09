#include "astar.h"

void Astar::runAstar(Graph g, Airport start, Airport end) {
    vector<Airport> open;
    vector<Airport> closed;
    Airport current;
    // Map to store h heuristics
    std::unordered_map<std::string, int> h;
    // Map to store g heuristics
    std::unordered_map<std::string, int> g;

    h[start.get_OpenFlightID()] = 0;

    // start.g = distance(start, start);
    // start.h = distance(start, end);

    // open.push(start);

    // while (open.length > 0) {
    //     // current is node with smallest f cost in open list
    //     // eslint-disable-next-line no-undef
    //     current = _.min(open, node = > node.f);
    //     // Remove current from the open list
    //     open.splice(open.indexOf(current), 1);
    //     // Push current onto the closed list
    //     closed.push(current);

    //     // If the current node is the end node, we are done
    //     if (current.xCoord == = end.xCoord&& current.yCoord == = end.yCoord)
    //     {
    //         return current;
    //     }
    //     let neighbors = getNeighbors(current, grid);
    //     for (let neighbor of neighbors) {
    //         // If neighbor is not walkable or in the closed list, skip to
    //         // next neighbor
    //         if (neighbor.isWall || closed.indexOf(neighbor) >= 0) {
    //             continue;
    //         }
    //         // If path to neighbor (g cost) is shorter than current
    //         if (current.g + distance(current, neighbor) < neighbor.g) {
    //             // Set f cost (through g and h)
    //             neighbor.g = current.g + distance(current, neighbor);
    //             neighbor.h = distance(neighbor, end);
    //             // Set parent of neighbor to current
    //             neighbor.parent = current;
    //         }
    //         // If neighbor is not in open list, add it to open list
    //         if (open.indexOf(neighbor) < 0) {
    //             open.push(neighbor);
    //         }
    //     }
    //     // eslint-disable-next-line no-undef
    //     if (showAlg) {
    //         for (let node of open) {
    //             node.isOpen = true;
    //         }
    //         for (let node of closed) {
    //             node.isClosed = true;
    //         }
    //         await sleep(50);
    //     }
    // }
    // throw "PathNotFound";
}
