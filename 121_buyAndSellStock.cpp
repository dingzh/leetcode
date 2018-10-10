class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        
        int min_price = (1<<31) - 1; //max int
        int best_profit = 0;
        for (int i = 0; i < size; ++i) {
            min_price = min( min_price, prices[i] );
            best_profit = max( best_profit, prices[i] - min_price );
        }

        return best_profit;
    }
};
