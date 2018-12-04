class Solution {
public:
    int numDistinct(string s, string t) {
        int len_s = s.length(), len_t = t.length();
        if (len_s < len_t) return 0;
        
        vector<vector<int>> dp(len_t + 1, vector<int>(len_s + 1, 0));
        
        for (int i = 0; i <= len_s; ++i)
            dp[0][i] = 1;
        
        for (int i = 1; i <= len_t; ++i) {
            for (int j = 1; j <= len_s; ++j ) {
                dp[i][j] = dp[i][j-1];
                if (t[i-1] == s[j-1])  dp[i][j] += dp[i-1][j-1];
            }
        }
        
        return dp[len_t][len_s];
    }
};
