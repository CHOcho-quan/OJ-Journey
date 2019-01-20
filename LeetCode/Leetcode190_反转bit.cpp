//
//  Leetcode190_反转bit.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

uint32_t GetIt(uint32_t n)
{
    uint32_t sum = 0;
    while (n!=0)
    {
        n/=2;
        sum++;
    }
    return sum;
}

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t a,sum = 0,t = GetIt(n);
        for (int j = 0;j < t;j++)
        {
            a=n%2;
            sum+=a*pow(2,31-j);
            n/=2;
        }
        return sum;    
    }
};
