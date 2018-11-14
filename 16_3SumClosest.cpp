class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int size = nums.size();
        // if (size < 3) return target;
        sort(nums.begin(), nums.end());
        int closest = nums[0] + nums[1] + nums[2];
        int min_diff = abs(closest - target);
        for (int i = 0; i < size - 2; ++i) {
            int first = nums[i];
            int tmp_target = target - first;
            int left = i + 1, right = size - 1;
            while (left < right) {
                int sum = nums[left] + nums[right];
                int diff = abs(tmp_target - sum);
                
                if (min_diff > diff) {
                    min_diff = diff;
                    closest = sum + first;
                }
                
                if (sum < tmp_target) { ++left; }
                else if (sum > tmp_target) { --right;} 
                else { return target; }
            }
        }
        return closest;
    }
};
