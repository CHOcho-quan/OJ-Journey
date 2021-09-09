class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<int> result;
        vector<vector<int>> graph(numCourses, vector<int>());
        
        for (auto& pre : prerequisites) {
            ++indegree[pre[0]];
            graph[pre[1]].push_back(pre[0]);
        }
        
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) if (!indegree[i]) q.push(i);
        while (!q.empty()) {
            int len = q.size();
            while (len--) {
                auto cur = q.front();
                q.pop();
                result.push_back(cur);
                for (auto& n : graph[cur]) {
                    --indegree[n];
                    if (!indegree[n]) {
                        q.push(n);
                    }
                }
            }
        }
        for (auto& t : indegree) if (t != 0) return {};
        return result;
    }
};
