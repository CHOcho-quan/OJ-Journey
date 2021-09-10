class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l = 0, r = 0, cur = 1, result = 1;
        cur *= nums[l];
        if (cur >= k) --result;
        while (r < nums.size() - 1) {
            cur *= nums[++r];
            while (l <= r && cur >= k) {
                cur /= nums[l++];
            }
            if (cur >= k) return result;
            result += (r - l + 1);
        }
        return result;
    }
};
