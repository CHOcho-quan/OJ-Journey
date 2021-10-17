class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict;
        unordered_map<string, bool> visited, visitedl;
        for (auto& w : wordList) dict.insert(w);
        dict.insert(beginWord);
        if (!dict.count(endWord)) return 0;
        queue<string> q, ql;
        q.push(beginWord);
        ql.push(endWord);
        visited[beginWord] = true;
        visitedl[endWord] = true;
        int res = 1, max_cnt = wordList.size() + 1;
        while (max_cnt--) {
            if (q.size() < ql.size()) {
                int len = q.size();
                while (len--) {
                    auto cur = q.front(); q.pop();
                    if (visitedl.count(cur)) return res;
                    for (int i = 0; i < cur.length(); ++i) {
                        for (int j = 0; j < 26; ++j) {
                            string sw = "";
                            if ('a' + j == cur[i]) continue;
                            auto tmp = cur;
                            sw += ('a' + j);
                            tmp.replace(i, 1, sw);
                            if (visited[tmp]) continue;
                            if (dict.count(tmp)) {
                                visited[tmp] = true;
                                q.push(tmp);
                            }
                        }
                    }
                }
            } else {
                int len = ql.size();
                while (len--) {
                    auto cur = ql.front(); ql.pop();
                    if (visited.count(cur)) return res;
                    for (int i = 0; i < cur.length(); ++i) {
                        for (int j = 0; j < 26; ++j) {
                            string sw = "";
                            if ('a' + j == cur[i]) continue;
                            auto tmp = cur;
                            sw += ('a' + j);
                            tmp.replace(i, 1, sw);
                            if (visitedl[tmp]) continue;
                            if (dict.count(tmp)) {
                                visitedl[tmp] = true;
                                ql.push(tmp);
                            }
                        }
                    }
                }
            }
            ++res;
        }
        
        return 0;
    }
};
