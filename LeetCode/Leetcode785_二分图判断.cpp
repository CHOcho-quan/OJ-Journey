class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int, int> c;
        vector<bool> visited(graph.size(), false);
        for (int i = 0; i < graph.size(); ++i) {
            if (visited[i]) continue;
            queue<int> q;
            q.push(i);
            c[i] = 1;
            visited[i] = true;
            while (!q.empty()) {
                int cur = q.front();
                // cout << "======== " << cur << "========\n";
                // for (auto ci : c) cout << ci.first << ' ' << ci.second << ' ';
                // cout << '\n';
                q.pop();
                for (auto& t : graph[cur]) {
                    if (visited[t] && c.count(t) && c[t] == c[cur]) return false;
                    if (visited[t]) continue;
                    else {
                        c[t] = 3 - c[cur];
                        q.push(t);
                        visited[t] = true;
                    }
                }
            }
        }
        
        return true;
    }
};
