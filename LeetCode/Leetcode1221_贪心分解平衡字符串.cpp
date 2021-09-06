class Solution {
public:
    int balancedStringSplit(string s) {
        int re = 0;
        unordered_map<char, int> check;
        
        for (int i = 0; i < s.length(); ++i) {
            ++check[s[i]];
            if (check['L'] == check['R'] && check['L'] != 0) {
                ++re;
                check['L'] = 0;
                check['R'] = 0;
            }
        }
        
        return re;
    }
};
