class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        auto inversion_point = is_sorted_until(nums.rbegin(), nums.rend());
        
        if (inversion_point == nums.rend()) {
            reverse(nums.begin(), nums.end());
            return ;
        }
        
        auto least_upper_bound =
            upper_bound(nums.rbegin(), inversion_point, *inversion_point);
        
        iter_swap(least_upper_bound, inversion_point);
        reverse(nums.rbegin(), inversion_point);
    }
};
