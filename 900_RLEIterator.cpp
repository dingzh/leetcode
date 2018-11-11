class RLEIterator {
    int idx;
    int size;
    vector<int> A;
public:
    RLEIterator(vector<int> A):A(move(A)) {
        idx = 0;
        size = this->A.size();
    }
    
    int next(int n) {
        int ret;
        while (idx < size && n) {
            if (n <= A[idx]) {
                A[idx] -= n;
                n = 0;
                ret = A[idx+1];
            } else {
                n -= A[idx];
                idx += 2;
            }
        }
        if (n) return -1;
        else return ret;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator obj = new RLEIterator(A);
 * int param_1 = obj.next(n);
 */
