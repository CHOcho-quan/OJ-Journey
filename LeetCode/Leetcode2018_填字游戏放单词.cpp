class Solution {
struct Pattern {
    vector<char> pattern;
};
public:
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        vector<Pattern> patterns;
        for (int i = 0; i < board.size(); ++i) {
            Pattern pat;
            int length = 0;
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == '#' && length) {
                    patterns.emplace_back(pat);
                    length = 0;
                    pat.pattern.clear();
                } else if (board[i][j] != '#')  {
                    ++length;
                    pat.pattern.emplace_back(board[i][j]);
                }
            }
            if (pat.pattern.size()) patterns.emplace_back(pat);
        }
        for (int j = 0; j < board[0].size(); ++j) {
            Pattern pat;
            for (int i = 0; i < board.size(); ++i) {
                if (board[i][j] == '#' && pat.pattern.size()) {
                    patterns.emplace_back(pat);
                    pat.pattern.clear();
                } else if (board[i][j] != '#')  {
                    pat.pattern.emplace_back(board[i][j]);
                }
            }
            if (pat.pattern.size()) patterns.emplace_back(pat);
        }

        for (auto& p : patterns) {
            for (auto & pp : p.pattern) cout << pp << '&';
            cout << '\n';
            if (p.pattern.size() == word.length()) {
                bool flag = true;
                for (int i = 0; i < word.length(); ++i) {
                    cout << "=============" << p.pattern[i] << '&' << word[i] << '\n';
                    if (word[i] != p.pattern[i] && p.pattern[i] != ' ') {
                        flag = false;
                        break;
                    }
                }
                if (flag) return true;
                flag = true;
                for (int i = 0; i < word.length(); ++i) {
                    cout << "=============" << p.pattern[i] << '&' << word[i] << '\n';
                    if (word[word.length() - i - 1] != p.pattern[i] && p.pattern[i] != ' ') {
                        flag = false;
                        break;
                    }
                }
                if (flag) return true;
            }
        }

        return false;
    }
};