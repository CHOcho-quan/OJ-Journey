class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, result = 0;
        int mask = 0;
        unordered_set<char> check;
        while (r < s.length()) {
            // std::cout << "l: " << l << ", r: " << r << ' ';
            if (!check.count(s[r])) {
                // std::cout << "not cotain " << s[r] << '\n';
                check.insert(s[r++]);
            } else {
                // std::cout << s[r] << " already cotains and mask: " << '\n';
                result = max(result, r - l);
                while (check.count(s[r])) {
                    check.erase(s[l++]);
                }
            }
        }
        result = max(r - l, result);
        
        return result;
    }
};
