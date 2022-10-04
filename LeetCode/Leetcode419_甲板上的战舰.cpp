class Solution {
public:
    vector<int> dirs = {1, 0, -1, 0, 1};

    void dfs(int x, int y, vector<vector<char>>& board, vector<vector<bool>>& visited) {
        for (int i = 0; i < 4; ++i) {
            int nx = x + dirs[i], ny = dirs[i + 1] + y;
            if (nx < 0 || ny < 0 || nx >= board.size() || ny >= board[0].size()) continue;
            if (visited[nx][ny]) continue;
            visited[nx][ny] = true;
            if (board[nx][ny] == 'X') dfs(nx, ny, board, visited);
        }
    }

    int countBattleships(vector<vector<char>>& board) {
        int res = 0;
        auto visited = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == 'X' && !visited[i][j]) {
                    visited[i][j] = true;
                    ++res;
                    dfs(i, j, board, visited);
                }
            }
        }

        return res;
    }
};