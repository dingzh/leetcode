class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long sum = 0;
        sum = accumulate(begin(nums), end(nums), sum);
        
        long lt = sum / m, rt = sum;
        while (lt < rt) {
            int mid = lt + (rt - lt) / 2;
            if (canSplit(nums, mid, m)) {
                rt = mid;
            } else {
                lt = mid + 1;
            }
        }
        return lt;
    }
    
    bool canSplit(const vector<int>& nums, const int target, const int m) {
        int cnt = 0;
        long sum = 0;
        for (auto num : nums) {
            if (num > target || cnt > m) return false;
            
            sum += num;
            if (sum > target) {
                sum = num;
                ++cnt;
            }
        }
        
        if (sum) ++cnt;
        return cnt <= m;
    }
};

