class BinaryIndexedTree {
    int size;
    vector<int> array;
    static inline int lowbit(int x) { return x & -x; }
public:
    explicit BinaryIndexedTree(int size): array(size+1, 0), size(size) {}
    
    int getSum(int idx) {   // inclusive
        int ret = 0;
        while (idx) {
            ret += array[idx];
            idx -= lowbit(idx);
        }
        return ret;
    }
    
    void update(int idx, int delta) {
        while(idx <= size) {
            array[idx] += delta;
            idx += lowbit(idx);
        }
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        auto nums_d = nums;
        sort(begin(nums_d), end(nums_d));
        unique(begin(nums_d), end(nums_d));
        
        int size_d = nums_d.size();
        BinaryIndexedTree bit(size_d);
        
        unordered_map<int, int> num_to_rank;
        for (int i = 0; i < size_d; ++i) {
            num_to_rank[nums_d[i]] = i + 1;
        }
        
        vector<int> ret(nums.size(), 0);
        for (int i = nums.size() - 1; i >= 0; --i) {
            int rank = num_to_rank[nums[i]];
            ret[i] = bit.getSum(rank-1);
            bit.update(rank, 1);
        }
        
        return ret;
    }
};
