class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int N = flights.size();
        int K =days[0].size();
        
        vector<vector<int>> dp(K, vector<int>(N, 0));
        
        for (int i = 0; i < N; ++i) {
            dp[K-1][i] = days[i][K-1];
        }
        
        for (int week = K-2; week >= 0; --week) {
            for (int city = 0; city < N; ++city) {
                int best = dp[week+1][city];
                for (int next = 0; next < N; ++next) if (flights[city][next]) {
                    best = max(best, dp[week+1][next]);
                }
                dp[week][city] = best + days[city][week];
            }
        }
        
        int ret = dp[0][0];
        for (int i = 1; i < N; ++i) if (flights[0][i]) ret = max(ret, dp[0][i]);
        return ret;
    }
};
