//
//  Leetcode500_键盘单行单词.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

bool in(string s,string ss)
{
    bool flag1 = false,flag2 = true;
    for (int i = 0;i < s.size();i++)
    {
        for (int j = 0;j < ss.size();j++)
        {
            if (s[i]==ss[j])
            {
                flag1 = true;
                break;
            }
            else continue;
        }
        if (flag1)
        {
            flag1 = false;
            continue;
        }
        else
        {
            flag2 = false;
            break;
        }
    }
    return flag2;
}

bool judging(string a)
{
    string type_a = "qwertyuiopQWERTYUIOP";
    string type_b = "asdfghjklASDFGHJKL";
    string type_c = "zxcvbnmZXCVBNM";
    
    if (in(a,type_a) || in(a,type_b) || in(a,type_c)) return true;
    else return false;
}

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> result;
        for (int i = 0;i < words.size();i++)
        {
            if (judging(words[i])) result.push_back(words[i]);
            else continue;
        }
        
        return result;
    }
};
