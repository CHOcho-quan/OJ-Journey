class Solution {
public:
    unordered_map<string, unordered_set<string>> nxt;
    
    int ladderLength(string beginWord, string endWord, unordered_set<string>& dict) {
        unordered_map<string, bool> visited, visitedl;
        dict.insert(beginWord);
        if (!dict.count(endWord)) return 0;
        queue<string> q, ql;
        q.push(beginWord);
        ql.push(endWord);
        visited[beginWord] = true;
        visitedl[endWord] = true;
        int res = 1, max_cnt = dict.size() + 1;
        while (max_cnt--) {
            bool flag = false;
            unordered_set<string> cur_vis;
            if (q.size() < ql.size()) {
                int len = q.size();
                while (len--) {
                    auto cur = q.front(); q.pop();
                    if (visitedl.count(cur)) flag = true;
                    for (int i = 0; i < cur.length(); ++i) {
                        for (int j = 0; j < 26; ++j) {
                            string sw = "";
                            if ('a' + j == cur[i]) continue;
                            auto tmp = cur;
                            sw += ('a' + j);
                            tmp.replace(i, 1, sw);
                            if (visited[tmp]) continue;
                            if (dict.count(tmp)) {
                                // cout << "A" << cur << ' ' << tmp << '\n';
                                nxt[cur].insert(tmp);
                                cur_vis.insert(tmp);
                                q.push(tmp);
                            }
                        }
                    }
                }
                for (auto& s : cur_vis) visited[s] = true;
            } else {
                int len = ql.size();
                while (len--) {
                    auto cur = ql.front(); ql.pop();
                    if (visited.count(cur)) flag = true;
                    for (int i = 0; i < cur.length(); ++i) {
                        for (int j = 0; j < 26; ++j) {
                            string sw = "";
                            if ('a' + j == cur[i]) continue;
                            auto tmp = cur;
                            sw += ('a' + j);
                            tmp.replace(i, 1, sw);
                            if (visitedl[tmp]) continue;
                            if (dict.count(tmp)) {
                                // cout << tmp << ' ' << cur << '\n';
                                nxt[tmp].insert(cur);
                                cur_vis.insert(tmp);
                                ql.push(tmp);
                            }
                        }
                    }
                }
                for (auto& s : cur_vis) visitedl[s] = true;
            }
            if (flag) return res;
            ++res;
        }
        
        return 0;
    }
    
    void backtrack(vector<vector<string>>& res, vector<string>& tmp, string& cur, string& end,
                   unordered_set<string>& wordList, unordered_set<string>& visited, int l) {
        if (tmp.size() > l) return;
        if (tmp.size() == l && cur == end) {
            res.push_back(tmp);
            return;
        }
        for (auto s : nxt[cur]) {
            tmp.push_back(s);
            backtrack(res, tmp, s, end, wordList, visited, l);
            tmp.pop_back();
        }
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict;
        for (auto& w : wordList) dict.insert(w);
        int l = ladderLength(beginWord, endWord, dict);
        cout << l << '\n';
        vector<vector<string>> res;
        if (!l) return res;
        vector<string> tmp = {beginWord};
        unordered_set<string> visited = {beginWord};
        backtrack(res, tmp, beginWord, endWord, dict, visited, l);
        return res;
    }
};
