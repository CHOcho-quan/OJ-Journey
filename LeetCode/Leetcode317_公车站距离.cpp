class Solution {
public:
    vector<int> dirs = {1, 0, -1, 0, 1};

    void bfs(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& cur_dis, vector<vector<int>>& dis_res, vector<vector<bool>>& visited) {
        queue<pair<int, int>> q;
        q.push(pair<int, int>(x, y));
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            int cur_x = cur.first, cur_y = cur.second;
            for (int i = 0; i < 4; ++i) {
                int nx = cur_x + dirs[i], ny = cur_y + dirs[i + 1];
                if (nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size() || visited[nx][ny]) continue;
                if (grid[nx][ny] != 0) continue;
                visited[nx][ny] = true;
                cur_dis[nx][ny] = cur_dis[cur_x][cur_y] + 1;
                if (dis_res[nx][ny] != -1) dis_res[nx][ny] += cur_dis[nx][ny];
                else dis_res[nx][ny] = cur_dis[nx][ny];
                q.push(pair<int, int>(nx, ny));
            }
        }
    }

    int shortestDistance(vector<vector<int>>& grid) {
        auto dis = vector<vector<int>>(grid.size(), vector<int>(grid[0].size(), -1);

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    auto visited = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));
                    auto cur_dis = vector<vector<int>>(grid.size(), vector<int>(grid[0].size(), 0));
                    visited[i][j] = true;
                    bfs(i, j, grid, cur_dis, dis, visited);
                }
            }
        }

        int res = 2147483647;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 0) {
                    res = min(res, dis[i][j]);
                }
            }
        }

        return res;
    }
};