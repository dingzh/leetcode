class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.length();
        if (!size) return 0;

        int* lastSeen = new int[256];
        fill(lastSeen, lastSeen + 256, -1);

        int maxLen = 0;
        int begin = 0;
        for (int idx = 0; idx < size; ++idx) {
            char ch = s[idx];
            if (lastSeen[ch] >= begin) {
                begin = lastSeen[ch] + 1;
            } else {
                int len = idx - begin + 1;
                maxLen = max(len, maxLen);
            }

            lastSeen[ch] = idx;
        }

        return maxLen;
    }
};
