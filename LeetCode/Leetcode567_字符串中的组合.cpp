class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.length() < s1.length()) return false;
        std::unordered_map<char, int> check;
        for (auto& s : s1) ++check[s];
        
        int l = 0, r = s1.length() - 1;
        for (int i = l; i <= r; ++i) {
            if (check.count(s2[i])) --check[s2[i]];
        }
        while (r < s2.length()) {
            bool flag = true;
            for (auto& c : check) {
                if (c.second != 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) return true;
            
            if (check.count(s2[l])) ++check[s2[l]];
            if (r < s2.length() && check.count(s2[++r])) --check[s2[r]];
            ++l;
        }
        
        return false;
    }
};
