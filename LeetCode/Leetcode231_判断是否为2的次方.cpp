//
//  Leetcode231_判断是否为2的次方.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n==0) return false;
        while (n!=0)
        {
            if (n%2!=0 && n!=1) return false;
            n/=2;
        }    
        return true; 
    }
};
