class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxHelper(nums, 0, nums.size()-1);
    }

    int maxHelper(vector<int>& nums, int lt, int rt) {
        if (lt == rt) return nums[lt];
        
        int mid = lt + (rt - lt) / 2;
        int lt_max = maxHelper(nums, lt, mid);
        int rt_max = maxHelper(nums, mid+1, rt);

        int lt_suffix_max = 0, rt_prefix_max = 0, temp;
        temp = 0;
        for (int i = mid-1; i >= lt; --i) {
            temp += nums[i];
            lt_suffix_max = max(lt_suffix_max, temp);
        }
        temp = 0;
        for (int i = mid+1; i <=rt; ++i) {
            temp += nums[i];
            rt_prefix_max = max(rt_prefix_max, temp);
        }

        int mid_max = lt_suffix_max + rt_prefix_max + nums[mid];

        return max(mid_max, max(lt_max, rt_max));
    }
};
