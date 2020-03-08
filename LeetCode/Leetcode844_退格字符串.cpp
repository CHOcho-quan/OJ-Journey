#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

bool backspaceCompare(string S, string T) 
{
    string s, t;
    for (int i = 0;i < S.length();i++)
    {
        if (S[i] == '#') {if (s.length()!=0) s.pop_back();}
        else s.push_back(S[i]);
    }

    for (int i = 0;i < T.length();i++)
    {
        if (T[i] == '#') {if (t.length()!=0) t.pop_back();}
        else t.push_back(T[i]);
    }

    cout << s << ' ' << t << endl;
    return s==t;
}

int main()
{
    string s = "xywrrmp", t = "xywrrmu#p";
    cout << backspaceCompare(s, t);
}