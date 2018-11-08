class Solution {
public:
    bool checkValidString(string s) {
        int lo = 0, hi = 0;

        for (auto ch : s) {
            switch (ch) {
                case '(':
                    ++lo;
                    ++hi;
                    break;
                case ')':
                    --lo;
                    --hi;
                    if (hi < 0) return false;
                    break;
                default:
                    --lo;
                    ++hi;
                    lo = max (0, lo);
            }
        }

        return lo == 0;
    }
};
