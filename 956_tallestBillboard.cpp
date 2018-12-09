class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        constexpr int maxsum = 10'000;
        constexpr int int_min = numeric_limits<int>::min();
        
        vector<vector<int>> dp(n + 1, vector<int>(2 * maxsum + 1, int_min));
        dp[0][maxsum] = 0;
        for (int i = 0; i < n; ++i) {
            for (int l = -maxsum; l <= maxsum; ++l) {
                int idx = maxsum + l;
                int lt = idx - rods[i] >= 0 ? dp[i][idx - rods[i]] : int_min;
                int mid = dp[i][idx];
                int rt = idx + rods[i] <= 2 * maxsum ?  dp[i][idx + rods[i]] : int_min;
                dp[i+1][idx] = max(lt + rods[i], max(mid, rt));
            }
        }
        return dp[n][maxsum];
    }
};
