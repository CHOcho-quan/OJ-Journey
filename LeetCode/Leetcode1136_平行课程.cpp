class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        queue<int> q;
        vector<int> indegree(n, 0);
        vector<vector<int>> adjGraph(n, vector<int>());
        for (auto& relation : relations) {
            int prev = relation[0] - 1, next = relation[1] - 1;
            ++indegree[next];
            adjGraph[prev].push_back(next);
        }
        
        for (int i = 0; i < n; ++i) {
            if (!indegree[i]) q.push(i);
        }
        
        int res = 0;
        while (!q.empty()) {
            int len = q.size();
            while (len--) {
                auto cur = q.front(); q.pop();
                for (auto& node : adjGraph[cur]) {
                    if (--indegree[node] == 0) q.push(node);
                }
            }
            ++res;
        }
        
        for (int i = 0; i < n; ++i) {
            if (indegree[i] != 0) return -1;
        }
        return res;
    }
};
