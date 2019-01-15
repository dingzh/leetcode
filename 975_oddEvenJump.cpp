class Solution {
    struct Result {
        bool even = false;
        bool odd = false;
    };
public:
    int oddEvenJumps(vector<int>& A) {
        int size = A.size();
        if (!size) return 0;
        int ret = 1;
        
        vector<Result> dp(size, Result());
        dp[size - 1].even = true;
        dp[size - 1].odd = true;
        
        map<int, int> val_idx_inc;
        map<int, int, std::greater<int>> val_idx_dec;
        val_idx_inc[A.back()] = size - 1;
        val_idx_dec[A.back()] = size - 1;
        
        for (int i = size - 2; i >= 0; --i) {
            int val = A[i];
            auto it = val_idx_inc.lower_bound(val);
            if (it != val_idx_inc.end()) {
                int idx = it->second;
                if (dp[i].odd = dp[idx].even) ++ret;
            }
            
            it = val_idx_dec.lower_bound(val);
            if (it != val_idx_dec.end()) {
                int idx = it->second;
                dp[i].even = dp[idx].odd;
            }
            
            val_idx_inc[val] = i;
            val_idx_dec[val] = i;
        }
        return ret;
    }
};
