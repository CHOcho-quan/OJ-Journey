class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adjGraph(numCourses, vector<int>());
        for (auto& prereq : prerequisites) {
            int pre = prereq[1], nxt = prereq[0];
            ++indegree[nxt];
            adjGraph[pre].push_back(nxt);
        }
        
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (!indegree[i]) q.push(i);
        }
        
        while (!q.empty()) {
            int len = q.size();
            while (len--) {
                auto cur = q.front();q.pop();
                for (auto& nxt : adjGraph[cur]) {
                    if (--indegree[nxt] == 0) {
                        q.push(nxt);
                    }
                }
            }
        }
        
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i]) return false;
        }
        return true;
    }
};
