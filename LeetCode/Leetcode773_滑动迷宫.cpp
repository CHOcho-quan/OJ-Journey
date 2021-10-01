// BFS
class Solution {
public:
    vector<int> direction = {-1, 0, 1, 0, -1};
    
    int slidingPuzzle(vector<vector<int>>& board) {
        map<vector<vector<int>>, int> rem;
        vector<vector<int>> st = {{1,2,3}, {4,5,0}};
        queue<vector<vector<int>>> q;
        
        q.push(st);
        int cnt = 0;
        while (!q.empty()) {
            int len = q.size();
            while (len--) {
                auto cur = q.front(); q.pop();
                if (cur == board) return cnt;
                rem[cur] = cnt;
                int x = 0, y = 0;
                for (int i = 0; i < 2; ++i) {
                    bool found = false;
                    for (int j = 0; j < 3; ++j) {
                        if (cur[i][j] == 0) {
                            found = true;
                            x = i;
                            y = j;
                            break;
                        }
                    }
                    if (found) break;
                }
                
                for (int k = 0; k < 4; ++k) {
                    int nx = x + direction[k], ny = y + direction[k + 1];
                    if (nx < 0 || ny < 0 || nx >= 2 || ny >= 3) continue;
                    swap(cur[x][y], cur[nx][ny]);
                    if (rem.count(cur)) {
                        swap(cur[x][y], cur[nx][ny]);
                        continue;
                    } else {
                        q.push(cur);
                        swap(cur[x][y], cur[nx][ny]);
                    }
                }
            }
            ++cnt;
        }
        
        return -1;
    }
};

// DFS
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
