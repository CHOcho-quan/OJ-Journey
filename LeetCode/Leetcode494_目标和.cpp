class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        if (nums.size() == 1) return nums[0] == target || nums[0] == -target;
        int len = nums.size();
        vector<vector<int>> dp(len + 1, vector<int>(2001, 0));
        dp[0][1000] = 1;
        for (int i = 1; i <= len; ++i) {
            int n = nums[i - 1];
            for (int j = -1000; j <= 1000; ++j) {
                if (1000 + j - n >= 0)
                    dp[i][j + 1000] += dp[i - 1][1000 + j - n];
                if (1000 + j + n <= 2000)
                    dp[i][j + 1000] += dp[i - 1][1000 + j + n];
            }
        }
        
        return dp[len][target + 1000];
    }
};
