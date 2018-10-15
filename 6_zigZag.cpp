class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        
        int len = s.length();
        int step = 2 * numRows-2;
        string ret;
        
        for (int i = 0; i < len; i += step) {
            ret += s[i];
        }

        for (int row = 1; row < numRows-1; ++row) {
            for (int start = 0; start < len; start += step) {
                int lt = start + row, rt = start + step - row;
                if (lt < len) ret += s[lt];
                if (rt < len) ret += s[rt];
            }
        }
        
        for (int i = numRows - 1; i < len; i += step) {
            ret += s[i];
        }
        
        return ret;
    }
};
