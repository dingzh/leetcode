class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        if (!row) return 0;
        int col = obstacleGrid[0].size();
        if (!col) return 0;
        
        if (obstacleGrid[row-1][col-1] == 1) return 0;
        obstacleGrid[row-1][col-1] = 1;
        
        for (int c = col - 1; c >=0; --c) {
            for (int r = row - 1; r >=0; --r) {
                int& val = obstacleGrid[r][c];
                if (val == 1) {
                    val = (c == col-1 && r == row-1) ? 1 : 0;
                } else {
                    int x = r + 1 < row ? obstacleGrid[r+1][c] : 0;
                    int y = c + 1 < col ? obstacleGrid[r][c+1] : 0;
                    val = x + y;
                }
                // cout << val << endl;
            }
        }
        
        return obstacleGrid[0][0];
    }
};
