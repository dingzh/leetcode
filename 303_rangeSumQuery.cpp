class NumArray {
    int* prefix_sum;
public:
    NumArray(vector<int> nums) {
        int size = nums.size();
        prefix_sum = new int[size+1];
        prefix_sum[0] = 0;
        int sum = 0;
        for (int i = 0; i <  size; ++i) {
            sum += nums[i];
            // right shift by 1 to avoid check
            prefix_sum[i+1] = sum;
        }
    }

    int sumRange(int i, int j) {
        return prefix_sum[j+1] - prefix_sum[i];
    }

    ~NumArray() {
        delete [] prefix_sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
