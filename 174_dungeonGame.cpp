class Solution {
    int row, col;
    vector<vector<int>> dp;
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        row = dungeon.size();
        assert(row);
        col = dungeon[0].size();
        assert(col);
        dp = vector<vector<int>>(row, vector<int>(col, -1));
        
        dp[row-1][col-1] = 1 - min(dungeon[row-1][col-1], 0);
        
        int ret = aux(0, 0, dungeon);
        // for (int r = 0; r < row; ++r) {
        //     for (int c = 0; c < col; ++c) 
        //         cout << dp[r][c] << '\t';
        //     cout << endl;
        // }
        return ret;  
    }
    
    int aux(int r, int c, vector<vector<int>>& dungeon) {
        if (r >= row || c >= col) return numeric_limits<int>::max();
        if (dp[r][c] != -1) return dp[r][c];

        int down = aux(r+1, c, dungeon);
        int right = aux(r, c+1, dungeon);
        int mini = min(down, right);
        
        int ret;
        if (dungeon[r][c] >= 0) {
            ret = mini - dungeon[r][c];
            ret = max(ret, 1);         // alive when arriving
        } else {
            ret = mini - dungeon[r][c]; // enough to survive for next moves
        }

        
        dp[r][c] = ret;
        return ret;
    }
};
