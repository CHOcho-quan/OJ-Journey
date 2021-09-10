class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1 = "", t1 = "";
        for (auto& si : s) {
            if (si == '#') {
                if (s1.length() != 0) s1 = s1.substr(0, s1.length() - 1);
            } else s1 += si;
        }
        for (auto& ti : t) {
            if (ti == '#') {
                if (t1.length() != 0) t1 = t1.substr(0, t1.length() - 1);
            } else t1 += ti;
        }
        return s1 == t1;
    }
};
