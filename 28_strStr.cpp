class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.length() == 0) return 0;
        int shift[128];
        for (int i = 0; i < 128; ++i) shift[i] = -1;

        for (int i = 0; i < needle.length(); ++i) {
                shift[needle[i]] = i;
        }

        int i = 0;
        int sLen = haystack.length(), pLen = needle.length();

        while (i + pLen <= sLen) {
                int j = 0;
                while (j < pLen && haystack[i+j] == needle[j]) ++j;
                if (j == pLen) {
                        return i;
                } else if(i + pLen < sLen) {
                        i = i + pLen - shift[haystack[i+pLen]];
                } else {
                        return -1;
                }
        }

        return -1;
    }
};
