class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, deque<string>> graph;
        
        for (const auto& p : tickets) 
            graph[p.first].push_back(p.second);
        
        for (auto& p : graph)  
            sort(begin(p.second), end(p.second));
        
        vector<string> ret;
        aux("JFK", graph, ret);
        
        ret.push_back("JFK");
        reverse(begin(ret), end(ret));
        return ret;
    }
    
    void aux(const string& start, unordered_map<string, deque<string>>& graph, 
                vector<string>& ret) {
        deque<string>& next_stops = graph[start];
        
        while (!next_stops.empty()) {
            string next = next_stops.front();
            next_stops.pop_front();
            aux(next, graph, ret);
            ret.push_back(next);
        }
    }
};
