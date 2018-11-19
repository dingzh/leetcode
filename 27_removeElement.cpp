class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int start = 0, end = nums.size() - 1;
        
        while (start <= end) {
            if (nums[start] == val) {
                nums[start] = nums[end--];
            } else {
                ++start;
            }
        }
        return end + 1;
    }
};
