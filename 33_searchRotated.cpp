class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lt = 0, rt = nums.size();
        if (!rt) return -1;
        
        int begin = nums[0];
        while (lt != rt) {
            int mid = (lt + rt) >> 1, midval = nums[mid];
            if (target < begin) {
                if (midval < target) lt = mid + 1;
                else if (target < midval) {
                    if (begin <= midval) {
                        lt = mid + 1;
                    } else {
                        rt = mid;
                    }
                } else {
                    lt = mid;
                    break;
                }
            } else {
                if (target < midval) rt = mid;
                else if (midval < target) {
                    if (begin <= midval) { 
                        lt = mid + 1;
                    } else {
                        rt = mid;
                    }
                } else {
                    lt = mid;
                    break;
                }
            }
            
        }
        if (lt == rt) return -1;
        return lt;
    }
};
