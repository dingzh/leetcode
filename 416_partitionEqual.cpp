class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0; 
        for (int num : nums) sum += num;
        if (num & 1) return false;

        int target = sum >> 1;
        vector<int> possible_sum(target + 1, 0);
        possible_sum[0] = 1;
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            for (int j = target; j - num >= 0; --j) {
                if (possible_sum[j-num] == 1) possible_sum[j] = 1;
            }
            if (possible_sum[target]) return true;
        }

        return false;
    }
};
