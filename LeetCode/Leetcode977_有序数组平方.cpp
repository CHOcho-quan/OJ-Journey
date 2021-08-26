class Solution {
public:
    
    vector<int> sortedSquares(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        vector<int> ans;
        while (low <= high) {
            if (abs(nums[low]) > abs(nums[high])) {
                ans.insert(ans.begin(), nums[low] * nums[low]);
                ++low;
            }
            else {
                ans.insert(ans.begin(), nums[high] * nums[high]);
                --high;
            }
        }
        return ans;
    }
};
