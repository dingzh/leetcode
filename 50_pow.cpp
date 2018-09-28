class Solution {
public:
    double myPow(double x, int n) {
        // std::nan -> cant compare x to 0
        if (n == 0) return 1;

        bool neg = n < 0;
        unsigned int exp = neg ? -n : n;
        double res = helper(x, n);

        return neg ? 1/res : res;
    }

    // n > 0 is assured
    double helper(double x, unsigned int exp) {
        if (exp == 1) return x;

        double res = helper(x, exp >> 1);
        res *= res;
        if (exp & 1) res *= x;

        return res;
    }
};
