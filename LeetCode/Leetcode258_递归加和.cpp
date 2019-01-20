//
//  Leetcode258_递归加和.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

class Solution {
public:
    int addDigits(int num) {
        while (num/10!=0)
        {
            num = num/10 + num%10;
        }
        return num;
    }
};
