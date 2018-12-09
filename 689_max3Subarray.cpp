class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        // no need to check k

        vector<int> k_sum;
        int sum = 0;
        int size = nums.size();
        
        for (int i = 0; i < k; ++i) sum += nums[i];
        k_sum.push_back(sum);

        for (int i = k; i < size; ++i) {
            sum = sum + nums[i] - nums[i-k];
            k_sum.push_back(sum);
        }
        
        int max_v = 0;
        int k_sum_size = k_sum.size();
        
        vector<int> lt_max(k_sum_size, 0);
        for (int i = 0; i < k_sum_size; ++i) {
            if (max_v < k_sum[i]) {
                max_v = k_sum[i];
                lt_max[i] = i;
            } else {
                lt_max[i] = lt_max[i-1];
            }
        }
        
        max_v = 0;
        vector<int> rt_max(k_sum_size, 0);
        for (int i = k_sum_size - 1; i >= 0; --i) {
            if ( max_v <= k_sum[i]) { // for lexical order
                max_v = k_sum[i];
                rt_max[i] = i;
            } else {
                rt_max[i] = rt_max[i+1];
            }
        }
        
        int max_ret = 0;
        vector<int> ret(3, 0);
        for (int i = k; i + k < k_sum_size; ++i) {
            int val = k_sum[lt_max[i-k]] + k_sum[rt_max[i+k]] + k_sum[i];
            if (val > max_ret) {
                max_ret = val;
                ret[0] = lt_max[i-k];
                ret[1] = i;
                ret[2] = rt_max[i+k];
            }
        }
        return ret;
    }
};
