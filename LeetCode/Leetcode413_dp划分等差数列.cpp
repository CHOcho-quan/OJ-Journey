#include <iostream>
#include <vector>

using namespace std;

int numberOfArithmeticSlices(vector<int>& A) 
{
    int length = A.size();
    int **dp;
    dp = new int*[length];
    for (int i = 0;i < length;i++) dp[i] = new int[length];

    // Initialization
    for (int i = 0;i < length;i++) dp[i][i] = 0;
    for (int i = 0;i < length;i++) 
    {
        if (i!=length-1) dp[i][i+1] = A[i+1] - A[i];
    }

    for (int i = 0;i < length;i++) {
        for (int j = 0;j < length;j++) {
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }

    // From i to j, whether A[i, j] is equal-difference
    for (int i = 0;i < length;i++)
    {
        for (int j = i+2;j < length;j++)
        {
            // Equal Difference
            if (A[j] - A[j-1] == dp[i][j-1]) dp[i][j] = dp[i][j-1];
            else dp[i][j] = 2147483647;
        }
    }

    for (int i = 0;i < length;i++) {
        for (int j = 0;j < length;j++) {
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }

    int cnt = 0;
    for (int i = 0;i < length;i++)
    {
        for (int j = 0;j < length;j++)
        {
            if (dp[i][j] != 2147483647 && j - i >= 2) cnt++;
        }
    }
    cout << "ans: " << cnt << endl;
    return cnt;
}

int main()
{
    vector<int> inp = {1, 2, 3, 4};
    cout << numberOfArithmeticSlices(inp);
}