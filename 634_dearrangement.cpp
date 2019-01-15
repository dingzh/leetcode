class Solution {
public:
    int findDerangement(int n) {
        long mod = 1'000'000'007;
        if (!n) return n;
        if (n <= 3) return n - 1;
        
        // dp[n] = (n-1) * (dp[n-1] + dp[n-2])
        long a = 0, b = 1;
        for (int i = 3; i <=n; ++i) {
            long next = (i-1) * (a + b);
            next %= mod;
            a = b;
            b = next;
        }
        
        return b;
    }
};
