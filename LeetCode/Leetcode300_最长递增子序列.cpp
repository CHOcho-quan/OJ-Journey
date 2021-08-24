class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        dp[0]= 1;
        
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) dp[i] = max(dp[j] + 1, dp[i]);
            }
            // for (auto& d : dp) std::cout << d << ' ';
            // std::cout << '\n';
        }
        
        int result = 0;
        for (auto& d : dp) {
            result = max(d, result);
        }
        return result;
    }
};
