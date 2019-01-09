class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (s <= 0) return 0;

        int lt = 0, rt = 0, sum = 0;
        int ret = nums.size() + 1;
        int size = nums.size();

        while (lt < size) {
            while (sum < s && rt < size) sum += nums[rt++];

            if (sum >= s) ret = min(ret, rt - lt);
            else break;
            sum -= nums[lt++];
        }

        return ret <= nums.size() ? ret : 0;
    }
};
