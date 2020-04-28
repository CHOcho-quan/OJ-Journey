#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    // int result;
    // vector<int> memo;
    // int times;
    bool isPalindrome(string s)
    {
        string t = s;
        reverse(t.begin(), t.end());
        if (s == t) return true;
        return false;
    }

    // int minCutPar(string s, int start) {
    //     if (start >= s.length()) {
    //         result = min(times-1, result);
    //         return 1;
    //     }

    //     // if (memo[start] != -1) return memo[start];

    //     for (int i = 1;i < s.length() + 1 - start;i++) {
    //         string tmp = s.substr(start, i);
            
    //         if (isPalindrome(tmp)) {
    //             cout << tmp << endl;
    //             times+=1;
    //             minCutPar(s, start + i);
    //             times-=1;
    //         } 
    //     }

    //     memo[start] = 0;
    //     return 0;
    // }

    // int minCut(string s) {
    //     result = 2147483647;
    //     times = 0;
    //     memo = vector<int>(s.length(), -1);
    //     minCutPar(s, 0);
    //     return result;
    // }

    int minCut(string s) {
        if (s.size() <= 1) return 0;
        int len = s.length();
        vector<int> dp = vector<int>(s.length(), 2147483646);
        dp[dp.size() - 1] = 0;

        vector<vector<bool>> checkPalindrome(len, vector<bool>(len, false));
        
        for(int right=0;right<len;right++){
            for(int left=0;left<=right;left++){
                if(s[left]==s[right] && (right-left<=2 || checkPalindrome[left+1][right-1])){ 
                    checkPalindrome[left][right]=true;
                }
            }
        }

        for (int i = dp.size() - 2;i >= 0;i--) {
            for (int j = dp.size() - 1;j >= i;j--) {
                if (j == dp.size() - 1)
                {
                    string tmp = s.substr(i, j-i+1);
                    if (checkPalindrome[i][j]) {dp[i] = 0;break;}
                    continue;
                }

                string tmp = s.substr(i, j-i+1);
                // cout << i << " " << j-i+1 << " " << tmp << endl;
                if (checkPalindrome[i][j])
                {
                    // cout << tmp << endl;
                    dp[i] = min(dp[j+1] + 1, dp[i]);
                }
            }
        }

        // for (int i = 0;i < dp.size();i++) cout << dp[i] << ' ';

        return dp[0];
    }
};