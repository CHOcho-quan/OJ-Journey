//
//  Leetcode441_排列硬币.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

class Solution {
public:
    int arrangeCoins(int n) {
        int ans = 0,i = 1;
        while (n > 0)
        {
            n-=i;
            if (n >= 0) ans++;
            i++;
        }
        return ans;    
    }
};
