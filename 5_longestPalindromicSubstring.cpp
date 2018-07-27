class Solution {
public:
    string longestPalindrome(string s) {
        // extra space
        int len = (s.length() << 1) + 3;
        char *sa = new char[len];
        int *res = new int[len];

        // string easy to handle insert #$^
        sa[0] = '$';
        for (int i = 0; i < s.length(); ++i) {
                sa[(i << 1) + 1] = '#';
                sa[(i << 1) + 2] = s[i];
        }
        sa[len - 2] = '#';
        sa[len - 1] = '^';

        int id = 0, mx = 0;
        // skil the first and last character in sa
        for (int i = 1; i < len - 1; ++i) {
                int pLen = 0;
                if (i < mx) {
                        pLen = min(res[2*id - i], mx - i);
                }
                while (sa[i - pLen] == sa[i + pLen]) ++pLen;
                res[i] = pLen - 1;

                if (i + pLen >= mx) {
                        mx = i + pLen;
                        id = i;
                }
        }

        int center;
        int maxLen = 0;
        for (int i = 1; i < len -1; ++i) {
                if (res[i] > maxLen) {
                        center = i;
                        maxLen = res[i];
                }
        }

        center = (center - 1) >> 1;
        return s.substr(center - maxLen/2, maxLen);
    }
};
