class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if (m & n == 0) return 0;
        
        while (m < n) {
            n = n & (n-1);
        }
        return n;
    }
};
