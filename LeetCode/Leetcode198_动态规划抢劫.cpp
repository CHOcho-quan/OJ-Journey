//
//  Leetcode198_动态规划抢劫.cpp
//  
//
//  Created by 铨 on 2018/10/25.
//
//

#include<iostream>
#include <vector>

using namespace std;

int rob(vector<int>& nums) {
    int *dp;
    dp = new int[nums.size() + 2];
    dp[0] = 0;
    dp[1] = 0;
    
    for (int i = 2;i < nums.size() + 2;i++) {
        dp[i] = max(dp[i-1], dp[i-2] + nums[i-2]);
    }
    
    return dp[nums.size() + 1];
}

int main()
{
    vector<int> c;
    c.push_back(2);
    c.push_back(7);
    c.push_back(9);
    c.push_back(3);
    c.push_back(1);
    cout << rob(c);
}
