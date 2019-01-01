class Solution {
public:
    int countSubstrings(string s) {
        int ret = 0;
        int len = s.length();
        
        for (int i = 0; i < len; ++i) {
            // check for odd length
            for (int l = 0; i - l >= 0 && i + l < len; ++l) {
                if (s[i-l] == s[i+l]) ++ret;
                else break;
            }
            
            // check for even length
            for (int l = 1; i - l + 1 >= 0 && i + l < len; ++l) {
                if (s[i-l+1] == s[i+l]) ++ret;
                else break;
            }
        }
        return ret;
    }
};
