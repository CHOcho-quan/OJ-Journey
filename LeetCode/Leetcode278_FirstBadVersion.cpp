//
//  Leetcode278_FirstBadVersion.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        for (int i = 0;i < s.length();i++)
        {
            result+=pow(26,s.length()-i-1)*(s[i]-'A'+1);
        }
        return result;
    }
};
