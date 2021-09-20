class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) return true;
        vector<int> dp(nums.size(), 0);
        dp[nums.size() - 1] = nums.size() - 1;
        for (int i = nums.size() - 2; i >= 0; --i) {
            dp[i] = nums[i] >= dp[i + 1] - i ? i : dp[i + 1];
        }
        return nums[0] >= dp[0];
    }
};
