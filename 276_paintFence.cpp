class Solution {
public:
    int numWays(int n, int k) {
        if (k == 0) return 0;
        
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        dp[1] = k;
        
        for (int i = 2; i <= n; ++i) {
            dp[i] = (dp[i-1] + dp[i-2]) * (k - 1);
        }
        
        return dp[n] + dp[n-1];
    }
};
