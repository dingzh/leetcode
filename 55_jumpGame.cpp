class Solution {
public:
    bool canJump(vector<int>& nums) {
        int frontier = 0, size = nums.size();
        for (int i = 0; i <= frontier && frontier < size; ++i) {
            frontier = max(frontier, i + nums[i]);
        }
        return frontier >= size-1;
    }
};
