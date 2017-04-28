#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

struct UndirectedGraphNode {
    string label;
    vector<UndirectedGraphNode*> neighbors;
    UndirectedGraphNode(string s) : label(s) {};
};

UndirectedGraphNode* cloneGraph(UndirectedGraphNode* graph) {
    if (graph == NULL) return NULL;

    queue<UndirectedGraphNode*> border;
    border.push(graph);

    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> map;
    UndirectedGraphNode* clone = new UndirectedGraphNode(graph->label);
    map[graph] = clone;

    // for each node
    while (!border.empty()) {
        UndirectedGraphNode* currNode = border.front();
        border.pop();

        // for each neighbor
        for (UndirectedGraphNode* neighbor : currNode->neighbors) {
            // if no copie exists
            if (map.find(neighbor) == map.end()) {
                // create a new node in the cloned graph
                UndirectedGraphNode* neighborClone = new UndirectedGraphNode(neighbor->label);

                // set the created node as one of the neighbors of the current node in the cloned graph
                map[currNode]->neighbors.push_back(neighborClone);

                map[neighbor] = neighborClone; // add the neighbor to the map
                border.push(neighbor); // the neighbor should be cloned later
                // if a copy already exists
            } else {
                map[currNode]->neighbors.push_back(map[neighbor]);
            }
        }
    }

    return clone;
}
