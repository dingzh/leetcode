class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int size = nums.size();
        if (size == 0) return {};
        vector<int> ret(size, 0);

        int curr = 1;
        for (int i = 0; i < size; ++i) {
            curr = nums[i] * curr;
            ret[i] = curr;
        }

        curr = 1;
        for (int i = size-1; i > 0; --i) {
            ret[i] = ret[i-1] * curr;
            curr *= nums[i];
        }
        ret[0] = curr;
        return ret;
    }
};
