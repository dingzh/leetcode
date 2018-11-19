class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int size = nums.size();
        vector<int> ret;
        
        for (int i = 0; i < size; ++i) {
            while (nums[i] != 0 && nums[i] != i + 1) {
                if (nums[ nums[i] - 1 ] == nums[i]) {
                    ret.push_back(nums[i]);
                    nums[i] = 0;
                    break;
                } else {
                    swap(nums[i], nums[ nums[i] - 1]);
                }
            }
        }
        return ret;
    }
};
