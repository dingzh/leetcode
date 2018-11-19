class NumArray {
    int n;
    vector<int> tree;
public:
    NumArray(vector<int> nums) {
        n = nums.size();
        tree = vector<int>(2 * n + 1, 0); // + 1 in case nums is empty()
        for (int i = 0; i < n; ++i) {
            tree[i + n] = nums[i];
        }

        for (int i = n-1; i > 0; --i) {
            tree[i] = tree[2 * i] + tree[2 * i + 1];
        }
        // for (int i = 0; i < 2 * n; ++i) cout << tree[i] << endl; 
    }

    void update(int i, int val) {
        int idx = i + n;
        int delta = val - tree[idx];
        while (idx) {
            tree[idx] += delta;
            idx >>= 1;
        }
    }

    int sumRange(int i, int j) {
        int ret = 0;
        i += n;
        j += n;

        while (i <= j) {
            if (i & 1) { // i is right child
                ret += tree[i];
                ++i;
            }
            if ((j & 1) == 0) { // j is left child
                ret += tree[j];
                --j;
            }
            i >>= 1;
            j >>= 1;
        }
        return ret;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
