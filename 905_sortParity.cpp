class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int size = A.size();
        
        int lt = -1;
        for (int i = 0; i < size; ++i) {
            if ( (A[i] & 1) == 0 ) { // even
                ++lt;
                swap(A[lt], A[i]);
            }
        }
        
        return A;
    }
};
