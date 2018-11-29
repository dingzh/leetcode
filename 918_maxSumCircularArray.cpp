class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int size = A.size();
        if (!size) return 0;
        
        int suffix = 0, max_suffix = 0;
        vector<int> aux(size, 0);
        for (int i = size - 1; i >= 0; --i) {
            suffix += A[i];
            max_suffix = max(max_suffix, suffix);
            aux[i] = max_suffix;
        }
        
        int max_val = A[0]; // make sure non-empty
        int dp = 0, prefix = 0;
        for (int i = 0; i < size; ++i) {
            dp = A[i] + max(dp, 0);
            prefix += A[i];
            max_val = max(dp, max_val);
            if (i + 1 < size)
                max_val = max(prefix + aux[i + 1], max_val);
        }
        return max_val;
    }
};
