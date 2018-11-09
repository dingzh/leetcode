class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        vector<int> res;
        sort(nums.begin(), nums.end());
        kSum(4, nums, 0, target, ret, res);
        return ret;
    }
    
    void kSum(int k, vector<int>& nums, int begin, int target,
             vector<vector<int>>& ret, vector<int>& res) {
        int size = nums.size();
        if (begin + k > size) return;

        
        if (k == 2) {
            int lt = begin, rt = size -1;
            while (lt < rt) {
                int sum = nums[lt] + nums[rt];
                if (sum < target) ++lt;
                else if (sum > target) --rt;
                else { // found one sol
                    ret.emplace_back( res );
                    ret.back().push_back(nums[lt]);
                    ret.back().push_back(nums[rt]);
                    ++lt;
                    while (lt < rt && nums[lt] == nums[lt-1]) ++lt;
                }
            }
        } else {
            for (int i = begin; i < size; ++i) {
                if (begin - i == 0 || nums[i] != nums[i-1]) {
                    res.push_back(nums[i]);
                    kSum(k-1, nums, i+1, target-nums[i], ret, res);
                    res.pop_back();
                }
            }
        }
    }
};
