class Solution {
public:
    string reverseVowels(string s) {
        if (s.length() == 0) return s;
        int st = 0, en = s.length() - 1;
        std::unordered_set<char> check = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        while (st <= en) {
            while (st <= en && !check.count(s[st])) ++st;
            while (en >= st && !check.count(s[en])) --en;
            // std::cout << st << ' ' << en << '\n';
            if (st <= en) {
                auto tmp = s[st];
                s[st] = s[en];
                s[en] = tmp;
            }
            ++st;
            --en;
        }
        return s;
    }
};
