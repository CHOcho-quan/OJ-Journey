class Solution {
public:
    vector<vector<int>> result;
    
    void backtrack(vector<int>& cand, vector<int>& tmp, int first, int target) {
        if (target <= 0) {
            if (target == 0) {
                // vector<int> temp = tmp;
                // sort(temp.begin(), temp.end());
                result.push_back(tmp);
            }
            return;
        }
        
        for (first; first < cand.size(); ++first) {
            int i = first;
            if (target < cand[i]) break;
            tmp.push_back(cand[i]);
            backtrack(cand, tmp, first, target - cand[i]);
            tmp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> tmp;
        backtrack(candidates, tmp, 0, target);
        // vector<vector<int>> re(result.begin(), result.end());
        return result;
    }
};
