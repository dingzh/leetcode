class Solution {
public:
    
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        
        for (int i = 0; i < size; ++i) {
            while (0 < nums[i] && nums[i] <= size && nums[i] != i+1) {
                int tmp = nums[i];
                swap(nums[tmp-1], nums[i]);
                if (nums[i] == tmp) nums[i] = 0;
            }
        }
        
        for (int i = 0; i < size; ++i) {
            if (nums[i] != i + 1) return i + 1;
        }
        return size+1;
    }
};
