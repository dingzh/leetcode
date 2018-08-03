class Solution {
public:
    int trailingZeroes(int n) {
        int ret = 0;
        while (n > 4) {
            n /= 5;
            ret += n;
        }
        return ret;
    }
};
