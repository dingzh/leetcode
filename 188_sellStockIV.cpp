class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (k == 0 || prices.size() == 0) return 0;
        if (k * 2 >= prices.size()) {
            // unlimited
            int prev = numeric_limits<int>::max();
            int ret = 0;
            for (int price : prices) {
                if (price > prev) {
                    ret += price - prev;
                }
                prev = price;
            }
            return ret;
        }
        
        vector<int> buy(k, numeric_limits<int>::min());
        vector<int> sell(k, 0);

        for (int price : prices) {
            for (int i = k-1; i >= 0; --i) {
                sell[i] = max(sell[i], buy[i] + price);
                buy [i] = max(buy[i], (i ? sell[i-1] : 0) - price);
            }
        }
        return sell.back();
    }
};
