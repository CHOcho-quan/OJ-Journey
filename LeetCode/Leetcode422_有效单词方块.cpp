class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        vector<string> colWords;
        for (int j = 0; j < words.size(); ++j) {
            string cur = "";
            for (int i = 0; i < words.size(); ++i) {
                if (j < words[i].length()) cur += words[i][j];
                else break;
            }
            colWords.push_back(cur);
        }
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] != colWords[i]) return false;
        }
        return true;
    }
};
