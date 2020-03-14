#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>

using namespace std;

string reorganizeString(string S) 
{
    map<char, int> smp;
    for (auto s:S)
    {
        if (smp.count(s)) {
            smp[s] += 1;
            if (smp[s] > S.length() - smp[s] + 1) return "";
        }
        else smp[s] = 1;
    }

    sort(S.begin(), S.end(), [&smp](char &a1, char &a2) {if (smp[a1] == smp[a2]) return a1 > a2; return smp[a1] > smp[a2];});
    cout << S << endl;

    string result(S.length(), 't');
    for (int i = 0;i < S.length();i+=2) result[i] = S[i/2];
    cout << result << ' ' << S;
    for (int i = 1;i < S.length();i+=2) result[i] = S[i/2 + (S.length() + 1) / 2];

    return result;
}

int main()
{
    string s = "abbabbaaab";

    cout << reorganizeString(s);
}