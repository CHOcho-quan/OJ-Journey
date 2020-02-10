#include <iostream>
#include <vector>

using namespace std;

int minFallingPathSum(vector<vector<int>>& arr) 
{
    if (arr.size()==0) return 0;

    int **dp;
    dp = new int*[arr.size()];
    for (int i = 0;i < arr.size();i++) dp[i] = new int[arr[i].size()];

    for (int i = 0;i < arr[0].size();i++) dp[0][i] = arr[0][i];
    for (int i = 1;i < arr.size();i++)
    {
        for (int j = 0;j < arr[i].size();j++)
        {
            int minimum = 2147483647;
            for (int k = 0;k < arr[i-1].size();k++)
            {
                if (k == j) continue;
                minimum = min(minimum, dp[i-1][k]);
            }
            //cout << minimum << endl;
            dp[i][j] = minimum + arr[i][j];
        }
    }

    for (int i = 0;i < arr.size();i++)
    {
        for (int j = 0;j < arr[i].size();j++)
        {
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }

    int result = 2147483647;
    for (int i = 0;i < arr[arr.size()-1].size();i++)
    {
        result = min(result, dp[arr.size()-1][i]);
    }
    return result;
}

int main()
{
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << minFallingPathSum(arr);
}