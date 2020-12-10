
#include "../Graph.h"
#include "../BFS/BFS.h"
class Dijkstra{
    private:
    // Connected nodes
    std::vector<std::string> connected_nodes;

    //maps a airport to its predicessor
    std::unordered_map<std::string, std::string> predecessor;

    //maps a path weight to a certatin airport
    std::map<int, std::string> data;

    Graph& full_graph;

    public:
    std::unordered_map<std::string, int> SSSP;

    Dijkstra(Graph& original, const Airport& source);
    void algorithm();

    
};