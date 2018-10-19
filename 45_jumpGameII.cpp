class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        // only one pos
        if (size==1) return 0;
        
        int step = 1, curr_frontier = 0, next_frontier = 0;
        for (int i = 0; i < size; ++i) {
            // if take another step, where we can reach
            next_frontier = max(next_frontier, nums[i] + i);
            if (next_frontier >= size -1) break;
            if (i == curr_frontier) {
                ++step;
                curr_frontier = next_frontier;
            }
        }
        
        return step;
    }
};
