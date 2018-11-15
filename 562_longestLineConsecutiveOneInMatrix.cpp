class Solution {
    typedef array<int, 4> Cell;
public:
    int longestLine(vector<vector<int>>& M) {
        int m = M.size();
        if (m == 0) return 0;
        int n = M[0].size();
        if (n == 0) return 0;

        int ret = 0;
        vector<vector<Cell>> dp(m, vector<Cell>(n, {0,0,0,0}));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!M[i][j]) continue; // all will be zero, as defaulted
                Cell& c = dp[i][j];
                c[0] = 1;
                if (j > 0 && dp[i][j-1][0]) c[0] += dp[i][j-1][0];
                c[1] = 1;
                if (j > 0 && i > 0 && dp[i-1][j-1][1]) c[1] += dp[i-1][j-1][1];
                c[2] = 1;
                if (i > 0 && dp[i-1][j][2]) c[2] += dp[i-1][j][2];
                c[3] = 1;
                if (i > 0 && j<n-1 && dp[i-1][j+1][3]) c[3] += dp[i-1][j+1][3];
                ret = max(ret, max( max(c[0], c[1]), max(c[2], c[3]) ));
            }
        }
        return ret;
    }
};
