class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0, size = nums.size();
        if (size < 3) return size;
        
        int cnt = 1, val = nums[0];
        for (int i = 1; i < size; ++i) {
            if (val == nums[i]) {
                ++cnt;
                if (cnt < 3) nums[++index] = nums[i];
            } else {
                cnt = 1;
                val = nums[i];
                nums[++index] = val;
            }
        }
        return index + 1;
    }
};
