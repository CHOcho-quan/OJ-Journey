//
//  Leetcode125_回文串.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

string Delete(string s)
{
    string result;
    for (int i = 0;i < s.length();i++)
    {
        if (s[i]=='.'||s[i]==','||s[i]==':'||s[i]=='~'||s[i]=='!'||s[i]=='?'||s[i]==' '||s[i]=='@'||s[i]=='#'||s[i]=='$'||s[i]=='%'||s[i]=='^'||s[i]=='&'||s[i]=='*'||s[i]=='('||s[i]==')'||s[i]=='-'||s[i]=='+'||s[i]=='\"'||s[i]=='\''||s[i]==';'||s[i]=='`') continue;
        else if (s[i] < 'a')
        {
            s[i] = s[i] - 'A' + 'a';
            result.insert(result.end(),s[i]);
        }
        else result.insert(result.end(),s[i]);
    }
    return result;
}

class Solution {
public:
    bool isPalindrome(string s) {
        if (s=="") return true;
        string ss = Delete(s);
        bool result = true;
        int len = ss.length();
        for (int i = 0;i < len/2;i++)
        {
            if (ss[i]!=ss[len-1-i])
            {
                result = false;
                break;
            }
        }  
        return result; 
    }
};
