class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) return false;
        sum /= 2;
        vector<bool> dp(sum + 1, false);
        dp[0] = true;
        for (int i = 1; i < nums.size() + 1; ++i) {
            auto n = nums[i - 1];
            for (int j = sum; j >= 0; --j) {
                if (j >= n) {
                    dp[j] = dp[j] || dp[j - n];
                }
            }
        }
        
        return dp[sum];
    }
};
