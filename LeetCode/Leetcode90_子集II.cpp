class Solution {
public:
    void backtrack(int first, vector<vector<int>>& result,
                   vector<int>& tmp, vector<int>& nums) {
        if (first == nums.size()) {
            result.push_back(tmp);
            return;
        }
        
        result.push_back(tmp);
        
        unordered_set<int> check;
        for (int i = first; i < nums.size(); ++i) {
            if (check.count(nums[i])) continue;
            check.insert(nums[i]);
            tmp.push_back(nums[i]);
            backtrack(i + 1, result, tmp, nums);
            tmp.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> tmp;
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        backtrack(0, result, tmp, nums);
        return result;
    }
};
