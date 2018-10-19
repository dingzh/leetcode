class Solution {
public:
    int longestValidParentheses(string s) {
        int maxv = 0;
        int len = s.length();
        vector<int> dp(len, 0);

        for (int i = 1; i < len; ++i) {

            int idx = i - dp[i-1] - 1;
            if (idx > -1 && s[i] == ')' && s[idx] == '(') {
                dp[i] = dp[i-1] + 2;
                // join prev valid
                if (idx >= 1) dp[i] += dp[idx-1]; 
                maxv = max(maxv, dp[i]);
            } 
        }

        return maxv;
    }
};
