//
//  Leetcode69_平方根.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

class Solution {
public:
    int mySqrt(int x) {
        bool flag = true;
        long long i = 0;
        if (x==0) return 0;
        
        while (flag)
        {
            if (i*i <= x) i++;
            else return i-1;
        }
    }
};
