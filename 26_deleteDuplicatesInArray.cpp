class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0, size = nums.size();
        if (!size) return 0;

        for (int i = ; i < size; ++i) {
            if (nums[index] != nums[i]) nums[++index] = nums[i];
        }

        return index + 1;
    }
};
