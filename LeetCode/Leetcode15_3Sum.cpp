class Solution {
public:
    vector<vector<int>> result;
    
    void backtrack(vector<int> nums, vector<int>& tmp, int sum, int first) {
        if (tmp.size() == 3) {
            if (!sum) result.push_back(tmp);
            return;
        }
        
        set<int> repeated;
        for (int i = first; i < nums.size(); ++i) {
            tmp.push_back(nums[i]);
            sum += nums[i];
            if (!repeated.count(nums[i]))
                backtrack(nums, tmp, sum, i + 1);
            repeated.insert(nums[i]);
            sum -= nums[i];
            tmp.pop_back();
        }
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) return result;
        std::sort(nums.begin(), nums.end());
        // for (auto& n : nums) cout << n << ' ';
        // vector<int> tmp;
        // backtrack(nums, tmp, 0, 0);
        
        unordered_set<int> check;
        for (int i = 0; i < nums.size(); ++i) {
            if (check.count(nums[i])) continue;
            check.insert(nums[i]);
            int target = -nums[i], l = i + 1, r = nums.size() - 1;
            
            int rem = 2147483647;
            while (l < r) {
                if (nums[l] + nums[r] > target) {
                    --r;
                } else if (nums[l] + nums[r] < target) ++l;
                else {
                    if (nums[l] != rem) {
                        result.push_back({nums[i], nums[l], nums[r]});
                        rem = nums[l];
                    }
                    --r;
                    ++l;
                }
            }
        }
        
        return result;
    }
};
