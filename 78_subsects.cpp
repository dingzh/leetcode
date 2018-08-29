class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> subset;

        helper(0, nums, subset, ret);
        return ret;
    }

    void helper(int l, const vector<int>& nums, vector<int>& subset, vector<vector<int>>& ret) {
        if (l == nums.size()) ret.push_back(subset);
        else {
            subset.push_back(nums[l]);
            helper(l + 1, nums, subset, ret);
            subset.pop_back();
            helper(l + 1, nums, subset, ret);
        }
    }
};
