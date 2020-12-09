#include "../Graph.h"
#include "../BFS/BFS.h"

class Heap{
    private:
    std::map<int, std::string> data;
    // Maps a node to its predecessor
    std::unordered_map<std::string, std::string> predecessor;
    // Graph with all nodes
    Graph& connected_component;
    public:
    Heap();
    Heap(Graph& component);
    void updateNode(std::string airport_ID);
    const Airport& pop();
    const Airport& peek();
    void push(const Airport& element);
};