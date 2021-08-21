class Solution {
public:
    void dfs(vector<vector<int>>& grid,
             vector<vector<bool>>& visited,
             int ind1,
             int ind2,
             int* result) {
        if (ind1 < 0 || ind1 >= grid.size()) return;
        if (ind2 < 0 || ind2 >= grid[0].size()) return;
        if (visited[ind1][ind2]) return;
        // std::cout << ind1 << ' ' << ind2 << '\n';
        visited[ind1][ind2] = true;
        if (grid[ind1][ind2]) ++(*result);
        else return;
        
        dfs(grid, visited, ind1 - 1, ind2, result);
        dfs(grid, visited, ind1 + 1, ind2, result);
        dfs(grid, visited, ind1, ind2 - 1, result);
        dfs(grid, visited, ind1, ind2 + 1, result);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        
        int result = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (visited[i][j] || !grid[i][j]) {
                    visited[i][j] = true;
                    continue;
                }
                int tmp = 0;
                dfs(grid, visited, i, j, &tmp);
                result = std::max(result, tmp);
            }
        }
        
        return result;
    }
};
