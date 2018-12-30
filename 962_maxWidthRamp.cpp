class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        int ret = 0;
        int size = A.size();
        if (!size) return ret;
        
        vector<int> cand_val;
        vector<int> cand_idx;
        cand_val.push_back(A[0]);
        cand_idx.push_back(0);
        
        for (int i = 1; i < size; ++i) {
            if (A[i] < cand_val.back()) {
                cand_val.push_back(A[i]);
                cand_idx.push_back(i);
            }
            
            auto pos = lower_bound(begin(cand_val), end(cand_val), A[i], greater<int>());
            if (pos == end(cand_val)) continue;

            int idx = distance(begin(cand_val), pos);
            ret = max(ret, i - cand_idx[idx]);
        }
        return ret;
    }
};
