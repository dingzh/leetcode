class Solution {
public:
    void sortColors(vector<int>& nums) {
        int begin = 0, curr = 0, end = nums.size() - 1;

        while (curr < end) {
            if (nums[curr] == 0) {
                // swap curr and begin, both move forward
                nums[curr] = nums[begin];
                nums[begin] = 0;
                ++curr;
                ++begin;
            } else if (nums[curr] == 2) {
                nums[curr] = nums[end];
                nums[end] = 2;
                --end;
            } else {
                ++curr;
            }
        }
    }
};
