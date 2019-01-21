class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            int x, y;
            tie(x, y) = edge;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        int start = longestPathStartFrom(0, graph);
        vector<int> path = findLongestPath(start, graph);

        int len = path.size();
        vector<int> ret;
        int idx = len >> 1;
        ret.push_back(path[idx]);
        if ((len & 1) == 0) { // even nodes, should have two MHT root
            ret.push_back(path[idx-1]);
        }
        return ret;
    }
    
    vector<int> findLongestPath(int start, vector<vector<int>>& graph) {
        vector<int> ret = {start};
        vector<int> path = {start};
        
        vector<int> visited(graph.size(), 0);
        visited[start] = 1;
        aux(start, graph, path, ret, visited);
        return ret;
    }
    
    void aux(int start, vector<vector<int>>& graph, 
             vector<int>& path, vector<int>& ret, vector<int>& visited) {
        // copy(begin(path), end(path), ostream_iterator<int>(cout, " "));
        // cout << endl;
        auto & next_nodes = graph[start];
        
        bool end = true;
        for (int node : next_nodes) if (!visited[node]){
            end = false;
            visited[node] = 1;
            path.push_back(node);
            aux(node, graph, path, ret, visited);
            path.pop_back();
        }
        if (end && path.size() > ret.size()) ret = path;
    }
    
    int longestPathStartFrom(int start, vector<vector<int>>& graph) {
        // BFS to find depth
        int end = 0;
        int size = graph.size();
        
        queue<int> q;
        q.push(start);
        vector<int> visited(graph.size(), 0);
        visited[start] = 1;
        
        while (!q.empty()) {
            int size = q.size();
            end = q.front();
            while (size --) {
                int node = q.front();
                q.pop();
                
                for (int next_node : graph[node]) if (!visited[next_node]) {
                    visited[next_node] = 1;
                    q.push(next_node);
                }
            }
        }
        return end;
    }
};
