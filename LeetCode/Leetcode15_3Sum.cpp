class Solution {
public:
    vector<vector<int>> result;
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) return result;
        std::sort(nums.begin(), nums.end());
        
        unordered_set<int> check;
        for (int i = 0; i < nums.size(); ++i) {
            if (check.count(nums[i])) continue;
            check.insert(nums[i]);
            int target = -nums[i];
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                if (nums[l] + nums[r] == target) {
                    vector<int> tmp = {nums[i], nums[l], nums[r]};
                    result.push_back(tmp);
                    auto recl = nums[l], recr = nums[r];
                    while (l < r && recl == nums[++l]);
                    while (l < r && recr == nums[--r]);
                } else if (nums[l] + nums[r] < target) ++l;
                else --r;
            }
        }
        
        return result;
    }
};
