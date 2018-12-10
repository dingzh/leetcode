class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (!size) return 0;
        if (size == 1) return nums[0];
        
        int ret1 = robAux(nums, 1);
        nums.pop_back();
        int ret2 = robAux(nums, 0);
        return max(ret1, ret2);
    }
    
    int robAux(vector<int>& nums, int start) {
        int tminus1 = 0;
        int tminus2 = 0;
        int size = nums.size();
        for (int i = start; i < size; ++i) {
            int curr = max(tminus1, tminus2 + nums[i]);
            tminus2 = tminus1;
            tminus1 = curr;
        }
        return tminus1;
    }
};
