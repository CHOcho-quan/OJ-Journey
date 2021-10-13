class Solution {
public:
    vector<int> direction = {-1, 0, 1, 0, -1};
    
    int res = 0;
    
    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited) {
        if (!grid[i][j]) return;
        int cnt = 0;
        // cout << i << ' ' << j << '\n';
        for (int k = 0; k < 4; ++k) {
            int ni = i + direction[k], nj = j + direction[k + 1];
            if (ni < 0 || nj < 0 || ni >= grid.size() || nj >= grid[0].size()) continue;
            if (grid[ni][nj]) ++cnt;
            if (visited[ni][nj]) continue;
            visited[ni][nj] = true;
            dfs(grid, ni, nj, visited);
        }
        res += 4 - cnt;
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        auto visited = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j]) {
                    visited[i][j] = true;
                    dfs(grid, i, j, visited);
                    return res;
                }
            }
        }
        
        return -1;
    }
};
