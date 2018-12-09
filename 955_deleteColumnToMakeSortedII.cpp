class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        queue<int> idx_to_check;
        int size = A.size();
        if (size <=1) return 0;

        for (int i = 1; i < size; ++i) {
            idx_to_check.push(i);
        }
        
        int ret = 0;
        int len = A[0].length();
        for (int c = 0; c < len; ++c) {
            queue<int> idx_backup = idx_to_check;
            int csize = idx_to_check.size();
            while(csize--) {
                int idx = idx_to_check.front();
                idx_to_check.pop();
                if (A[idx][c] < A[idx-1][c]) {
                    idx_to_check = idx_backup;
                    ++ret;
                    break;
                } else if (A[idx][c] == A[idx-1][c]) {
                    idx_to_check.push(idx);
                }
            }
        }
        return ret;
    }
};
