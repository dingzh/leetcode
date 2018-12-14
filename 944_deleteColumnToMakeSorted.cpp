class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int size = A.size();
        if (!size) return 0;
        
        int ret = 0, len = A[0].length();
        for (int i = 0; i < len; ++i) {
            char prev = '\0';
            for (int r = 0; r < size; ++r) {
                if (prev > A[r][i]) {
                    ++ret;
                    break;;
                }
                prev = A[r][i];
            }
        }
        return ret;
    }
};
