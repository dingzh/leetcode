class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) return 0;
        if (size == 0) return -1;

        int rsum = 0, lsum = 0;
        for (auto n : nums) rsum += n;

        for (int j =0; j < nums.size(); ++j) {
            rsum -= nums[j];
            if (lsum == rsum) return j;
            lsum += nums[j];
        }

        return -1;
    }
};  
