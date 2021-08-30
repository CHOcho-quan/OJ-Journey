class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) return 0;
        
        int l = 0, r = 0, cnt = 0, re = 0;
        unordered_map<char, int> check;
        
        while (r < s.length()) {
            // if not repeated, ++r
            if (!check.count(s[r]) || check[s[r]] < 1) {
                ++cnt;
            }
            ++check[s[r]];
            re = max(re, cnt);
            // if repeated, ++l
            while (cnt != r - l + 1) {
                if (check[s[l]] == 1) --cnt;
                --check[s[l++]];
            }
            ++r;
        }
        re = max(re, cnt);
        return re;
    }
};
