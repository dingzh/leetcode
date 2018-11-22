class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size();
        if (!row) return 0;
        int col = grid[0].size();
        if (!col) return 0;
        
        int ret = 0;
        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < col; ++c) {
                if (grid[r][c]) {
                    ret += 4;
                    if (r > 0 && grid[r-1][c]) ret -= 2;
                    if (c > 0 && grid[r][c-1]) ret -= 2;
                }
            }
        }
        return ret;
    }
};
