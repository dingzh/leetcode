class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> char_to_cnt;
        int odd_cnt = 0;
        for (char ch : s) {
            if (++char_to_cnt[ch] & 1) { // odd
                ++odd_cnt;
            } else {
                --odd_cnt;
            }
        }

        return odd_cnt == 0 || odd_cnt == 1;
    }
};
