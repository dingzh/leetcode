class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(begin(nums), end(nums), 0);
        if (sum % k) return false;
        if (k == 1 && nums.size()) return true;
        
        int target = sum / k;
        sort(begin(nums), end(nums), greater<int>());
        if (nums[0] > target) return false;
        
        vector<int> sums(k, 0);
        return aux(nums, 0, sums, target, k);
    }
    
    bool aux(vector<int>& nums, int pos, vector<int>& sums, int target, int k) {
        // base
        if (pos == nums.size()) return true;
        
        bool ret = false;
        for (int i = 0; i < k; ++i) {
            // major pruning here
            if (i > 0 && sums[i] == sums[i-1]) continue;
            
            sums[i] += nums[pos];
            
            if (sums[i] <= target) ret = aux(nums, pos + 1, sums, target, k);
            sums[i] -= nums[pos];
            if (ret) return true;
        }
        return false;
    }
};
