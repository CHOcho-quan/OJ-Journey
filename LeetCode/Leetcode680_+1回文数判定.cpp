class Solution {
public:
    bool validWithoutCheck(string s) {
        int st = 0, en = s.length() - 1;
        while (st <= en) {
            if (s[st] == s[en]) {
                ++st;
                --en;
            } else {
                return false;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int st = 0, en = s.length() - 1;
        while (st <= en) {
            if (s[st] == s[en]) {
                ++st;
                --en;
            } else {
                if (validWithoutCheck(s.substr(st+1, en-st)) ||
                    validWithoutCheck(s.substr(st, en-st))) return true;
                else return false;
            }
        }
        return true;
    }
};
