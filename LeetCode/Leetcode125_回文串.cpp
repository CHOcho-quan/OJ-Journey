class Solution {
public:
    bool isPalindrome(string s) {
        bool res = true;
        int st = 0, en = s.length() - 1;
        while (st < en) {
            while (st < s.length() && !((s[st] >= 'a' && s[st] <= 'z') || (s[st] >= 'A' && s[st] <= 'Z') || (s[st] >= '0' && s[st] <= '9'))) ++st;
            while (en >= 0 && !((s[en] >= 'a' && s[en] <= 'z') || (s[en] >= 'A' && s[en] <= 'Z') || (s[en] >= '0' && s[en] <= '9'))) --en;
            if (st >= en) break;
            // cout << tolower(s[st]) << ' ' << tolower(s[en]) << '\n';
            if (tolower(s[st]) != tolower(s[en])) {
                res = false;
                break;
            } else {
                ++st;
                --en;
            }
        }

        return res;
    }
};