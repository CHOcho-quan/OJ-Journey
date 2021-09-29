class Solution {
public:
    int minSteps(string s, string t) {
        int l = s.length();
        unordered_map<char, int> check;
        for (auto& si : s) ++check[si];
        for (auto& ti : t) {
            if (check.count(ti) && check[ti] > 0) {
                --l;
                --check[ti];
            }
        }
        
        return l;
    }
};
