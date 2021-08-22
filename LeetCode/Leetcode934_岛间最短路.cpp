class Solution {
public:
    vector<int> dir = {-1, 0, 1, 0, -1};
    int shortestBridge(vector<vector<int>>& grid) {
        vector<vector<int>> island1;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        
        // Find first island
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j]) {
                    visited[i][j] = true;
                    vector<int> tmp = {i, j};
                    island1.push_back(tmp);
                    break;
                }
            }
            if (island1.size()) break;
        }
        queue<vector<int>> q;
        q.push(island1[0]);
        island1.pop_back();
        vector<vector<int>> bw;
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            if (!grid[cur[0]][cur[1]]) {
                bw.push_back(cur);
                continue;
            }
            else {
                island1.push_back(cur);
                // visited[cur[0]][cur[1]] = true;
            }
            
            for (int i = 0; i < 4; ++i) {
                int c1 = cur[0] + dir[i], c2 = cur[1] + dir[i + 1];
                if (c1 >= 0 && c1 < grid.size() && c2 >= 0 && c2 < grid[0].size()) {
                    if (!visited[c1][c2]) {
                        if (grid[c1][c2]) visited[c1][c2] = true;
                        vector<int> tmp = {c1, c2};
                        q.push(tmp);
                    }
                }
            }
        }
        
        for (auto& i : bw) {
            // std::cout << i[0] << ' ' << i[1] << '\n';
            q.push(i);
            visited[i[0]][i[1]] = true;
        }
        // std::cout << "=============\n";
        
        int result = 0, check = q.size(), cnt = 0;
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            ++cnt;
            // if (visited[cur[0]][cur[1]]) {
            //     if (cnt == check) {
            //         ++result;
            //         check = q.size();
            //         cnt = 0;
            //     }
            //     continue;
            // }
            // visited[cur[0]][cur[1]] = true;
            
            if (grid[cur[0]][cur[1]]) {
                break;
            }
            // std::cout << "=== " << cur[0] << ' ' << cur[1] << " === " << cnt << ' ' << check << ' ' << result << '\n';
            
            for (int i = 0; i < 4; ++i) {
                int c1 = cur[0] + dir[i], c2 = cur[1] + dir[i + 1];
                if (c1 >= 0 && c1 < grid.size() && c2 >= 0 && c2 < grid[0].size()) {
                    if (!visited[c1][c2]) {
                        vector<int> tmp = {c1, c2};
                        visited[c1][c2] = true;
                        q.push(tmp);
                    }
                }
            }
            
            if (cnt == check) {
                ++result;
                check = q.size();
                cnt = 0;
            }
        }
        
        return result;
    }
};
