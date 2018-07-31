class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, max = 1u << 31;
        for (auto num : nums) {
            sum += num;
            max = sum > max ? sum : max;
            sum = sum > 0 ? sum : 0;
        }

        return max;
    }
};
