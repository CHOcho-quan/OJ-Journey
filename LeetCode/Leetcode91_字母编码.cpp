class Solution {
public:
    bool strComp(const string& s1, const string& s2) {
        if (s1.length() > s2.length()) return true;
        else if (s1.length() < s2.length()) return false;
        return s1 > s2;
    }
    
    int numDecodings(string s) {
        vector<int> dp(s.length() + 1, 0);
        dp[0] = 1;
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '0') {
                if (i == 0) return 0;
                if (strComp(s.substr(i - 1, 2), "26") || s[i-1] == '0') return 0;
                dp[i+1] = dp[i - 1];
                continue;
            }
            dp[i+1] = dp[i];
            if (i > 0 &&
                !strComp(s.substr(i - 1, 2), "26") &&
                s[i-1] != '0') dp[i+1] += dp[i - 1];
            // for (auto& d : dp) std::cout << d << ' ';
            // std::cout << '\n';
        }
        
        return dp[s.length()];
    }
};
