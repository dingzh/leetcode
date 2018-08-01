class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (!n) return 0;
        
        int *val = new int[n + 1];
        val[0] = 0;
        val[1] = nums[0];
        
        for (int i = 2; i <= n; ++i) {
            int pick = val[i-2] + nums[i-1];
            int nopick = val[i-1];
            val[i] = max(pick, nopick);
        }
        
        return val[n];
    }
};
