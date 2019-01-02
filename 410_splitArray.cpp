class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<int>> dp(m, vector<int>(n, numeric_limits<int>::max()));
        vector<int> prefix_sum;

        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            prefix_sum.push_back(sum);
            dp[0][i] = sum;
        }

        for (int i = 1; i < m; ++i) {
            for (int j = i; j < n; ++j ) {
                int& val = dp[i][j];
                for ( int k = j - 1; k >= i-1; --k) {
                    int lt = dp[i-1][k];
                    int rt = prefix_sum[j] - prefix_sum[k];
                    if (rt >= val) break;
                    val = max(lt, rt);
                }
            }
        }

        return dp.back().back();
    }
};
