class Solution {
public:
    bool isPredecessor(const string& w1, const string& w2) {
        // Judge if w1 is predecessor of w2
        for (int i = 0; i < w2.length(); ++i) {
            if (w2.substr(0, i) + w2.substr(i + 1, w2.length()) == w1) return true;
        }

        return false;
    }

    int dfs(vector<string>& words, int& res, int cur_sum, string cur) {
        if (mems.find(cur) != mems.end()) {
            res = max(res, mems[cur] + cur_sum);
            return mems[cur];
        }
        res = max(res, mems[cur] + cur_sum);
        if (l2w.find(cur.length() + 1) == l2w.end()) {
            mems[cur] = 0;
            return 0;
        }

        for (auto& word : l2w[cur.length() + 1]) {
            cur_sum += 1;
            if (isPredecessor(cur, word))
                mems[cur] = max(mems[cur], dfs(words, res, cur_sum, word) + 1);
            cur_sum -= 1;
        }

        return mems[cur];
    }

    int longestStrChain(vector<string>& words) {
        int res = 1;
        for (auto& word : words) l2w[word.length()].push_back(word);
        for (auto& word : words) dfs(words, res, 1, word);
        return res;
    }

    unordered_map<string, int> mems;
    unordered_map<int, vector<string>> l2w;
};