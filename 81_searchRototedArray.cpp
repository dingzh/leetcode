class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return false;
        
        int min_idx = findMin(nums);
        
        int idx1 = binarySearch(nums, min_idx, nums.size(), target);
        int idx2 = binarySearch(nums, 0, min_idx, target);
        
        return idx2 != -1 || idx1 != -1;
    }
    
    int findMin(vector<int>& nums) {
        int lt = 0, rt = nums.size() - 1;
        
        // nums[rt-1] <= nums[rt] is important for finding the rightmost min val
        while (lt < rt && nums[rt-1] <= nums[rt]) {
            int mid = lt + ( rt - lt ) / 2;
            if (nums[mid] < nums[rt]) {
                rt = mid;
            } else if (nums[mid] == nums[rt]) {
                rt = rt - 1;
            } else {
                lt = mid + 1;
            }
        }
        return rt;
    }
    
    int binarySearch(vector<int>& nums, int lt, int rt, int target) { // [lt, rt)
        while (lt < rt) {
            int mid = lt + (rt - lt) / 2;
            if (nums[mid] > target) {
                rt = mid;
            } else if (nums[mid] < target) {
                lt = mid + 1;
            } else {
                return mid;
            }
        }
        
        return -1;
    }
};




