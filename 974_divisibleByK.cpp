class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        vector<int> dp(K, 0);
        dp[0] = 1;
        int ret = 0, sum = 0;
        
        for (auto num : A) {
            sum += num;
            int mod = ((sum % K) + K ) % K;
            ret += dp[mod]++;
        }
        
        return ret;
    }
};
