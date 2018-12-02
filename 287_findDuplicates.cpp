class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        assert(nums.size() > 1);

        int slow = 0, fast = 0;
        do {
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];
        } while (slow != fast);

        slow = 0;
        while (slow != fast) {
            fast = nums[fast];
            slow = nums[slow];
        }
        
        return slow;
    }
};
