class Solution {
public:
    vector<vector<int>> result;
    set<vector<int>> check;
    
    void backtrace(vector<int>& candidates,
                   vector<int>& tmp,
                   int n, int first, int target) {
        if (n == first || target <= 0) {
            if (target == 0) {
                auto temp = tmp;
                // for (auto& t : tmp) std::cout << t << ' ';
                // std::cout << "================GOT\n";
                sort(temp.begin(), temp.end());
                check.insert(temp);
            }
            return;
        }
        
        set<int> reap;
        for (int i = first; i < n; ++i) {
            // for (auto& t : tmp) std::cout << t << ' ';
            // std::cout << "================\n";
            // std::cout << candidates[i] << ' ' << target << ' ' << first << '\n';
            int rem = candidates[i];
            tmp.push_back(rem);
            if (!reap.count(rem))
                backtrace(candidates, tmp, n, i + 1, target - rem);
            reap.insert(rem);
            tmp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> tmp;
        backtrace(candidates, tmp, candidates.size(), 0, target);
        result.assign(check.begin(), check.end());
        return result;
    }
};
