class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int pos = strStr(A, B);
        if (pos == -1) return -1;

        return (pos + B.length() - 1) / A.length() + 1;
    }

    // return first idx in A if matched, -1 if not
    int strStr(string& A, string& B) {
        int shift[256] = {0};
        int lenA = A.length(), lenB = B.length();
        
        for (int i = 0; i < lenB; ++i) {
            shift[ B[i] ] = i;
        }
        
        int i = 0;
        while (i < lenA) {
            int j = 0;
            while (j < lenB && A[(i+j)%lenA] == B[j]) ++j;
            if (j == lenB) return i;
            else i = i + (lenB - shift[ A[(i+lenB)%lenA] ]);
        }
        return -1;
    }
};
