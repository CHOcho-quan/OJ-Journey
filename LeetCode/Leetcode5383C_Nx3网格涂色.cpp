//
//  Leetcode5383C_Nx3网格涂色.cpp
//  
//
//  Created by 铨 on 2020/4/12.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

/**
 * TLE : Using Backtrack
 */
vector<vector<int>> m;
int result;

bool compatible(int color, int i)
{
    // cout << "COLOR: " << color << endl;
    bool flag = true;
    if (i % 3 > 0) flag = flag && (m[i/3][i%3-1] != color);
    if (i % 3 < 2) {
        //        cout << (m[i/3][i%3+1] != color) << endl;
        flag = flag && (m[i/3][i%3+1] != color);
        //        cout << flag << endl;
    }
    if (i / 3 > 0) flag = flag && (m[i/3-1][i%3] != color);
    if (i / 3 < m.size() - 1) flag = flag && (m[i/3+1][i%3] != color);
    
    return flag;
}

bool solve(int n, int i)
{
    if (i == n * 3)
    {
        result++;
        result = result % (1000000000 + 7);
        return true;
    }
    for (int color = 0;color < 3;color++)
    {
        if (!compatible(color, i)) {
            // cout << m[0][0] << ' ' << m[0][1] << ' ' << m[0][2] << endl;
            continue;
        }
        m[i / 3][i % 3] = color;
        
        solve(n, i+1);
        m[i/3][i%3] = -1;
    }
    
    return false;
}

int numOfWays(int n) {
    result = 0;
    vector<int> colors = {0, 1, 2};
    m = vector<vector<int>>(n, vector<int>(3, -1));
    solve(n, 0);
    
    return result;
}

/**
 * DP (Math) : OK
 */
int numOfWays2(int n) {
    if (n == 1) return 12;
    if (n == 2) return 54;
    vector<int64_t> a{6, 30};
    vector<int64_t> b{6, 24};
    for (int i = 2; i < n; i++) {
        a.emplace_back((a[i - 1] * 3 + b[i - 1] * 2) % 1000000007);
        b.emplace_back((a[i - 1] * 2 + b[i - 1] * 2) % 1000000007);
    }
    return (a.back() + b.back()) % 1000000007;
}

