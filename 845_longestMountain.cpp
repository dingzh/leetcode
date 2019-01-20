class Solution {
public:
    int longestMountain(vector<int>& A) {
        int size = A.size();
        if (size < 3) return 0;
        
        int base = 0, ret = 0;
        
        while (base < size) {
            int end = base;
            if (end + 1 < size && A[end + 1] > A[end]) {
                while (end + 1 < size && A[end + 1] > A[end]) ++end;
                
                if (end + 1 < size && A[end + 1] < A[end]) {
                    while (end + 1 < size && A[end+1] < A[end]) ++end;
                    
                    ret = max(ret, end - base + 1);
                }
            }
            
            base = max(end, base + 1);
        }

        return ret;
    }
};
