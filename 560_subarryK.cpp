class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ret = 0;
        unordered_map<int, int> prefix_sum_count;
        prefix_sum_count[0] = 1;

        int prefix_sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            prefix_sum += nums[i];
            if ( prefix_sum_count.count(prefix_sum - k) ) {
                ret += prefix_sum_count[prefix_sum - k];
            }
            ++prefix_sum_count[prefix_sum];
        }
        return ret;
    }
};
