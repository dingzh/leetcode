class Solution {
public:
    bool isMatch(string s, string p) {
        int slen = s.length(), plen = p.length();
        
        vector<int> dp(slen + 1, 0);
        dp[0] = 1;
        
        for (char pchar : p) {
            stack<int> stk;
            for (int j = slen; j >= 0; --j) {
                
                if (dp[j]) {
                    while (!stk.empty()) {
                        dp[stk.top()] = 1;
                        stk.pop();
                    }
                    if (pchar == '*') dp[j] = 1;
                }
                
                switch (pchar) {
                    case '?':
                        dp[j] = j > 0 ? dp[j-1] : 0; break;
                    case '*':
                        stk.push(j); break;
                    default:
                        dp[j] = (j > 0 && pchar == s[j-1]) ? dp[j-1] : 0;
                }
            }
        }
        
        return dp.back();
    }
};
