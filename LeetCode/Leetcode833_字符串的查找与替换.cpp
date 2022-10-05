class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        vector<string> res;
        int cur_ind = 0;

        vector<pair<int, pair<string, string>>> v;
        for (int i = 0; i < indices.size(); ++i) {
            v.emplace_back(pair<int, pair<string, string>>(indices[i], pair<string, string>(sources[i], targets[i])));
        }
        sort(v.begin(), v.end());

        for (int i = 0; i < v.size(); ++i) {
            cout << v[i].first << ' ' << v[i].second.first << ' ' << v[i].second.second << '\n';
            int ind = v[i].first;
            string src = v[i].second.first, tgt = v[i].second.second;
            if (ind != cur_ind) {
                res.push_back(s.substr(cur_ind, ind - cur_ind));
                cur_ind = ind;
            }
            if (src == s.substr(ind, src.length())) {
                res.push_back(tgt);
                cur_ind = ind + src.length();
            }
        }
        if (cur_ind < s.length()) res.push_back(s.substr(cur_ind, s.length()));

        string r = "";
        for (auto& s : res) r += s;
        return r;
    }
};