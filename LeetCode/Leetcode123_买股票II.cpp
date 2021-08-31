class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> buy(3, -1000001), sell(3, 0);
        
        for (int i = 0; i < prices.size(); ++i) {
            for (int j = 1; j <= 2; ++j) {
                buy[j] = max(sell[j - 1] - prices[i], buy[j]);
                sell[j] = max(sell[j], buy[j] + prices[i]);
            }
        }
        
        return sell[2];
    }
    
    int maxProfit1(vector<int>& prices) {
        vector<vector<int>> buy(prices.size(), vector<int>(3, -100001));
        vector<vector<int>> sell(prices.size(), vector<int>(3, 0));
        
        buy[0][1] = -prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            for (int j = 1; j < 3; ++j) {
                buy[i][j] = max(sell[i - 1][j - 1] - prices[i], buy[i - 1][j]);
                sell[i][j] = max(buy[i - 1][j] + prices[i], sell[i - 1][j]);
            }
        }
        //         for (auto& b : buy) {
        //             for (auto& bb : b) cout << bb << ' ';
        //             cout << '\n';
        //         }
        
        // cout << "============================\n";
        //         for (auto& b : sell) {
        //             for (auto& bb : b) cout << bb << ' ';
        //             cout << '\n';
        //         }
        
        return max(sell[prices.size() - 1][2], sell[prices.size() - 1][1]);
    }
};
