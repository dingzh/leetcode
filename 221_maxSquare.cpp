class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if (!row) return 0;
        int col = matrix[0].size();
        if (!col) return 0;
        
        vector<vector<int>> dp(row, vector<int>(col, 0));
        
        int ret = 0;
        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < col; ++c) {
                if (matrix[r][c] == '1') {
                    int up = r > 0 ? dp[r-1][c] : 0;
                    int lt = c > 0 ? dp[r][c-1] : 0;
                    int diag = r > 0 && c > 0 ? dp[r-1][c-1] : 0;
                    dp[r][c] = min(diag, min(up, lt)) + 1;
                    ret = max(ret, dp[r][c]);
                } 
            }
        }
        return ret*ret;
    }
};
