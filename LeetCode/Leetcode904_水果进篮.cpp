class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        if (fruits.size() == 1) return 1;
        
        unordered_set<int> check;
        int result = 1, rem = fruits[0], cnt = 0, fr = 0;
        check.insert(fruits[0]);
        for (int i = 1; i < fruits.size(); ++i) {
            if (check.count(fruits[i]) || check.size() <= 1) {
                ++result;
                check.insert(fruits[i]);
                if (check.size() == 2 && fruits[i] == rem) ++cnt;
                if (check.size() == 2 && fruits[i] != rem) cnt = 1;
                rem = fruits[i];
                // std::cout << result << ' ' << check.size() << ' ' << cnt << '\n';
            } else {
                check.clear();
                check.insert(rem);
                fr = max(fr, result);
                result = cnt + 1;
                cnt = 1;
                rem = fruits[i];
                check.insert(fruits[i]);
                // std::cout << "=== " << rem << ' ' << result << ' ' << check.size() << '\n';
            }
        }
        fr = max(fr, result);
        
        return fr;
    }
    
    int totalFruit1(vector<int>& fruits) {
        if (fruits.size() == 1) return 1;
        int fs = fruits.size();
        vector<vector<int>> dp(fs, vector<int>(fs, 0));
        vector<unordered_set<int>> cnt(fs, unordered_set<int>());
        
        for (int i = 0; i < fs; ++i) {
            dp[i][i] = 1;
            cnt[i].insert(fruits[i]);
        }
        int result = 0;
        for (int i = 0; i < fs; ++i) {
            for (int j = i + 1; j < fs; ++j) {
                if (cnt[i].count(fruits[j])) {
                    dp[i][j] = dp[i][j - 1] + 1;
                    result = max(result, dp[i][j]);
                } else if (cnt[i].size() <= 1) {
                    cnt[i].insert(fruits[j]);
                    dp[i][j] = dp[i][j - 1] + 1;
                    result = max(result, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                    break;
                }
            }
        }
        
        // for (int i = 0; i < fruits.size(); ++i) {
        //     for (int j = i + 1; j < fruits.size(); ++j) {
        //         std::cout << i << ' ' << j << ' ' << dp[i][j] << '\n';
        //     }
        // }
        
        return result;
    }
};
