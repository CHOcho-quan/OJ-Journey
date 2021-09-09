class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> indegree(n, 0);
        vector<bool> visited(n, false);
        vector<set<int>> adjGraph(n, set<int>());
        for (auto& e : edges) {
            if (!adjGraph[e[0]].count(e[1])) ++indegree[e[1]];
            adjGraph[e[0]].insert(e[1]);
        }
        if (adjGraph[destination].size()) return false;
        
        std::function<bool (int)> backtrace = [&] (int x)
        {
            if (adjGraph[x].size() == 0)       //是叶节点
                return x == destination;
            for (int y: adjGraph[x]) {
                if (visited[y] == true)     //之前已经visit了，有环
                    return false;
                visited[y] = true;          //借
                if (backtrace(y) == false)
                    return false;
                visited[y] = false;         //回溯。有借有还
            }
            return true;
        };
        
        visited[source] = true;             //从source出发
        return backtrace(source);
    }
};
