//
//  Leetcode389_字符串差距.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

class Solution {
public:
    char findTheDifference(string s, string t) {
        int index = 0;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        for (int i = 0;i < t.length();i++)
        {
            string temp = t;
            string ss = temp.erase(index,1);
            if (ss==s)  return t[index];
            else
            {
                index++;
            }
        }
        return t[index];
    }
};
