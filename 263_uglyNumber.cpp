class Solution {
public:
    bool isUgly(int num) {
        if (num < 1) return false;
        while (!(num & 1)) num >>= 1;
        while (!(num % 3)) num /= 3;
        while (!(num % 5)) num /= 5;

        return num == 1;
    }
};
