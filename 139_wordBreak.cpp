class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.length();
        
        unordered_set<string> word_set(wordDict.begin(), wordDict.end());
        vector<bool> dp(len + 1, false);
        dp[0] = true;

        for (int i = 0; i < len; ++i) {
            for (int j = 0; j <= i; ++j) {
                if ( dp[j] && word_set.count( s.substr(j, i-j+1) ) ) {
                    dp[j+1] = true;
                }
            }
        }

        return dp[len];
    }
};
