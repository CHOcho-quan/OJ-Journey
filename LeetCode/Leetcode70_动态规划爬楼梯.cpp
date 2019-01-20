//
//  Leetcode70_动态规划爬楼梯.cpp
//  
//
//  Created by 铨 on 2018/10/25.
//
//

#include<iostream>
#include <vector>

using namespace std;

int climbStairs(int n) {
    int *dp;
    dp = new int[n+1];
    dp[0] = 1;
    dp[1] = 1;
    if (n == 1) return 1;
    
    for (int i = 2;i < n+1;i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    return dp[n];
}

int main()
{
    int c = 3;
    cout << climbStairs(c);
}
