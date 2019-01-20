//
//  Leetcode13_罗马数字转阿拉伯数.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

int Turn(const char a)
{
    switch (a)
    {
        case 'I':return 1;
        case 'V':return 5;
        case 'X':return 10;
        case 'L':return 50;
        case 'C':return 100;
        case 'D':return 500;
        case 'M':return 1000;
    }
}

class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        if (s.length()==1) return Turn(s[0]);
        else
        {
            int i = 1;
            for (i;i < s.length();)
            {
                if (Turn(s[i-1]) >= Turn(s[i]))
                {
                    sum+=Turn(s[i-1]);
                    i++;
                    if (i==s.length()) sum+=Turn(s[i-1]);
                }
                else
                {
                    sum+=Turn(s[i]);
                    sum-=Turn(s[i-1]);
                    i+=2;
                    if (i==s.length()) sum+=Turn(s[i-1]);
                }
            }
        }
        return sum;
    }
};
