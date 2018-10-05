class Solution {
public:
    int numDecodings(string s) {
        const int len = s.length();
        if (!len) return 0;
        
        int* dp = new int[len + 1];
        dp[len] = 1;
        dp[len-1] = s[len-1] == '0' ? 0 : 1;

        for (int i = len - 2; i > -1; --i) {
            if (s[i] == '0') {
                dp[i] = 0;
                continue;
            }

            int ret = dp[i+1];
            int val = toInt(s[i], s[i+1]);
            if (val <= 26) ret += dp[i+2];
            dp[i] = ret;
        }

        int ret = dp[0];
        delete [] dp;
        return ret;
    }
    
    int toInt(int x, int y) {
        return  (x - '0') * 10 + y - '0';
    }
};
