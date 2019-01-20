//
//  Leetcode507_完全数.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0;
        if (num%2) return 0;
        if (num==0) return 0;
        for (int i = 1;i < num/2;i++)
        {
            if (!(num%i))
            {
                sum+=i;
                if (i!=1)
                {
                    if (num/i >= num/2) sum+=num/i;
                }
            }
            //cout << sum << endl;
        }
        return sum==num;
    }
};
