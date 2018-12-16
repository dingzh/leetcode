class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int lines = triangle.size();
        if (lines == 0) return 0;
        
        vector<int> dist = triangle[0];
        
        for (int line = 1; line < lines; ++line) {
            auto& vec = triangle[line];
            int size = vec.size();
            vector<int> next;
            next.push_back(dist[0] + vec[0]);
            for (int i = 1; i + 1 < size; ++i) {
                next.push_back(min(dist[i-1], dist[i]) + vec[i]);
            }
            next.push_back(dist.back() + vec[size-1]);
            dist = (move(next));
        }
        return *min_element(begin(dist), end(dist));
    }
};
