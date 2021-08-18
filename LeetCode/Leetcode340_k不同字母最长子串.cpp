class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k == 0) return 0;
        int st = 0, en = 0;
        std::unordered_set<char> distinct;
        std::unordered_map<char, int> check;
        
        for (; en < s.length(); ++en) {
            ++check[s[en]];
            distinct.insert(s[en]);
            if (distinct.size() == k) break;
        }
        // std::cout << en;
        if (en == s.length()) return en;
        int result = en - st + 1;
        ++en;
        for (; en < s.length(); ++en) {
            ++check[s[en]];
            distinct.insert(s[en]);
            // If NOT satisfy distinct condition
            while (distinct.size() != k && st < s.length()) {
                if (!(--check[s[st]])) distinct.erase(s[st]);
                ++st;
            }
            result = en - st + 1 > result ? en - st + 1 : result;
        }
        return result;
    }
};
