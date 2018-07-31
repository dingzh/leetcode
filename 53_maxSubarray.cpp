class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }

    int helper(vector<int>& nums, int lt, int rt) {
        if (lt == rt) return nums[lt];
        int mid = (lt + rt) >> 1;

        int ltMax = helper(nums, lt,mid);
        int rtMax = helper(nums, mid+1, rt);

        int sum = 0;
        int midLeftMax = 1u << 31, midRightMax = 1u << 31;
        for (int i = mid; i >= lt; --i) {
            sum += nums[i];
            midLeftMax = max(midLeftMax, sum);
        }

        sum = 0;
        for (int i = mid+1; i <= rt; ++i) {
            sum += nums[i];
            midRightMax = max(midRightMax, sum);
        }

        return max(max(ltMax, rtMax), midLeftMax+midRightMax);
    }
};
