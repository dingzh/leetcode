class NumArray {
    int size;
    vector<int> _nums;
    vector<int> idx_arr;
public:
    NumArray(vector<int> nums): idx_arr(nums.size()+1, 0) {
        _nums = move(nums);
        size = _nums.size();
        for ( int i = 0; i < _nums.size(); ++i ) {
            updateAux(i+1, _nums[i]);
        }
    }
    
    void update(int i, int val) {
        int delta = val - _nums[i];
        _nums[i] = val;
        updateAux( i+1, delta );
    }
    
    int sumAux(int idx) {
        int ret = 0;
        while (idx > 0) {
            ret += idx_arr[idx];
            idx -= (-idx) & idx;
        }
    }

    void updateAux(int idx, int delta) {
        while (idx <= size) {
            idx_arr[idx] += delta;
            idx += (-idx) & idx;
        }
    }
    
    int sumRange(int i, int j) {
        return sumAux(j + 1) - sumAux(i);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
