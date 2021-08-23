class Solution {
public:
    bool backtrack(vector<vector<char>>& board, vector<vector<set<char>>>& rem, int i, int j) {
        if (j == 9) {
            i += 1;
            j = 0;
        }
        if (i == 9) {
            return true;
        }
        if (board[i][j] != '.') return backtrack(board, rem, i, j + 1);
        
        // std::cout << "Filling in " << i << ' ' << j << ' ';
        for (auto& num : rem[i][j]) {
            // std::cout << num << '\n';
            board[i][j] = num;
            vector<int> sec1, sec2;
            // rem operation
            for (int k = 0; k < 9; ++k) {
                if (board[i][k] == '.' && rem[i][k].count(num)) {
                    rem[i][k].erase(num);
                    sec1.push_back(i);
                    sec2.push_back(k);
                }
                if (board[k][j] == '.' && rem[k][j].count(num)) {
                    rem[k][j].erase(num);
                    sec1.push_back(k);
                    sec2.push_back(j);
                }
            }
            // Sub Box
            int c1 = i / 3, c2 = j / 3;
            for (int k1 = c1 * 3; k1 < c1 * 3 + 3; ++k1) {
                for (int k2 = c2 * 3; k2 < c2 * 3 + 3; ++k2) {
                    if (board[k1][k2] == '.' && rem[k1][k2].count(num)) {
                        rem[k1][k2].erase(num);
                        sec1.push_back(k1);
                        sec2.push_back(k2);
                    }
                }
            }
            if (backtrack(board, rem, i, j + 1)) return true;
            // rem back operation
            for (int t = 0; t < sec1.size(); ++t) {
                rem[sec1[t]][sec2[t]].insert(num);
            }
            board[i][j] = '.';
        }
        
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<set<char>>> rem(9, vector<set<char>>(9, set<char>({'1','2', '3', '4', '5', '6', '7', '8', '9'})));
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    // Col & Row
                    for (int k = 0; k < 9; ++k) {
                        if (board[i][k] != '.')
                            rem[i][j].erase(board[i][k]);
                        if (board[k][j] != '.')
                            rem[i][j].erase(board[k][j]);
                    }
                    // Sub Box
                    int c1 = i / 3, c2 = j / 3;
                    for (int k1 = c1 * 3; k1 < c1 * 3 + 3; ++k1) {
                        for (int k2 = c2 * 3; k2 < c2 * 3 + 3; ++k2) {
                            if (board[k1][k2] != '.')
                                rem[i][j].erase(board[k1][k2]);
                        }
                    }
                }
            }
        }
        
        // for (int i = 0; i < 9; ++i) {
        //     for (int j = 0; j < 9; ++j) {
        //         std::cout << i << ", " << j << ": ";
        //         for (auto& r3 : rem[i][j]) {
        //             std::cout << r3 << ' ';
        //         }
        //         std::cout << '\n';
        //     }
        // }
        
        backtrack(board, rem, 0, 0);
    }
};
