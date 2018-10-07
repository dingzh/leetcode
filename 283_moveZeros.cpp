class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        
        int p = -1, t = 0;
        while (t < size) {
            if (nums[t]) {
                nums[++p] = nums[t];
            }
            ++t;
        }
        
        for (int i = p+1; i < size; ++i) {
            nums[i] = 0;
        }
    }
};
