class Solution {
    vector<array<int,2>> dlt { {0,-1}, {1,0}, {0,1}, {-1,0}, };
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        int row = grid.size();
        if (!row) return 0;
        int col = grid[0].size();
        if (!col) return 0;
        
        unordered_set<string> path_set;
        for (int r = 0; r < row; ++r)
            for (int c = 0; c < col; ++c) if (grid[r][c] != 0) {
                string path;
                dfs(r, c, grid, path);
                path_set.insert(move(path));
            }
        
        return path_set.size();
    }
    
    void dfs(int r, int c, vector<vector<int>>& grid, string& path) {
        int row = grid.size();
        int col = grid[0].size();
        grid[r][c] = 0;
        
        for (int i = 0; i < 4; ++i) {
            int nr = r + dlt[i][0];
            int nc = c + dlt[i][1];
            
            if (nr >= 0 && nr < row && nc >= 0 && nc < col && grid[nr][nc]) {
                path.push_back(i);
                dfs(nr, nc, grid, path);
            }
        }
        path.push_back('<');
    }
};
