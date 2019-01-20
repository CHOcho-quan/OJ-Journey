//
//  Leetcode371_不用加减的加减法.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

class Solution {
public:
    int getSum(int a, int b) {
        int sum = a;
        while (b!=0)
        {
            sum = a^b;
            b = (a&b)<<1;
            a = sum;
        }
        return sum;
    }
};
