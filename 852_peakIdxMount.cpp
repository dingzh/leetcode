class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int lt = 0, rt = A.size()-1;
        for(;;) {
            int mid = (lt + rt) / 2;
            if (A[mid-1] < A[mid] && A[mid] < A[mid+1]) {
                lt = mid;
            } else if (A[mid-1] > A[mid] && A[mid] > A[mid+1]) {
                rt = mid;
            } else {
                return mid;
            }
        }
    }
};
