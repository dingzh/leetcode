class Solution {
public:
    int findMin(vector<int>& nums) {
        int size = nums.size();
        if (!size) return 0;
        if (size == 1 ) return nums[0];

        int lt = 0, rt = size - 1;
        while (lt != rt) {
            int mid = (lt + rt) >> 1;
            if (nums[mid] > nums[lt]) lt = mid;
            else rt = mid;
        }
        return min(nums[lt + 1], nums[0]); // in case monotonically increasing
    }
};
