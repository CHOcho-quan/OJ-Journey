class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        for (int i = 1; i < s.length() + 1; ++i) {
            for (int j = 0; j < i; ++j) {
                // std::cout << s.substr(j, i - j) << ' ' << dict.count(s.substr(j, i - j)) << '\n';
                dp[i] = dp[i] || (dict.count(s.substr(j, i - j)) && dp[j]);
            }
            // for (auto d : dp) std::cout << d << ' ';
            // std::cout << '\n';
        }
        
        return dp[s.length()];
    }
};
