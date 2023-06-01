class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int f = 0, s = 0;
        for (int i = nums.size() - 1; i >= 1; --i) {
            if (nums[i-1] < nums[i]) {
                f = i;
                s = i - 1;
                break;
            }
        }
        if (f == 0 && s == 0) sort(nums.begin(), nums.end());
        else {
            for (int i = nums.size() - 1; i >= f; --i) {
                if (nums[i] > nums[s]) {
                    swap(nums[i], nums[s]);
                    break;
                }
            }
            sort(nums.begin() + f, nums.end());
        }
    }
};