class Solution {
    vector<vector<int>> ret;
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int size = nums.size();
        if (size == 0 || nums[0] > 0) return ret;
        for (int begin = 0; begin < size - 2; ++begin) {
            helper(nums, begin);
            while (begin < size-2 && nums[begin] == nums[begin+1])
                ++begin;
        }

        return ret;
    }

    void helper(vector<int>& nums, int begin) {
        int target = -nums[begin];
        int p = begin + 1, t = nums.size() - 1;

        while ( p < t ) {
            int sum = nums[p] + nums[t];
            if (sum < target) {
                ++p;
            } else if (sum > target) {
                --t;
            } else {
                ret.push_back({nums[begin], nums[p], nums[t]});
                while (p < t && nums[p] == nums[++p]);
            }
        }
    }
};
