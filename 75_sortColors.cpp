class Solution {
public:
    void sortColors(vector<int>& nums) {
        int less_end = 0, unseen_begin = 0, greater_begin = nums.size();

        while (unseen_begin < greater_begin) {
            if (nums[unseen_begin] == 1) {
                ++unseen_begin;
            } else if (nums[unseen_begin] == 0) {
                nums[unseen_begin] = 1;
                nums[less_end] = 0;
                ++less_end;
                ++unseen_begin;
            } else {
                nums[unseen_begin] = nums[--great_begin];
                nums[greater_begin] = 2;
            }
        }
    }
};
