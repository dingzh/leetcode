class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_no_flip = 0, max_with_flip = 0, max_one = 0;
        for (int num : nums) {
            if (num) {
                ++max_no_flip;
                ++max_with_flip;
                max_one = max( max_one, max(max_no_flip, max_with_flip));
            } else {
                max_with_flip = max_no_flip + 1;
                max_no_flip = 0;
                max_one = max( max_one, max_with_flip);
            }
        }
        return max_one;
    }
};
