//
//  Leetcode172_末尾的0.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

class Solution {
public:
    int trailingZeroes(int n) {
        int sum = 0;
        while (n!=0)
        {
            sum+=n/5;
            n/=5;
        }
        return sum;    
    }
};
