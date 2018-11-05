class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;

        permuteUniqueAux(0, nums, ret);
        return ret;
    }

    void permuteUniqueAux(int start, vector<int>& nums, vector<vector<int>>& ret) {
        int size = nums.size();
        if (start == size) {
            ret.emplace_back(nums);
            return ;
        }

        unordered_set<int> used;
        for (int i = start; i < size; ++i ) {
            if (used.count(nums[i])) continue;
            used.insert(nums[i]);
            swap(nums[i], nums[start]);
            permuteUniqueAux(start + 1, nums, ret);
            swap(nums[i], nums[start]);
        }
    }
};
