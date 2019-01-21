class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        
        int ret = 0, size = nums.size();
        for (int i = 0; i < size; ++i) {
            
            // O(n) algo to find 2sum smaller
            int lt = i + 1, rt = size - 1;
            int subtarget = target - nums[i];
            while (lt < rt) {
                if (nums[lt] + nums[rt] >= subtarget) --rt;
                else {
                    ret += rt - lt;
                    ++lt;
                }
            }
        }
        
        return ret;
    }
};
