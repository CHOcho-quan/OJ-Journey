//
//  Leetcode461_汉明距离.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x^y,ans = 0;
        while (z!=0)
        {
            if (z%2==1) ans++;
            z/=2;
        }
        return ans;
    }
};
