//
//  Leetcode20_括号匹配.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

char ItsFriend(char a)
{
    switch (a)
    {
        case '(': return ')';
        case '[': return ']';
        case '{': return '}';
        case '~': return '*';
    }
}

class Solution {
public:
    bool isValid(string s) {
        string read = "";
        if (s=="") return true;
        if (s[0]==')' || s[0]==']' || s[0]=='}') return false;
        read+=s[0];
        //int len = read.length();
        char right_most = read[0];
        for (int i = 1;i < s.length();i++)
        {
            //cout << read;
            if (s[i]!=ItsFriend(right_most) && (s[i]!='(' && s[i]!='[' && s[i]!='{')) return false;
            else if (s[i]==ItsFriend(right_most))
            {
                read.erase(read.end()-1);
                if (read.length()!=0) right_most = read[read.length()-1];
                else right_most = '~';
            }
            else
            {
                read.insert(read.end(),s[i]);
                right_most = read[read.length()-1];
            }
            //cout << read << endl;
        }
        if (read.length()==0) return true;
        else return false;    
    }
};
