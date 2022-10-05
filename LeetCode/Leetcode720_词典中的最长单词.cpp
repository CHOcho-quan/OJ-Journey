class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_map<int, unordered_map<string, vector<string>>> l2c2s;
        for (auto& word : words) {
            if (word.length() == 1) l2c2s[word.length()][""].push_back(word);
            else l2c2s[word.length()][word.substr(0, word.length() - 1)].push_back(word);
        }

        string res = "";
        queue<string> q;
        for (auto& char2word : l2c2s[1]) {
            for (auto& w : char2word.second) {
                q.push(w);
            }
        }

        while (!q.empty()) {
            auto cur = q.front();
            // cout << cur << '\n';
            if (cur.length() > res.length()) res = cur;
            else if (cur.length() == res.length()) res = res > cur ? cur : res;
            q.pop();


            for (string& word : l2c2s[cur.length() + 1][cur]) {
                q.push(word);
            }
        }

        return res;
    }
};