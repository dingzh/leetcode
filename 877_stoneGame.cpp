class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int N = piles.size();
        
        // guaranteed not zero
        // if (!N) return false;
        
        vector<vector<int>> dp(N, vector<int>(N, 0));
        
        for(int i = 0; i < N; ++i) dp[i][i] = piles[i];
        for (int i = 0; i + 1 < N; ++i) dp[i][i+1] = max(piles[i], piles[i+1]);
        
        for (int step = 2; step < N; ++step)
            for (int i = 0; i + step < N; ++i) {
                int x = i, y = i + step;
                dp[x][y] = max( piles[x] + min( dp[x+2][y],   dp[x+1][y - 1] ),
                                piles[y] + min( dp[x+1][y-1], dp[x][y-2]   ) );
            }
        
        int sum = 0;
        accumulate(begin(piles), end(piles), sum);
        return dp[0][N-1] > sum / 2;
    }
};
