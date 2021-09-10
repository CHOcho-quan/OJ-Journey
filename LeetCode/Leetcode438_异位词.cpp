class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int l = 0, r = p.length() - 1, cnt = 0;
        vector<int> result;
        unordered_map<char, int> check;
        for (auto& pi : p) ++check[pi];
        
        for (int i = l; i <= r; ++i) {
            if (check.count(s[i])) {
                if (check[s[i]] > 0) ++cnt;
                --check[s[i]];
            }
        }
        
        while (r < s.length() - 1) {
            if (cnt == p.length()) result.push_back(l);
            if (check.count(s[l])) {
                if (check[s[l]] >= 0) --cnt;
                ++check[s[l]];
            }
            ++l;
            ++r;
            if (check.count(s[r])) {
                if (check[s[r]] > 0) ++cnt;
                --check[s[r]];
            }
        }
        if (cnt == p.length()) result.push_back(l);
        return result;
    }
};
