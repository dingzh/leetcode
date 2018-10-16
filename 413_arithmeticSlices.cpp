class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int size = A.size();
        if (size < 3) return 0;
        
        int ret = 0;
        int prev = A[1] - A[0];
        int acc = 1;
        
        for (int i = 2; i < size; ++i) {
            int diff = A[i] - A[i-1];
            if (diff == prev) {
                ret += acc;
                ++acc;
            } else {
                prev = diff;
                acc = 1; 
            }
        }
        return ret;
    }
};
