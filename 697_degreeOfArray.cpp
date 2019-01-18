class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int max_cnt = 0;
        unordered_map<int,int> left, right, count;
        for (int i = 0; i < nums.size(); ++i) {
            int val = nums[i];
            int tmp;
            if ( (tmp = ++count[val]) == 1) left[val] = i;
            right[val] = i;
            max_cnt = max(max_cnt, tmp);
        }
        
        if (max_cnt == nums.size()) return max_cnt;
        
        int ret = numeric_limits<int>::max();
        
        for (const auto& p : count) {
            if (p.second == max_cnt) {
                ret = min(ret, right[p.first] - left[p.first] + 1);
            }
        }
        return ret;
    }
};
