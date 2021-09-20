class Solution {
public:
    vector<int> direction = {-1, 0, 1, 0, -1};
    vector<int> direction2 = {-1, -1, 1, 1, -1};
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        q.push({0, 0});
        visited[0][0] = true;
        int result = 0;
        bool flag = false;
        while (!q.empty()) {
            int len = q.size();
            ++result;
            while (len--) {
                auto [x, y] = q.front();
                if (x == n - 1 && y == n - 1) {
                    flag = true;
                    break;
                }
                q.pop();
                if (grid[x][y]) continue;
                // cout << x << ' ' << y << '\n';
                for (int i = 0; i < 4; ++i) {
                    int nx = x + direction[i], ny = y + direction[i + 1];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                    if (visited[nx][ny]) continue;
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
                for (int i = 0; i < 4; ++i) {
                    int nx = x + direction2[i], ny = y + direction2[i + 1];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                    if (visited[nx][ny]) continue;
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
            if (flag) break;
        }
        
        if (!flag) return -1;
        else if (grid[n - 1][n - 1]) return -1;
        return result;
    }
};
