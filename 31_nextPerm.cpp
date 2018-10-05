class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        if (size <= 1) return;

        int i = size - 2;
        while ( i > -1 && nums[i] >= nums[i+1]) --i;
        if (i == -1) {
            reverse( nums, 0, size - 1 );
            return;
        }

        int p = i + 1;
        int k = p;
        while (k < size && nums[k] > nums[i]) ++k;
        --k;

        swap(nums, i, k);
        reverse(nums, p, size - 1);
    }
    
    // end included
    void reverse(vector<int> &nums, int begin, int end) {
        while (begin < end) {
            swap(nums, begin, end);
            ++begin;
            --end;
        }
    }

    void swap(vector<int> &nums, int x, int y) {
        int temp = nums[x];
        nums[x] = nums[y];
        nums[y] = temp;
    }
};
