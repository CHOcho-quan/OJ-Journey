class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        vector<int> vi(n, 0);
        vector<int> lrem;
        for (int i = 0; i < n; ++i) {
            auto si = s[i];
            if (si == '*') vi[i] = 3;
            if (si == '(') {
                lrem.push_back(i);
                vi[i] = 1;
            }
            if (si == ')') {
                if (!lrem.empty()) {
                    vi[lrem.back()] = 0;
                    lrem.pop_back();
                } else vi[i] = -1;
            }
        }
        int scnt = 0, lcnt = 0;
        for (int i = 0; i < n; ++i) {
            auto v = vi[i];
            // cout << v << "+=========\n";
            if (scnt < 0) return false;
            if (v == 0) continue;
            if (v == 1) ++lcnt;
            if (v == 3 && lcnt > 0) {
                --lcnt;
            } else if (v == 3) ++scnt;
            if (v == -1) {
                // cout << scnt;
                if (scnt <= 0) return false;
                else --scnt;
            }
            // cout << scnt << ' ' << lcnt << '\n';
        }
        return lcnt == 0;
    }
};
