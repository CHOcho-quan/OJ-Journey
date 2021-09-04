class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 1) return triangle[0][0];
        // vector<vector<int>> dp(triangle);
        int result = 2147483647;
        // for (int i = 1; i < triangle.size(); ++i) {
        //     for (int j = 0; j < triangle[i].size(); ++j) {
        //         if (j - 1 >= 0 && j < triangle[i - 1].size())
        //             dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
        //         else if (j < triangle[i - 1].size())
        //             dp[i][j] = dp[i - 1][j] + triangle[i][j];
        //         else if (j - 1 >= 0)
        //             dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
        //         if (i == triangle.size() - 1) result = min(result, dp[i][j]);
        //     }
        // }
        vector<int> dp(triangle.size(), 2147483647);
        dp[0] = triangle[0][0];
        for (int i = 1; i < triangle.size(); ++i) {
            for (int j = triangle[i].size() - 1; j >= 0; --j) {
                if (j == 0) dp[j] = dp[j] + triangle[i][j];
                else dp[j] = min(dp[j], dp[j - 1]) + triangle[i][j];
                if (i == triangle.size() - 1) result = min(result, dp[j]);
            }
        }
        
        return result;
    }
};
