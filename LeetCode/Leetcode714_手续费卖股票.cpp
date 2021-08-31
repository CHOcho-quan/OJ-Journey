class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<int> buy(prices.size(), -1000001), sell(prices.size(), 0);
        buy[0] = -prices[0] - fee;
        for (int i = 1; i < prices.size(); ++i) {
            buy[i] = max(buy[i - 1], sell[i - 1] - prices[i] - fee);
            sell[i] = max(buy[i] + prices[i], sell[i - 1]);
        }
        
        return sell[prices.size() - 1];
    }
};
