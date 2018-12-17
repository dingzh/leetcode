class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lt = 0, rt = nums.size() - 1;
        
        while (lt < rt) {
            
            int mid = (rt - lt)/2 + lt;
            // cout << lt << ' ' << rt << ' ' << mid << endl;
            if ((mid & 1) == 0) { // is even
                if (nums[mid] == nums[mid+1]) {
                    lt = mid + 2;
                } else {
                    rt = mid;
                }
            } else { // is odd
                if (nums[mid] == nums[mid-1]) {
                    lt = mid + 1;
                } else {
                    rt = mid;
                }
            }
        }
        
        return nums[lt];
    }
};
