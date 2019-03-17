//
//  SJTU1349_DP跳房子.cpp
//  
//
//  Created by 铨 on 2019/3/11.
//
//

#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <stack>
#include <iomanip>
#include <cmath>
#include <queue>

using namespace std;

int main() {
    int r, c;
    char tmp;
    cin >> r >> c;
    int **t;
    int **dp;
    t = new int*[r];
    dp = new int*[r];
    for (int i = 0;i < r;i++)
    {
        t[i] = new int[c];
        dp[i] = new int[c];
    }
    
    for (int i = 0;i < r;i++)
    {
        for (int j = 0;j < c;j++)
        {
            dp[i][j] = 0;
            cin >> tmp;
            if (tmp == 'R') t[i][j] = 0;
            else t[i][j] = 1;
        }
    }
    
    dp[r-1][c-1] = 1;
    for (int i = r-1;i>=0;i--)
    {
        for (int j = c-1;j>=0;j--)
        {
            if (t[i][j] == 0)
            {
                for (int t1 = i+1;t1 < r;t1++)
                {
                    for (int t2 = j+1;t2 < c;t2++)
                    {
                        if (t[t1][t2] == 1) dp[i][j] += dp[t1][t2];
                    }
                }
            }
            else
            {
                for (int t1 = i+1;t1 < r;t1++)
                {
                    for (int t2 = j+1;t2 < c;t2++)
                    {
                        if (t[t1][t2] == 0) dp[i][j] += dp[t1][t2];
                    }
                }
            }
        }
    }
    
    cout << dp[0][0] << endl;
    //    for (int i = 0;i < r;i++)
    //    {
    //        for (int j = 0;j < c;j++)
    //        {
    //            cout << dp[i][j] << ' ';
    //        }
    //        cout <<endl;
    //    }
}


