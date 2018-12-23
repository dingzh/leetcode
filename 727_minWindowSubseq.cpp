class Solution {
public:
    string minWindow(string S, string T) {
        int slen = S.size(), tlen = T.size();
        if (slen < tlen) return "";

        vector<vector<int>> dp(slen, vector<int>(tlen, -1));
        dp[0][0] = S[0] == T[0] ? 0 : -1;

        int min_len = slen + 1;
        int min_start = 0;
        for (int i = 1; i < slen; ++i) {
            dp[i][0] = S[i] == T[0] ? i : dp[i-1][0];

            for (int j = 1; j < tlen; ++j) {
                dp[i][j] = S[i] == T[j] ? dp[i-1][j-1] : dp[i-1][j];
            }
            int start = dp[i].back();
            if (start != -1 && i - start + 1 < min_len) {
                min_start = start;
                min_len = i - start + 1;
            }
        }

        string ret;
        if (min_len <= slen) ret = S.substr(min_start, min_len);
        return ret;
    }
};
