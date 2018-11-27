class Solution {
public:
    int minMoves(vector<int>& nums) {
        if (!nums.size()) return 0;
        
        int minval = nums[0];
        int count = 0;
        
        int ret = 0;
        for (int num : nums) {
            if (num < minval) {
                ret += (minval - num) * count;
                minval = num;
            } else {
                ret += (num - minval);
            }
            ++count;
        }
        
        return ret;
    }
};
