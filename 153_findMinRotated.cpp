class Solution {
public:
    int findMin(vector<int>& nums) {
        int size = nums.size();
        if (!size) return 0;

        int lt = 0, rt = size - 1;
        while (lt < rt) {
            int mid = (lt + rt) >> 1;
            if (nums[mid] < nums[rt]) rt = mid;
            else lt = mid + 1;
        }
        return nums[rt];
    }
};
