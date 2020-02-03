#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;

bool isPalindromeBF(string s)
{
    int len = s.length()-1, ss = 0;
    bool flag = true;

    while (ss <= len)
    {
        if (s[ss++] != s[len--]) return false;
    }
    return true;
}

bool isPalindrome(string s, int ss, int len)
{
    bool flag = true;

    while (ss <= len)
    {
        if (s[ss++] != s[len--]) return false;
    }
    return true;
}

vector<vector<int>> palindromePairs(vector<string>& words) {
    set<int> s;
    unordered_map<string, int> mp;
    vector<vector<int>> ans;
    for (int i = 0;i < words.size();i++)
    {
        s.insert(words[i].size());
        mp[words[i]] = i;
    }

    for (int i = 0;i < words.size();i++)
    {
        string tmp = words[i];
        reverse(tmp.begin(), tmp.end());
        if (mp.count(tmp) && mp[tmp] != i) ans.push_back({i, mp[tmp]});

        int length=tmp.size();
        for(auto it=s.begin();*it!=length;it++){
            int d=*it;
            if(isPalindrome(tmp,0,length-d-1) && mp.count(tmp.substr(length-d))){
                ans.push_back({i, mp[tmp.substr(length-d)]});
            }
            if(isPalindrome(tmp,d,length-1) && mp.count(tmp.substr(0,d))){
                ans.push_back({mp[tmp.substr(0,d)], i});
            }
        }
    }

    return ans;
}

vector<vector<int>> palindromePairsBF(vector<string>& words) {
    vector<vector<int>> ans;
    for (int i = 0;i < words.size();i++)
    {
        for (int j = 0;j < words.size();j++)
        {
            if (i >= j) continue;
            vector<int> tmp;
            string nowij = words[i] + words[j], nowji = words[j] + words[i];
            //cout << nowij << ' ' << nowji << endl;
            if (isPalindromeBF(nowij)) {
                //cout << "ij" << endl;
                tmp.push_back(i);
                tmp.push_back(j);
                if (tmp.size()!=0) ans.push_back(tmp);
                tmp.clear();
            }
            if (isPalindromeBF(nowji)) {
                //cout << "ji" << endl;
                tmp.push_back(j);
                tmp.push_back(i);
                if (tmp.size()!=0) ans.push_back(tmp);
                tmp.clear();
            }
        }
    }

    return ans;
}

int main()
{
    vector<string> words = {"abcd","dcba","lls","s","sssll"};
    vector<vector<int>> palindromePair = palindromePairs(words);
    for (auto pp:palindromePair)
    {
        cout << '[';
        for (auto p:pp)
        {
            cout << p << ' ';
        }
        cout << ']' << ' ';
    }
}