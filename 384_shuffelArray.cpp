class Solution {
    vector<int> orig;
    default_random_engine re{random_device{}()};
    
public:
    Solution(vector<int> nums):orig(move(nums)) {
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return orig;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        auto ret = orig;
        int size = ret.size();
        for (int i = size-1; i > 0; --i) {
            uniform_int_distribution<int> dis(0, i);
            int idx = dis(re);
            swap(ret[i], ret[idx]);
        }
        return ret;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
