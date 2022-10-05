class Solution {
public:
    void dfs(int e, unordered_map<int, vector<int>>& m2e, vector<int>& informTime, vector<int>& res, int cur) {
        if (m2e.find(e) == m2e.end()) {
            res.push_back(cur);
            return;
        }

        for (auto& ei : m2e[e]) {
            dfs(ei, m2e, informTime, res, cur + informTime[e]);
        }
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> m2e;
        vector<int> res;
        for (int i = 0; i < manager.size(); ++i) {
            m2e[manager[i]].push_back(i);
        }

        dfs(headID, m2e, informTime, res, 0);
        int result = -1;
        for (auto& r : res) result = max(r, result);
        return result;
    }
};