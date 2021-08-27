class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size(), cnt = 0;
        vector<vector<int>>
        dp(m + 1, vector<int>(n + 1, 0));
        vector<int> ones(len, 0), zeros(len, 0);
        for (auto& str : strs) {
            int one = 0, zero = 0;
            for (auto& c : str) {
                if (c == '0') ++zero;
                else ++one;
            }
            ones[cnt] = one;
            zeros[cnt++] = zero;
        }
        
        for (int i = 1; i < len + 1; ++i) {
            int z = zeros[i - 1], o = ones[i - 1];
            // std::cout << i << "th: " << z << " zeros, " << o << " ones\n";
            // dp[i][j][k] = max(dp[i][j - zeros[i]][k - ones[i]])
            for (int j = m; j >= 0; --j) {
                for (int k = n; k >= 0; --k) {
                    // std::cout << "=== " << i - 1 << ' ' << j - z << ' ' << k - o << '\n';
                    if (k >= o && j >= z) {
                        dp[j][k] = max(dp[j - z][k - o] + 1, dp[j][k]);
                    }
                }
            }
        }
        
        int max = 0;
        return dp[m][n];
    }
};
