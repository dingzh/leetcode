class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if (size < 1) return 0;
        
        int minprice = prices[0];
        // sell on and before this date
        vector<int> sellprofit(size, 0);
        for (int i = 1; i < size; ++i) {
            sellprofit[i] = max(sellprofit[i-1], prices[i] - minprice);
            minprice = min(minprice, prices[i]);
        }
        
        // initialize max profit to buy and sell for only one time
        int maxprofit = sellprofit.back(), maxprice = prices.back();
        for (int i = size-1; i > 0; --i) {
            int buyprofit = maxprice - prices[i];
            maxprice = max(maxprice, prices[i]);
            maxprofit = max(maxprofit, sellprofit[i-1] + buyprofit);
        } // buy on day zero is already accounted
        
        return maxprofit;
    }
};
