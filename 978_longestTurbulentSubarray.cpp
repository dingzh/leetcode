class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int size = A.size();
        if (size < 2) return size;

        int inc_len = 1;
        int dec_len = 1;
        int ret = 1;

        for (int i = 1; i < size; ++i) {
            if (A[i] > A[i-1]) {
                inc_len = dec_len + 1;
                dec_len = 1;
                ret = max(ret, inc_len);
            } else if (A[i] < A[i-1]) {
                dec_len = inc_len + 1;
                inc_len = 1;
                ret = max(ret, dec_len);
            } else {
                inc_len = 1;
                dec_len = 1;
            }
        }

        return ret;
    }
};
