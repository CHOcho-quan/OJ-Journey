class Solution {
public:
    bool backtrace(vector<vector<char>>& board, vector<vector<bool>>& visited, string& word, int i, int j) {
        int l = word.length();
        if (l == 0) {
            return true;
        }
        if (i < 0 || j < 0 || i >= board.size() || j >= board[i].size() || visited[i][j]) return false;
        
        if (word[l - 1] == board[i][j]) {
            auto tmp = word[l - 1];
            visited[i][j] = true;
            word.pop_back();
            if (backtrace(board, visited, word, i + 1, j) ||
                backtrace(board, visited, word, i - 1, j) ||
                backtrace(board, visited, word, i, j + 1) ||
                backtrace(board, visited, word, i, j - 1)) return true;
            word.push_back(tmp);
            visited[i][j] = false;
        }
        
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0) return false;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (backtrace(board, visited, word, i, j)) return true;
            }
        }
        return false;
    }
};
