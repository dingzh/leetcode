class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;
        int lt = 1, rt = x;

        // find the least num s.t. num^2 is greater than x
        while (lt < rt) {
            long long mid = lt + (rt - lt)/2;
            long long sq = mid * mid;
            if (sq <= x) {
                lt = mid + 1;
            } else {
                rt = mid;
            }
        }
        return rt - 1;
    }
};
