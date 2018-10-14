/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return nullptr;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> nodes_map;
        return DFS(node, nodes_map);
    }

    UndirectedGraphNode *
    DFS(UndirectedGraphNode* node,
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>& nodes_map) {

        UndirectedGraphNode* new_node = nodes_map[node];
        if (!new_node) {
            new_node = new UndirectedGraphNode(node->label);
            nodes_map[node] = new_node;
            for (auto next_node : node->neighbors) {
                new_node->neighbors.push_back( DFS(next_node, nodes_map) );
            }
        }

        return new_node;
    }
};
