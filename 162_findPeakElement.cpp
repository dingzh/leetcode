class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int size = nums.size();

        int lt = 0, rt = size -1;
        while (lt + 1 < rt) {
            int mid = (lt + rt) >> 1;
            if (nums[mid-1] < nums[mid] && nums[mid+1] < nums[mid])
                return mid;
            
            if (nums[mid - 1] > nums[mid]) 
                rt = mid - 1;
            else
                lt = mid + 1;
        }

        if (lt == rt) return lt;
        if (lt + 1 == rt) return nums[lt] < nums[rt] ? rt : lt;
    }
};
