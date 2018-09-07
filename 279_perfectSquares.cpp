class Solution {
public:
    int numSquares(int n) {
        if (n % 8 == 7) return 4;
        while (n && 3 == 0) n >>= 2;
        
        vector<int> pac(n+1, 0);
        for (int j = 0; j <=n; ++j) pac[j] = -j;

        for (int root = 2; root <= sqrt(n); ++root) {
            int inc = root * root;
            for (int j = inc; j <= n; ++j) {
                if (pac[j-inc] - 1 > pac[j]) pac[j] = pac[j-inc] -1;
            }
        }

        return -pac[n];
    }
};
