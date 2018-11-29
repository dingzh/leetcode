class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int size = A.size();
        assert(size);
        
        int sum = accumulate(cbegin(A), cend(A), 0);

        const int& (*pmin)(const int&, const int&) = min;
        const int& (*pmax)(const int&, const int&) = max;
        
        int max_val = findOptimumComp(A, pmax);
        int min_val = findOptimumComp(A, pmin);
        
        return min_val == sum ? max_val : max(max_val, sum - min_val);
    }
    
    int findOptimumComp(vector<int>& A, function<const int&(const int&, const int&)> comp) {
        // A is not empty
        int optimum = A[0];
        int prefix = 0;
        for (int i = 0; i < A.size(); ++i) {
            prefix = A[i] + comp(prefix, 0);
            optimum = comp(prefix, optimum);
        }
        
        return optimum;
    }
};
