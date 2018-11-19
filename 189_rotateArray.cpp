class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        if (!size || !k) return ;
        k = k % size;
        
        reverse(begin(nums), end(nums));
        
        auto pivot = nums.begin() + k;
        
        reverse(nums.begin(), pivot);
        reverse(pivot, nums.end());
    }
};
