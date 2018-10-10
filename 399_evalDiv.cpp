class Solution {
    unordered_map<string, vector<pair<string, double>>> graph;
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, 
            vector<double>& values, vector<pair<string, string>> queries) {

       buildGraph( equations, values );

       vector<double> ret;
       for (auto& q : queries) {
           double result = query( q );
           ret.push_back( result );
       }

       return ret;
    }

    void 
    buildGraph(vector<pair<string, string>> equations, vector<double> values){
        for (int i = 0; i < equations.size(); ++i) {
            auto& eq = equations[i];
            graph[eq.first].push_back(  make_pair( eq.second, values[i] ) );
            graph[eq.second].push_back( make_pair( eq.first, 1/values[i] ) );
        }
    }

    double query(pair<string, string>& q) {
        if (graph.find( q.first ) == graph.end() ||
            graph.find( q.second ) == graph.end()) return -1.0;

        unordered_set<string> visited;
        bool found = false;
        double ret = queryHelper( q.first, q.second, visited, found );
        return found ? ret : -1.0; 
    }

    double queryHelper(string& curr, string& target,
            unordered_set<string> visited, bool& found) {
        if (curr == target ) {
            found = true;
            return 1.0;
        }

        for (auto& node : graph[curr]) {
            string& next = node.first;
            if (visited.count( next )) continue;
            else visited.insert( next );

            double ret = queryHelper( next, target, visited, found );

            if (found) { return node.second * ret; }
        }

        return -1.0;
    }
};
