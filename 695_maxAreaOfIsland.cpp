class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ret = 0;
        int row = grid.size();
        if (!row) return 0;
        int col = grid[0].size();
        if (!col) return 0;
        
        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < col; ++c) {
                if (grid[r][c]) 
                    ret = max(ret, dfs(r, c, grid, row, col));
            }
        }
        return ret;
    }
    
    int dfs(int r, int c, vector<vector<int>>& grid, const int row, const int col) {   
        int ret = 0;
        stack<pair<int, int>> stk;
        stk.emplace(r, c);
        
        while (!stk.empty()) {
            tie(r, c) = stk.top();
            stk.pop();
            
            if (r < 0 || c < 0 || r >= row || c >= col || !grid[r][c]) continue;
            ++ret;
            grid[r][c] = 0;

            stk.emplace(r-1, c);
            stk.emplace(r, c-1);
            stk.emplace(r+1, c);
            stk.emplace(r, c+1);
        }
        
        return ret;
    }
};
