class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int size = nums.size();
        if (size < 3) return false;

        array<int, 4> dp;
        dp.fill(numeric_limits<int>::max());
        dp[0] = numeric_limits<int>::min();

        for (int num : nums) {
            for (int i = 1; i < 4; ++i ) {
                if ( (num > dp[i-1] || (i == 1 && num == dp[0])) && num <= dp[i]) {
                    if (i == 3) return true;
                    dp[i] = num;
                    break;
                }
            } 
        }

        return false;
    }
};
