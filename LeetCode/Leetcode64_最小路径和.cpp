class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<int> dp(grid[0].size(), 0);
        dp[0] = grid[0][0];
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (i > 0 && j > 0) {
                    dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
                } else if (i > 0) {
                    dp[j] = dp[j] + grid[i][j];
                } else if (j > 0) {
                    dp[j] = dp[j - 1] + grid[i][j];
                } else continue;
            }
            
            // for (auto& c : dp) std::cout << c << ' ';
            // std::cout << '\n';
        }
        
        return dp[grid[0].size() - 1];
    }
    
    int minPathSum1(vector<vector<int>>& grid) {
        int l1 = grid.size(), l2 = grid[0].size();
        vector<vector<int>> dp(l1, vector<int>(l2, 0));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < l1; ++i) dp[i][0] = dp[i - 1][0] + grid[i][0];
        for (int i = 1; i < l2; ++i) dp[0][i] = dp[0][i - 1] + grid[0][i];
        
        for (int i = 1; i < l1; ++i) {
            for (int j = 1; j < l2; ++j) {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        
        return dp[l1 - 1][l2 - 1];
    }
};
