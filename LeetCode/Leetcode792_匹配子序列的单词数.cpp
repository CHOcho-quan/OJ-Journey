class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int res = 0;
        unordered_map<char, set<int>> c2i;
        for (int i = 0; i < s.length(); ++i) c2i[s[i]].insert(i);

        int record = -1;
        for (auto& word : words) {
            bool flag = true;
            for (auto& c : word) {
                auto iter = c2i[c].upper_bound(record);
                if (iter == c2i[c].end()) {
                    record = -1;
                    flag = false;
                    continue;
                } else {
                    record = *iter;
                }
            }
            if (flag) ++res;
            record = -1;
        }

        return res;
    }
};