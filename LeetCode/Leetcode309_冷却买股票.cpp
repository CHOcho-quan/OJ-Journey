class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) {
            return 0;
        }
        vector<int> buy(n + 1), sell(n + 1, 0);
        
        buy[1] = -prices[0];
        for (int i = 2; i < prices.size() + 1; ++i) {
            buy[i] = max(buy[i - 1], sell[i - 2] - prices[i - 1]);
            sell[i] = max(sell[i - 1], buy[i] + prices[i - 1]);
            // std::cout << buy[i] << ' ' << sell[i] << '\n';
        }
        
        return sell[n];
    }
    
    int maxProfit1(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) {
            return 0;
        }
        vector<int> buy(n), sell(n), s1(n), s2(n);
        s1[0] = buy[0] = -prices[0];
        sell[0] = s2[0] = 0;
        for (int i = 1; i < n; i++) {
            buy[i] = s2[i-1] - prices[i];
            s1[i] = max(buy[i-1], s1[i-1]);
            sell[i] = max(buy[i-1], s1[i-1]) + prices[i];
            s2[i] = max(s2[i-1], sell[i-1]);
        }
        return max(sell[n-1], s2[n-1]);
    }
};
