class TicTacToe {
private:
    vector<vector<int>> vec_;
    int n_;

    int _checkplayer(int row, int col, int player) {
        // first check row win
        bool win = true;
        for (int i = 0; i < n_; ++i) {
            if (vec_[row][i] != player) {
                win = false;
                break;
            }
        }
        if (win) {return player;}
        // we'll check for column next
        win = true;
        for (int i = 0; i < n_; ++i) {
            if (vec_[i][col] != player) {
                win = false;
                break;
            }
        }
        if (win) {return player;}
        // check diagonals
        if (row == col) {
            win = true;
            for (int i = 0; i < n_; ++i) {
                if (vec_[i][i] != player) {
                    win = false;
                    break;
                }
            }
        }
        if (win) {return player;}
        if (row + col == n_ - 1) {
            win = true;
            for (int i = 0; i < n_; ++i) {
                if (vec_[i][n_ - i - 1] != player) {
                    win = false;
                    break;
                }
            }
        }
        if (win) return player;
        else return 0;
    }

public:
    TicTacToe(int n) : n_(n) {
        vec_ = vector<vector<int>>(n, vector<int>(n, -1));
    }
    
    int move(int row, int col, int player) {
        vec_[row][col] = player;
        return _checkplayer(row, col, player);
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */