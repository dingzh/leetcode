class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int size = row.size();
        int N = size / 2;
        
        vector<int> partner_pos(N, -1);
        vector<vector<int>> graph(N, vector<int>());
        
        for (int i = 0; i < size; ++i) {
            int num_couple = row[i] / 2;
            int my_pos = i / 2;
            int& pt_pos = partner_pos[num_couple];
            
            if (pt_pos != -1) {
                graph[my_pos].push_back(pt_pos);
                graph[pt_pos].push_back(my_pos);
            } else {
                pt_pos = my_pos;
            }
        }
        
        int component = 0;
        vector<int> visited(N, 0);
        for (int i = 0; i < N; ++i)if (!visited[i]) {
             ++component;
            dfs(i, graph, visited);
        }
        return N - component;
    }
    
    void dfs(int start, vector<vector<int>>& graph, vector<int>& visited) {
        if (visited[start]) return ;
        visited[start] = 1;
        for (int next : graph[start]) {
            dfs(next, graph, visited);
        }
    }
};
