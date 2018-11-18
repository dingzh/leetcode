class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int size = M.size();
        int ret = 0;
        vector<int> visited(size, 0);
        
        for (int i = 0; i < size; ++i) {
            if (!visited[i]) {
                ++ret;
                dfs(i, visited, M);
            }
        }
        return ret;
    }
    
    void dfs(int idx, vector<int>& visited, vector<vector<int>>& M) {
        int size = M[0].size();
        
        stack<int> stk;
        stk.push(idx);
        visited[idx] = 1;
        while (!stk.empty()) {
            int idx = stk.top();
            stk.pop();
            for (int i = 0; i < size; ++i) {
                if (M[idx][i] && !visited[i]) {
                    stk.push(i);
                    visited[i] = 1;
                }
            } 
        }
    }
};
