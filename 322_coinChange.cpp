class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        constexpr int none = numeric_limits<int>::max();
        vector<int> dp(amount+1, none);
        dp[0] = 0;

        for ( int coin : coins ) {
            for (int i = coin; i <= amount; ++i) {
                if(dp[i-coin] != none) {
                    dp[i] = min( dp[i], dp[i-coin] + 1 );
                }
            }
        }

        return dp[amount] == none ? -1 : dp[amount];
    }
};
