class Solution {
public:
    string minWindow(string S, string T) {
        int slen = S.size(), tlen = T.size();
        if (slen < tlen) return "";

        vector<int> dp(tlen, -1);
        dp[0] = S[0] == T[0] ? 0 : -1;

        int min_len = slen + 1;
        int min_start = 0;
        for (int i = 1; i < slen; ++i) {

            for (int j = tlen - 1; j > 0; --j) {
                if(S[i] == T[j])  dp[j] = dp[j-1];
            }

            if (S[i] == T[0]) dp[0] = i;

            int start = dp.back();
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
