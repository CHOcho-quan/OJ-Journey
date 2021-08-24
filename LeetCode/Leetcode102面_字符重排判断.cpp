#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>

using namespace std;

bool CheckPermutation(string s1, string s2) 
{
    map<char, int> mp;
    for (auto s : s1)
    {
        if (mp.count(s)) mp[s] += 1;
        else mp[s] = 1;
    }

    for (auto s : s2)
    {
        if (mp.count(s)) mp[s] -= 1;
        else return false;
    }

    for (auto p = mp.begin();p != mp.end();p++)
    {
        if (p->second != 0) return false;
    }

    return true;
}

int main()
{
    string s = "abc", t = "cda";
    cout << CheckPermutation(s, t);
}