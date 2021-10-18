class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        vector<vector<int>> boom(grid.size(), vector<int>(grid[0].size(), 0));
        int pre = 0;
        for (int i = 0; i < grid.size(); ++i) {
            pre = 0;
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 'E') ++pre;
                if (grid[i][j] == 'W') pre = 0;
                if (grid[i][j] == '0') {
                    boom[i][j] += pre;
                }
            }
        }
        
        for (int i = 0; i < grid.size(); ++i) {
            pre = 0;
            for (int j = grid[i].size() - 1; j >= 0; --j) {
                if (grid[i][j] == 'E') ++pre;
                if (grid[i][j] == 'W') pre = 0;
                if (grid[i][j] == '0') {
                    boom[i][j] += pre;
                }
            }
        }
        
        for (int j = 0; j < grid[0].size(); ++j) {
            pre = 0;
            for (int i = 0; i < grid.size(); ++i) {
                if (grid[i][j] == 'E') ++pre;
                if (grid[i][j] == 'W') pre = 0;
                if (grid[i][j] == '0') {
                    boom[i][j] += pre;
                }
            }
        }
        
        for (int j = 0; j < grid[0].size(); ++j) {
            pre = 0;
            for (int i = grid.size() - 1; i >= 0; --i) {
                if (grid[i][j] == 'E') ++pre;
                if (grid[i][j] == 'W') pre = 0;
                if (grid[i][j] == '0') {
                    boom[i][j] += pre;
                }
            }
        }
        
        int res = 0;
        for (auto& boom_col : boom) {
            for (auto& boom_num : boom_col) res = max(boom_num, res);
        }
        
        return res;
    }
    
    int maxKilledEnemies1(vector<vector<char>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == '0') {
                    int cur = 0;
                    // all the enemies in same column
                    for (int k = i; k < grid.size(); ++k) {
                        if (grid[k][j] == 'W') break;
                        if (grid[k][j] == 'E') ++cur;
                    }
                    for (int k = i; k >= 0; --k) {
                        if (grid[k][j] == 'W') break;
                        if (grid[k][j] == 'E') ++cur;
                    }
                    for (int k = j; k < grid[i].size(); ++k) {
                        if (grid[i][k] == 'W') break;
                        if (grid[i][k] == 'E') ++cur;
                    }
                    for (int k = j; k >= 0; --k) {
                        if (grid[i][k] == 'W') break;
                        if (grid[i][k] == 'E') ++cur;
                    }
                    res = max(cur, res);
                }
            }
        }
        
        return res;
    }
};
