class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lt = 0, rt = nums.size();

        while (lt != rt) {
            int mid = (lt + rt) >> 1;
            if (nums[mid] < target) {
                lt = mid + 1;
            } else if (nums[mid] > target) {
                rt = mid; 
            } else {
                return mid;
            }
        }

        return lt;
    }
};
