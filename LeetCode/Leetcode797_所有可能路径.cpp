class Solution {
public:
    void dfs(int i, int en,
             vector<int>& tmp,
             vector<bool>& visited,
             vector<vector<int>>& graph,
             vector<vector<int>>& result) {
        if (i == en) {
            tmp.push_back(en);
            // for (auto& t : tmp) cout << t << ' ';
            result.push_back(tmp);
            tmp.pop_back();
            return;
        }
        if (visited[i]) return;
        // cout << i << '\n';
        visited[i] = true;
        tmp.push_back(i);
        for (auto& n : graph[i]) {
            if (visited[n]) continue;
            // cout << n << ' ';
            dfs(n, en, tmp, visited, graph, result);
        }
        tmp.pop_back();
        visited[i] = false;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> result;
        vector<bool> visited(n, false);
        vector<int> tmp;
        dfs(0, n - 1, tmp, visited, graph, result);
        return result;
    }
};
