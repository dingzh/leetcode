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
        stack<UndirectedGraphNode*> stk;
        stk.push(node);
        
        while (!stk.empty()) {
            auto curr = stk.top();
            stk.pop();
            auto copy = nodes_map[curr];
            if (!copy) {
                copy = new UndirectedGraphNode(curr->label);
                nodes_map[curr] = copy;
            }

            for (auto next_node : curr->neighbors) {
                UndirectedGraphNode* next_node_copy = nodes_map[next_node];
                if (!next_node_copy) {
                    next_node_copy = new UndirectedGraphNode(next_node->label);
                    nodes_map[next_node] = next_node_copy;
                    stk.push(next_node);
                }
                copy->neighbors.push_back(next_node_copy);
            }
        }

        return nodes_map[node];
    }
};
