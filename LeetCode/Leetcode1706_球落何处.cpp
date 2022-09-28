class Solution {
public:
    int dfs(int col, vector<vector<int>>& grid) {
        int cur_row = 0;
        while (cur_row < grid.size()) {
            // cout << "=============" << cur_row << ' ' << col << "==============\n";
            if (grid[cur_row][col] == 1) {
                if (col == grid[0].size() - 1) return -1;
                switch (grid[cur_row][col + 1]) {
                    case -1: {
                        return -1;
                        break;
                    }
                    case 1: {
                        cur_row += 1;
                        col += 1;
                        if (col >= grid[0].size()) return -1;
                        break;
                    }
                }
            } else {
                if (col == 0) return -1;
                switch (grid[cur_row][col - 1]) {
                    case -1: {
                        cur_row += 1;
                        col -= 1;
                        if (col < 0) return -1;
                        break;
                    }
                    case 1: {
                        return -1;
                        break;
                    }
                }
            }
        }

        return col;
    }

    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> res;
        // cout << dfs(0, grid);
        for (int i = 0; i < grid[0].size(); ++i) {
            res.push_back(dfs(i, grid));
        }

        return res;
    }
};