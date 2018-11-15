class Solution {
    
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        return aux(1, n, dp);
    }
    
    int aux(int start, int end, vector<vector<int>>& dp) {
        if (start >= end) return 0;
        if (dp[start][end] != -1) return dp[start][end];
        
        int best_cost = numeric_limits<int>::max();
        for (int i = (start + end)/2; i <= end; ++i) {  // i is the one i pick
            int cost = i + max(aux(start, i-1, dp), aux(i + 1, end, dp));
            best_cost = min(best_cost, cost);
        }
        dp[start][end] = best_cost;
        return best_cost;
    }
};
