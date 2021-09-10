class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0, cur = nums[0], result = 2147483647;
        
        while (r < nums.size()) {
            while (l <= r && cur >= target) {
                result = min(result, r - l + 1);
                if (result == 1) return result;
                cur -= nums[l++];
                if (cur >= target) result = min(result, r - l + 1);
            }
            if (r == nums.size() - 1) break;
            cur += nums[++r];
        }
        return result == 2147483647 ? 0 : result;
    }
};
