class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> least_ending( nums.size(), 0 );
        
        least_ending[0] = numeric_limits<int>::min();
        int size = 1;
        
        for (auto num : nums) {
            auto end = least_ending.begin() + size;
            auto it = upper_bound( least_ending.begin(), end, num );
            if (num > *(it-1)) {
                if ( it == end ) { ++size; }
                *it = num;
            }
        }
        return size-1;       
    }
};
