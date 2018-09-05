class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (!m) return 0;
        int n = grid[0].size();
        if (!n) return 0;
        
        int** res = new int*[m];
        for (int i = 0; i < m; ++i) res[i] = new int[n];
        res[0][0] = grid[0][0];
        for (int i = 1; i < m; ++i) res[i][0] = grid[i][0] + res[i-1][0];
        for (int i = 0; i < n; ++i) res[0][i] = grid[0][i] + res[0][i-1];
        
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j) {
                int tmp = min(res[i][j-1], res[i-1][j]);
                res[i][j] = grid[i][j] + tmp;
            }
        
        return res[m-1][n-1];
    }
};
