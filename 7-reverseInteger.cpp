class Solution {
    // overflow guard
    constexpr static int of_guard = ((1<<30) / 5);
public:
    int reverse(int x) {
        int ret = 0;
        while (x) {
            if (ret > of_guard || ret < -of_guard) {
                return 0;
            }
            ret = ret * 10 + x % 10;
            x = x / 10;
        }
        
        return ret;
    }
};
