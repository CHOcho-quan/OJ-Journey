class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                if (nums[nums[i] - 1] < 0) res.push_back(nums[i]);
                nums[nums[i] - 1] *= -1;
            } else {
                if (nums[-1 - nums[i]] < 0) res.push_back(-nums[i]);
                nums[-1 - nums[i]] *= -1;
            }
        }

        return res;
    }
};