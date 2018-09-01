class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m > n) {
            auto tmp = m;
            m = n;
            n = tmp;
        }

        int tmpRes[101][101] = {};
        tmpRes[0][1] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++i) {
                tmpRes[i][j] = tmpRes[i-1][j] + tmpRes[i][j-1];
            }
        }

        return tmpRes[n][m];
    }
};
