class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int row = A.size();
        int size = A[0].size();
        
        for (int r = 0; r < row; ++r) {
            int lt = 0, rt = size - 1;
            vector<int>& Ar = A[r];
            while (lt < rt) {
                if (Ar[lt] == Ar[rt]) {
                    Ar[lt] ^= 1;
                    Ar[rt] ^= 1;
                }
                ++lt; --rt;
            }
            if (lt == rt) Ar[lt] ^= 1;
        }
        return A;
    }
};
