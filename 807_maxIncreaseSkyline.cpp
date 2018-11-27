class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int row = grid.size();
        if (!row) return 0;
        int col = grid[0].size();
        if (!col) return 0;
        
        vector<int> left;
        for (auto& r : grid) {
            left.push_back(*max_element(r.begin(), r.end()));
        }
        
        vector<int> top(col, 0);
        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < col; ++c) {
                top[c] = max(top[c], grid[r][c]);
            }
        }
        
        int ret = 0;
        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < col; ++c) {
                int h = min(left[r], top[c]);
                ret += h - grid[r][c];
            }
        }
        return ret;
    }
};
