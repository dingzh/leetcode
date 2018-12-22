class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, vector<string>> graph;
        for (auto& p : tickets) {
            graph[p.first].emplace_back(p.second);
        }
        
        for (pair<const string, vector<string>>&p : graph) {
            sort(begin(p.begin()), end(p.end()));
        }
        
        vector<string> ret;
        string begin = "JFK";
        dfs(begin, tickets.size();)
    }
};


// how to find a hamliton loop
