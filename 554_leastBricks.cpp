class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int maxEdges = 0;
        
        unordered_map<int, int> edges;

        for (int i = 0; i < wall.size(); ++i) {
            int len = 0;
            for (int j = 0; j < wall[i].size()-1; ++j) {
                len += wall[i][j];
                edges[len] += 1;
                maxEdges = edges[len] > maxEdges ? edges[len] : maxEdges;
            }
        }

        return wall.size() - maxEdges;
    }
};
