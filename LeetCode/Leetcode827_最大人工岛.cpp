class Solution {
public:
    vector<int> direction = {-1, 0, 1, 0, -1};
    
    int largestIsland(vector<vector<int>>& grid) {
        unordered_map<int, int> area;
        int res = 0;
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
        std::function<void(int, int, int, int&)> dfs = [&](int r, int c, int color, int& size) {
            grid[r][c] = color;
            ++size;
            for (int k = 0; k < 4; ++k) {
                int nr = r + direction[k], nc = c + direction[k + 1];
                if (nr < 0 || nc < 0 || nr >= grid.size() || nc >= grid[0].size()) continue;
                if (vis[nr][nc] || !grid[nr][nc]) continue;
                vis[nr][nc] = true;
                dfs(nr, nc, color, size);
            }
        };
        
        int color = 1;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] && !vis[i][j]) {
                    int size = 0;
                    vis[i][j] = true;
                    dfs(i, j, color, size);
                    // cout << size << '\n';
                    area[color++] = size;
                    res = max(size, res);
                }
            }
        }
        
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (!grid[i][j]) {
                    int cur = 1;
                    unordered_set<int> counted;
                    for (int k = 0; k < 4; ++k) {
                        int ni = i + direction[k], nj = j + direction[k + 1];
                        if (ni < 0 || nj < 0 || ni >= grid.size() || nj >= grid[0].size()) continue;
                        if (grid[ni][nj] && !counted.count(grid[ni][nj])) {
                            counted.insert(grid[ni][nj]);
                            cur += area[grid[ni][nj]];
                        }
                    }
                    res = max(res, cur);
                }
            }
        }
        
        return res;
    }
};
