class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        vector<int> prefix_sum;
        int sum = 0, size = nums.size();
        
        int ret = size + 1;
        for (int i = 0; i < size; ++i) {
            sum += nums[i];
            if (sum >= s) ret = min(ret, i + 1);
            prefix_sum.push_back(sum);
        }
        
        for (int i = 0; i < size; ++i) {
            auto it = lower_bound(begin(prefix_sum), end(prefix_sum), prefix_sum[i] + s);
            if (it == end(prefix_sum)) break;
            
            int tmp = distance(begin(prefix_sum), it) - i;
            ret = min(ret, tmp);
        }
        
        return ret <= size ? ret : 0;
    }
};
