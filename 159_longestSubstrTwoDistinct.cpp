class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int k = 2;
        array<int, 256> char_cnt;
        for (int& cnt : char_cnt) cnt = 0;
        
        int max_len = 0;
        int n = 0;
        int lt = 0, rt = 0, len = s.length();
        while (rt < len) {
            char ch = s[rt];
            if ( char_cnt[ch]++ == 0 ) { // new character
                ++n;
                if (n > k) {
                    max_len = max( max_len, rt - lt);
                    // remove 1 char
                    while (--char_cnt[s[lt++]]) { }
                    n = k;
                }
            }
            ++rt;
        }
        
        return max( max_len, rt - lt);;
    }
};
