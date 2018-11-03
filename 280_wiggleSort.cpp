class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        bool ascend = true;
        for (int i = 1; i < nums.size(); ++i) {
            if (ascend && nums[i-1] > nums[i] || !ascend && nums[i-1] < nums[i]) {
                swap(nums[i-1], nums[i]);
            }
            ascend ~= ascend;
        }
    }
};
