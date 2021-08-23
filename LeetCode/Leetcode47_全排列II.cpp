class Solution {
public:
    vector<vector<int>> result;
    
    void backtrack(vector<int>& nums, vector<int>& tmp, int n, int level) {
        if (n == level) {
            result.push_back(tmp);
            return;
        }
        
        set<int> repeated;
        for (int i = level; i < n; ++i) {
            // std::cout << level << ' ' << nums[i] << '\n';
            tmp.push_back(nums[i]);
            swap(nums[level], nums[i]);
            if (!repeated.count(nums[level]))
                backtrack(nums, tmp, n, level + 1);
            swap(nums[i], nums[level]);
            repeated.insert(nums[i]);
            tmp.pop_back();
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> tmp = {};
        backtrack(nums, tmp, nums.size(), 0);
        return result;
    }
};
