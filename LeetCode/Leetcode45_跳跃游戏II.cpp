class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        vector<int> dp(n, 10001);
        dp[n - 1] = 0;
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 1; j <= nums[i]; ++j) {
                if (j + i >= n) break;
                dp[i] = min(dp[j + i] + 1, dp[i]);
            }
        }
        
        return dp[0];
    }
};
