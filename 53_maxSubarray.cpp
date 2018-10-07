class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret = nums[0], max_suffix = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            max_suffix = max(max_suffix, 0) + nums[i];
            ret = max( ret, max_suffix);
        }
        return ret;
    }
};
