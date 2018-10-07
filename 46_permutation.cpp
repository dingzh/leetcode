class Solution {
    vector<vector<int>> ret;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        permuteHelper(nums, 0, nums.size());
        return ret;
    }

    void permuteHelper(vector<int>& nums, int begin, int end) {
        if (begin == end) {
            ret.emplace_back(nums.begin(), nums.end());
            return ;
        }

        permuteHelper(nums, begin+1, end);
        for (int i = begin + 1; i < end; ++i) {
            swap(nums, begin, i);
            permuteHelper(nums, begin+1, end);
            swap(nums, begin, i);
        }

    }

    void swap(vector<int>& nums, int x, int y) {
        int tmp = nums[x];
        nums[x] = nums[y];
        nums[y] = tmp;
    }
};
