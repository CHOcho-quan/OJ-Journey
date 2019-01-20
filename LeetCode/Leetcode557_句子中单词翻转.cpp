//
//  Leetcode557_句子中单词翻转.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

void reverse(string &s)
{
    int len = s.length(),i = 0;
    char temp;
    
    while (i!=len/2)
    {
        temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
        i++;
    }
}

class Solution {
public:
    string reverseWords(string s) {
        string result = "",temp = "";
        
        for (int i = 0;i < s.length();i++)
        {
            if (s[i]!=' ') temp = temp + s[i];
            else
            {
                reverse(temp);
                result = result + temp;
                if (i!=s.length()-1) result = result + " ";
                temp = "";
            }
        }
        reverse(temp);
        result = result + temp;
        
        return result;
    }
};
