class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        
        int min_idx = findMin(nums);
        if (target <= nums.back()) {
            return binarySearch(nums, min_idx, nums.size(), target);
        } else {
            return binarySearch(nums, 0, min_idx, target);
        }
    }
    
    int findMin(vector<int>& nums) {
        int lt = 0, rt = nums.size() - 1;
        while (lt < rt) {
            int mid = lt + ( rt - lt ) / 2;
            if (nums[mid] < nums[rt]) {
                rt = mid;
            } else {
                lt = mid + 1;
            }
        }
        return lt;
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




