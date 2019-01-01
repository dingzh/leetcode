class Solution {
    vector<int> ret;
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        
        vector<vector<int>> graph(10, vector<int>());
        for (int i = 0; i < 10; ++i) {
            auto& vec = graph[i];
            if (i + K < 10) vec.push_back(i + K);
            if (i - K >= 0 && K) vec.push_back(i - K);
        }

        for (int i = 1; i < 10; ++i) 
            dfs(0, i, graph, N);
        
        if (N == 1) dfs(0, 0, graph, 1);
        
        return ret;
    }
    
    void dfs(int val, int start, vector<vector<int>>& graph, int len) {
        val = val * 10 + start;
        
        if (len == 1) {
            ret.push_back(val);
            return ;
        }
        
        for (auto num : graph[start]) 
            dfs(val, num, graph, len-1);
    }
};
