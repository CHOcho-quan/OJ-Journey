#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <cmath>

using namespace std;

int minDistance(string word1, string word2) 
{
    vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1, 0));
    for (int i = 0;i < word1.length() + 1;i++) dp[i][0] = i;
    for (int i = 0;i < word2.length() + 1;i++) dp[0][i] = i;

    for (int i = 1;i < word1.length() + 1;i++)
    {
        for (int j = 1;j < word2.length() + 1;j++)
        {
            if (word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
            else {
                // Different method i.e. replace, delete, insert
                dp[i][j] = min(min(dp[i-1][j-1] + 1, 1 + dp[i-1][j]), 1 + dp[i][j-1]);
            }
        }
    }

    for (int i = 0;i < word1.length() + 1;i++)
    {
        for (int j = 0;j < word2.length() + 1;j++) cout << dp[i][j] << ' ';
        cout << endl;
    }

    return dp[word1.length()][word2.length()];
}

int main()
{
    string s = "horse", t = "ros";
    cout << minDistance(s, t);
}