class Solution {
    int ret = 0;
    int row = 0;
    int col = 0;
    vector<array<int,2>> dir = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        row = grid.size();
        col = row ? grid[0].size() : 0;
        if (!col) return 0;

        int sq_cnt = 0;
        pair<int,int> start;
        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < col; ++c) {
                if (grid[r][c] == 1) start = make_pair(r, c);
                else if (grid[r][c] == 0) ++sq_cnt;
            }
        }

        aux(start.first, start.second, sq_cnt, grid);
        return ret;
    }

    void aux(int r, int c, int cnt, vector<vector<int>>& grid) {
        for (const auto pdir : dir) {
            int nr = r + pdir[0];
            int nc = c + pdir[1];
            
            int val = -1;
            if (nr >= 0 && nr < row && nc >= 0 && nc < col) val = grid[nr][nc];
            
            if (val == 0) {
                grid[r][c] = -1;
                aux(nr, nc, cnt - 1, grid);
                grid[r][c] = 0;
            } else if (val == 2 && cnt == 0) {
                ++ret;
            }
        }
    }
};
