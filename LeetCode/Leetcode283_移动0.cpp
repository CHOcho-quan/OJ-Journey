class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeros = 0, at = 0;
        for (auto& n : nums) if (!n) ++zeros;
        for (int i = 0; i < nums.size(); ++i) if (nums[i] != 0) nums[at++] = nums[i];
        for (; at < nums.size(); ++at) nums[at] = 0;
    }
};
