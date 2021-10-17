class Solution {
public:
    /*
     dp[n] - there are t moves for 0 to get to n
     nums[i] covers i to i + nums[i]
     */
    
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int res = 0, cur = 0, board = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int step = nums[i];
            cur = max(cur, i + step);
            if (i == board) {
                board = min(cur, static_cast<int>(nums.size() - 1));
                ++res;
                if (board == nums.size() - 1) return res;
            }
        }
        
        return res;
    }
};
