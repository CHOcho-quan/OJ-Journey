class Solution {
public:
    int dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int i) {
        if (i < 0 || i >= isConnected.size() || visited[i]) return 0;
        visited[i] = true;
        for (int j = 0; j < isConnected[i].size(); ++j) {
            if (isConnected[i][j]) {
                dfs(isConnected, visited, j);
                visited[j] = true;
            }
        }
        return 1;
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        if (isConnected.size() == 0) return 0;
        
        int result = 0, size0 = isConnected.size(), size1 = isConnected[0].size();
        vector<bool> visited(size0, false);
        for (int i = 0; i < size0; ++i) {
            if (visited[i]) continue;
            // for (auto v : visited) std::cout << v << ' ';
            result += dfs(isConnected, visited, i);
        }
        
        return result;
    }
};
