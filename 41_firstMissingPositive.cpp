class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        for (int num = 1; num <= size; ++num) {
            int idx = num - 1;
            while (nums[idx] != num && nums[idx] > 0 && nums[idx] - 1 < size) {
                int tmp = nums[idx];
                int swap_idx = nums[idx] - 1;
                if (nums[idx] == nums[swap_idx]) break;
                nums[idx] = nums[swap_idx];
                nums[swap_idx] = tmp;
            }
        }
        
        for (int i = 0; i < size; ++i) {
            if (i+1 != nums[i]) return i + 1;
        }
        
        return size + 1;
    }
};
