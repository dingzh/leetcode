class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int lt = 0, rt = nums.size() - 1;
        while (true) {
            int pos = partition(nums, lt, rt);
            if (pos == k - 1) {
                return nums[pos];
            } else if (pos < k - 1) {
                lt = pos + 1;
            } else {
                rt = pos - 1;
            }
        }
    }
    
    int partition(vector<int>& nums, int start, int end) {
        // start != end
        int lt = start-1, mid = start, rt = end;
        int pivot = min(nums[start], nums[end]);
        pivot = max(pivot, nums[(start + end)/2]);
        
        while (mid <= rt) {
            if (nums[mid] == pivot) {
                ++mid;
            } else if (nums[mid] > pivot) {
                ++lt;
                swap(nums[mid], nums[lt]);
                ++mid;
            } else {
                swap(nums[rt], nums[mid]);
                --rt;
            }
        }
        return mid - 1;
    }
};
