class Solution {
public:
    vector<int> direction = {-1, 0, 1, 0, -1};
    
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), result = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        using PII = pair<int, int>;
        queue<PII> q;
        set<vector<PII>> check;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (visited[i][j]) continue;
                if (grid[i][j]) {
                    vector<PII> tmp;
                    q.push({i, j});
                    tmp.push_back({0, 0});
                    visited[i][j] = true;
                    while (!q.empty()) {
                        int len = q.size();
                        while (len--) {
                            auto [x, y] = q.front();q.pop();
                            for (int k = 0; k < 4; ++k) {
                                int nx = x + direction[k], ny = y + direction[k + 1];
                                if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                                if (visited[nx][ny] || !grid[nx][ny]) continue;
                                q.push({nx, ny});
                                tmp.push_back({nx - i, ny - j});
                                visited[nx][ny] = true;
                            }
                        }
                    }
                    check.insert(tmp);
                }
            }
        }
        
        return check.size();
    }
};
