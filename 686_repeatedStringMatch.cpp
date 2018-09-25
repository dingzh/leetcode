class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        // length is guaranteed to be in range (1,1000)
        int strLen = A.length(), pattLen = B.length();

        int shift[128];
        fill(shift, shift + 128, -1);
        for (int idx = 0; i < pattLen; ++i)
            shift[B[idx]] = idx;

        int begin = 0;
        while (begin < strLen) {
            int j = 0;
            while (j < pattLen && A[ (begin+j) % strLen ] == B[j]) ++j;
            if (j == pattLen) {
                break;
            } else {
                begin = begin + pattLen - shift[ A[(begin+pattLen) % strLen] ];
            }
        }

        if (begin < strLen) {
            return (begin + pattLen - 1)/strLen + 1;
        } else {
            return -1;
        }
       
    }
};
