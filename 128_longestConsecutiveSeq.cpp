class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int max_len = 0;
        unordered_set<int> num_set(nums.begin(), nums.end());
        
        for (int num : nums) {
            if (num_set.count( num - 1 )) {
                continue;
            }

            int len = 1;
            while ( num_set.count(num + 1) ) {
                ++len;
                ++num;
            }

            max_len = max( max_len );
        }
        return max_len;
    }
};
