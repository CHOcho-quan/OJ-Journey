class Solution {
public:
    vector<int> direction = {-1, 0, 1, 0, -1};
    
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        
        bool flag = false;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 2) {
                    q.push(pair<int, int>(i, j));
                    visited[i][j] = true;
                } else if (grid[i][j] == 1) flag = true;
            }
        }
        if (q.empty() && !flag) return 0;
        
        int result = -1;
        while (!q.empty()) {
            int len = q.size();
            while (len--) {
                auto [x, y] = q.front();
                q.pop();
                for (int i = 0; i < 4; ++i) {
                    int px = x + direction[i], py = y + direction[i + 1];
                    if (px < 0 || py < 0 ||
                        px >= grid.size() || py >= grid[0].size() ||
                        visited[px][py]) continue;
                    if (grid[px][py] == 1) {
                        visited[px][py] = true;
                        grid[px][py] = 2;
                        q.push(pair<int, int>(px, py));
                    }
                }
            }
            ++result;
        }
        
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        
        return result;
    }
};
