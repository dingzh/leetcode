class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, vector<int>> graph;
        
        int size = stones.size();
        for (int i = 0; i < size; ++i)
            for (int j = i + 1; j < size; ++j) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    // connected if same row or same col
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        
        int ret = 0;
        vector<bool> visited(size, false);
        for (int i = 0; i < size; ++i) if (!visited[i]) {
            visited[i] = true;
            stack<int> stk;
            stk.push(i);
            
            --ret; // each component has one
            while (!stk.empty()) {
                ++ret;
                int node = stk.top();
                stk.pop();
                for (int next : graph[node]) if (!visited[next]) {
                    visited[next] = true;
                    stk.push(next);
                }
            }
        }
        return ret;
    }
};
