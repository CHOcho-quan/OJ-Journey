class Solution {
public:
    vector<int> direction = {-1, 0, 1, 0, -1};
    
    vector<vector<bool>> visited;
    
    void solve(vector<vector<char>>& board) {
        int len1 = board.size(), len2 = board[0].size();
        visited = vector<vector<bool>>(len1, vector<bool>(len2, false));
        
        queue<pair<int, int>> q;
        vector<int> re;
        for (int i = 0; i < len1; ++i) {
            for (int j = 0; j < len2; ++j) {
                if (visited[i][j]) continue;
                if (board[i][j] == 'O') {
                    vector<pair<int, int>> tmp;
                    q.push({i, j});
                    tmp.push_back({i, j});
                    visited[i][j] = true;
                    
                    bool flag = true;
                    while (!q.empty()) {
                        int len = q.size();
                        while (len--) {
                            auto [curi, curj] = q.front();
                            q.pop();
                            for (int k = 0; k < 4; ++k) {
                                auto ni = curi + direction[k], nj = curj + direction[k + 1];
                                if (ni < 0 || nj < 0 || ni >= len1 || nj >= len2) {
                                    flag = false;
                                    continue;
                                }
                                if (visited[ni][nj]) continue;
                                if (board[ni][nj] == 'X') continue;
                                q.push({ni, nj});
                                visited[ni][nj] = true;
                                tmp.push_back({ni, nj});
                            }
                        }
                    }
                    
                    if (flag) {
                        for (auto [i1, j1] : tmp) {
                            board[i1][j1] = 'X';
                        }
                    }
                }
            }
        }
    }
};
