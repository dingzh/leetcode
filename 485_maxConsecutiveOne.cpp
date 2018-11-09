class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int prev = 0, count = 0, max_count = 0;
        for (int num : nums) {
            if (prev && num) ++count;
            else if (prev && !num) {
                max_count = max(max_count, count);
                prev = 0;
                count = 0;
            } else if(!prev && num) {
                ++count;
                prev = 1;
            }
        }
        return max(max_count, count);
    }
};
