class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int size = A.size();
        if (!size) return 0;
        
        sort(begin(A), end(A));
        int minval = A[0];
        
        int ret = 0;
        for (int i = 1; i < size; ++i) {
            if (A[i] <= minval) {
                ret += minval - A[i] + 1;
                minval += 1;
            } else {
                minval = A[i];
            }
        }
        return ret;
    }
};
