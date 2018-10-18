class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int first = firstPos(nums, target);
        if (first == -1) return {-1, -1};
        int last = lastPos(nums, target);
        return {first, last};
    }

    int firstPos(vector<int>& nums, int target) {
        int lt = 0, rt = nums.size();
        while (lt < rt) {
            int mid = (lt + rt) / 2;
            if (nums[mid] < target) {
                lt = mid + 1;
            } else {
                rt = mid;
            }
        }
        if (lt < nums.size() && nums[lt] == target) return lt;
        return -1;
    }

    int lastPos(vector<int>& nums, int target) {
        int lt = -1, rt = nums.size()-1;
        while (lt < rt) {
            int mid = (lt + rt + 1) / 2;
            if (nums[mid] > target) {
                rt = mid -1;
            } else {
                lt = mid; 
            }
        }
        if (lt > -1 && nums[lt] == target) return lt;
        return -1;
    }
};
