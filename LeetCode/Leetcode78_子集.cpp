class Solution {
public:
    vector<vector<int>> result;
    
    void backtrack(vector<int>& nums, vector<int>& tmp, int first) {
        for (int i = first; i < nums.size(); ++i) {
            tmp.push_back(nums[i]);
            result.push_back(tmp);
            backtrack(nums, tmp, i + 1);
            tmp.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> tmp;
        result.push_back(tmp);
        backtrack(nums, tmp, 0);
        return result;
    }
};
