class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if (S == T) return 0;
        int size = routes.size();
        for(auto& route : routes) sort(begin(route), end(route));

        vector<vector<int>> graph(size, vector<int>());
        for (int i = 0; i < size; ++i)
            for (int j = i+1; j < size; ++j) {
                if (intersect(i, j, routes)) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }

        unordered_set<int> dest;
        unordered_set<int> visited;
        queue<int> q;
        for (int i = 0; i < size; ++i) {
            if (binary_search(begin(routes[i]), end(routes[i]), S)) {
                q.push(i);
                visited.insert(i);
            }
            if (binary_search(begin(routes[i]), end(routes[i]), T)) dest.insert(i);
        }

        int ret = 0;
        while (!q.empty()) {
            int size = q.size();
            ++ret;
            while (size--) {
                int route = q.front(); q.pop();
                if (dest.count(route)) return ret;
                for (int next_route : graph[route]) if (!visited.count(next_route)) {
                    visited.insert(next_route);
                    q.push(next_route);
                }
            }
        }

        return -1;
    }

    bool intersect(int i, int j, vector<vector<int>>& routes) {
        const auto& route1 = routes[i];
        const auto& route2 = routes[j];

        int p1 = 0, p2 = 0, size1 = route1.size(), size2 = route2.size();
        while(p1 < size1 && p2 < size2) {
            if (route1[p1] < route2[p2]) ++p1;
            else if (route1[p1] > route2[p2]) ++p2;
            else return true;
        }
        return false;
    }
};
