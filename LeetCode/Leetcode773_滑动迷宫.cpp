class Solution {
public:
    using PII = pair<int, int>;
    
    map<vector<vector<int>>, int> toex;
    int result = 1000;
    vector<vector<int>> expect = {{1,2,3}, {4,5,0}};
    vector<int> direction = {-1, 0, 1, 0, -1};
    
    void dfs(PII zero, int tmp, vector<vector<int>>& cur, vector<vector<int>>& board) {
        if (board == cur) {
            // for (auto& c : cur) for (auto& ci : c) cout << ci << ' ';
            // cout << "========\n";
            result = min(tmp, result);
            return ;
        }
        int curstep = 1000;
        if (toex.count(cur)) {
            curstep = toex[cur];
        }
        auto [x, y] = zero;
        // cout << x << ' ' << y << '\n';
        if (!toex.count(cur) || curstep > tmp) {
            toex[cur] = tmp;
            for (int i = 0; i < 4; ++i) {
                int nx = x + direction[i], ny = y + direction[i + 1];
                if (nx < 0 || ny < 0 || nx >= 2 || ny >= 3) continue;
                swap(cur[nx][ny], cur[x][y]);
                dfs({nx, ny}, tmp + 1, cur, board);
                swap(cur[nx][ny], cur[x][y]);
            }
        }
    }
    
    int slidingPuzzle(vector<vector<int>>& board) {
        PII curz = {1, 2};
        // for (int i = 0; i < 2; ++i) {
        //     bool found = false;
        //     for (int j = 0; j < 3; ++j) {
        //         if (board[i][j] == 0) {
        //             found = true;
        //             curz = {i, j};
        //             break;
        //         }
        //     }
        //     if (found) break;
        // }
        // cout << curz.first << ' ' << curz.second << '\n';
        vector<vector<int>> cur = {{1,2,3},{4,5,0}};
        dfs(curz, 0, cur, board);
        return result == 1000 ? -1 : result;
    }
};
