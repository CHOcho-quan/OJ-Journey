#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

string longestPalindrome(string s) {
    //    cout << 23;
    bool dp[2000][2000];
    
    for (int i = 0;i < s.size();i++) dp[i][i] = true;
    
    for (int i = 0;i < s.size();i++)
    {
        if (i != s.size() - 1) {
            if (s[i] == s[i+1]) dp[i][i+1] = true;
            else dp[i][i+1] = false;
        }
    }
    
    for (int i = 2;i < s.size();i++)
    {
        for (int j = 0;j < s.size();j++)
        {
            if (j+i < s.size()) dp[j][j+i] = (dp[j+1][j+i-1] && (s[j] == s[j+i]));
        }
    }
    
    //    for (int i = 0;i < s.size();i++)
    //    {
    //        for (int j = 0;j < s.size();j++)
    //        {
    //            cout << dp[i][j] << ' ';
    //        }
    //        cout << endl;
    //    }
    
    int cnt = -1;
    string result;
    for (int i = 0;i < s.size();i++)
    {
        for (int j = 0;j < s.size();j++)
        {
            if (j >= i && dp[i][j])
            {
                if (j - i > cnt)
                {
                    cnt = j - i;
                    result = s.substr(i, j-i+1);
                    //                    cout << i << ' ' << j << ' ' << result << endl;
                }
            }
        }
    }
    
    return result;
}

int main() {
    string re = longestPalindrome("babad");
    cout << re;
}
