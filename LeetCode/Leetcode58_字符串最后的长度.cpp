//
//  Leetcode58_字符串最后的长度.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s=="") return 0;
        bool flag = true;
        int sum = 0;
        for (int i = s.length()-1;i >= 0;i--)
        {
            if ((s[i]-'A'>=0 && s[i]-'Z'<=0) || (s[i]-'a'>=0 && s[i]-'z'<=0))
            {
                flag = false;
                sum++;
            }
            else if (flag) continue;
            else break;
        }
        
        return sum;    
    }
};
