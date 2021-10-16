class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> adjGraph(n, vector<int>());
        for (auto& e : edges) {
            int prev = e[0] - 1, next = e[1] - 1;
            adjGraph[prev].push_back(next);
            adjGraph[next].push_back(prev);
        }
        
        queue<pair<int, double>> q;
        vector<bool> visited(n, false);
        q.push({0, 1.0});
        visited[0] = true;
        int stuck = 0;
        bool flag = false;
        double res = 0.0;
        ++t;
        while (t--) {
            int len = q.size();
            while (len--) {
                auto cur = q.front(); q.pop();
                auto [node, prob] = cur;
                // cout << node << ' ' << prob << '\n';
                int total = 0;
                for (auto& nxt : adjGraph[node]) {
                    if (visited[nxt]) continue;
                    ++total;
                }
                for (auto& nxt : adjGraph[node]) {
                    if (visited[nxt]) continue;
                    visited[nxt] = true;
                    q.push({nxt, prob * 1.0 / total});
                }
                if (node == target - 1) {
                    res = prob;
                    if (!t || total == 0) flag = true;
                }
            }
        }
        if (flag) return res;
        else return 0;
    }
};
