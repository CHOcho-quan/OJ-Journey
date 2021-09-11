class Solution {
public:
    vector<int> direction = {-1, 0, 1, 0, -1};
    
    int dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        for (int k = 0; k < 4; ++k) {
            int ni = i + direction[k], nj = j + direction[k + 1];
            if (ni >= grid.size() || nj >= grid[0].size() || ni < 0 || nj < 0) continue;
            if (visited[ni][nj] || grid[ni][nj] == '0') continue;
            visited[ni][nj] = true;
            dfs(ni, nj, grid, visited);
        }
        return 1;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int len1 = grid.size(), len2 = grid[0].size();
        int result = 0;
        vector<vector<bool>> visited(len1, vector<bool>(len2, false));
        
        for (int i = 0; i < len1; ++i) {
            for (int j = 0; j < len2; ++j) {
                if (visited[i][j]) continue;
                if (grid[i][j] == '0') {
                    visited[i][j] = true;
                    continue;
                }
                visited[i][j] = true;
                result += dfs(i, j, grid, visited);
            }
        }
        
        return result;
    }
};
