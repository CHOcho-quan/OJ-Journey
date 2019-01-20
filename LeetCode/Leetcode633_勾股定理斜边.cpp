//
//  Leetcode633_勾股定理斜边.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

class Solution {
public:
    bool judgeSquareSum(int c) {
        int a = sqrt(c),b;
        for (int i = 0;i < a+1;i++)
        {
            b = c - i*i;
            if ((int)sqrt(b)*(int)sqrt(b)==b) return true;
        }
        return false;
    }
};
