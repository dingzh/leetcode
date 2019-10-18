class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> val_to_idx;
        
        for (int i = 0; i < nums.size(); ++i) {
            int diff = target - nums[i];
            if (val_to_idx.find(diff) != val_to_idx.end()) {
                return {val_to_idx[diff], i};
            }
            
            val_to_idx[nums[i]] = i;
        }
        
        return {};
    }
};
