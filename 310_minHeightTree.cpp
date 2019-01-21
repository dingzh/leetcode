class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> ret;
        
        vector<int> degree(n, 0);
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            int x, y;
            tie(x, y) = edge;
            graph[x].push_back(y);
            graph[y].push_back(x);
            ++degree[x];
            ++degree[y];
        }
        
        queue<int> q;
        for (int i = 0; i < n; ++i) if (degree[i] <= 1) { // < 1 only happen when 1 node
            q.push(i);
        }

        int nodes_count = n;
        while (nodes_count > 2) {
            int size = q.size();
            nodes_count -= size;
            while (size--) {
                int node = q.front(); q.pop();
                
                for (int next_node : graph[node]) if (--degree[next_node] == 1) {
                    q.push(next_node);
                }
            }
        };
        
        while (!q.empty()) {
            ret.push_back(q.front());
            q.pop();
        }

        return ret;
    }
};
