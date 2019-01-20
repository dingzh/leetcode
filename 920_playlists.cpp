class Solution {
public:
    int numMusicPlaylists(int N, int L, int K) {
        vector<long> dp(N, 0);
        const int mod = 1'000'000'007;
        dp[0] = N;
        
        for (int len = 2; len <= L; ++len) {
            for (int kind = N - 1; kind >= 0; --kind) {
                dp[kind] *= max(0, kind + 1 - K);
                dp[kind] %= mod;
                if (kind > 0) {
                    dp[kind] += dp[kind-1] * (N - kind);
                    dp[kind] %= mod;
                }
            }
        }
        return dp.back();
    }
};
