class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> num_count;
        if (!k) return false;
        
        int size = nums.size();
        int window = k + 1; // max dist = k -> window size k + 1
        int init = min(size, window);
        
        for (int i = 0; i < init; ++i) {
            if (num_count[nums[i]]++) return true;
        }
        
        for (int i = window; i < size; ++i) {
            --num_count[nums[i-window]];
            if (num_count[nums[i]]++) return true;
        }
        
        return false;
    }
};
