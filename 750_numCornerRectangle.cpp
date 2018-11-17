class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int row = grid.size();
        if (row < 2) return 0;
        int col = grid[0].size();
        if (col < 2) return 0;

        int ret = 0;
        vector<bitset<200>> ones(row, bitset<200>());
        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < col; ++c) {
                if (grid[r][c]) ones[r].set(c);
            }
        }

        for (int i = 0; i < row; ++i) {
            for (int j = i + 1; j < row; ++j) {
                int cnt = (ones[i] & ones[j]).count();
                ret += (cnt * (cnt - 1)) / 2;
            }
        }

        return ret;
    }

};
