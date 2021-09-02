class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1, re = 0;
        while (l < r) {
            re += nums[r--] - nums[l++];
        }
        return re;
    }
};
