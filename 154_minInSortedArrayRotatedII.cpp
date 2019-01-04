class Solution {
    public:
    int findMin(vector<int>& nums) {
        int lt = 0, rt = nums.size() - 1;
        
        // additionally could stop search early if assured 
        // current search scope ascending
        while (lt < rt && nums[lt] >= nums[rt]) {
            int mid = lt + (rt - lt) / 2;
            if (nums[mid] > nums[rt]) {
                lt = mid + 1;
            } else if (nums[mid] == nums[rt]) {
                rt = rt - 1;
            } else {
                rt = mid;
            }
        }

        return nums[lt];
    }
};
