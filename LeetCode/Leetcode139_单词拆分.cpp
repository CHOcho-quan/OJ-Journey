#include <string>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> memo;
    bool wordBreakPar(string s, set<string>& wordDict, set<int>& length, int start) {
        if (start == s.length()) return true;

        if (memo[start] != -1) return memo[start];

        for (auto iter = length.begin();iter != length.end();iter++) {
            int i = *iter;
            if (start + i > s.length()) continue;
            string tmp = s.substr(start, i);
            if (wordDict.count(tmp)) {
                if (wordBreakPar(s, wordDict, length, start + i)) {
                    memo[start] = true;
                    return true;
                }
            }
        }

        memo[start] = 0;
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> wd = set<string>(wordDict.begin(), wordDict.end());
        set<int> wdL;
        
        for (auto iter = wd.begin();iter != wd.end();iter++) {
            string ss = *iter;
            wdL.insert(ss.length());
        }
        memo = vector<int>(s.length(), -1);

        return wordBreakPar(s, wd, wdL, 0);
    }

    // bool wordBreak(string s, vector<string>& wordDict) {
    //     auto cmp = [](const string &a, const string &b) { return a.length() < b.length(); };
    //     priority_queue<string, vector<string>, decltype(cmp)> pq(cmp);

    //     set<string> wd = set<string>(wordDict.begin(), wordDict.end());
    //     set<int> wdL;
        
    //     for (auto iter = wd.begin();iter != wd.end();iter++) {
    //         string ss = *iter;
    //         wdL.insert(ss.length());
    //     }

    //     for (auto iter = wdL.begin();iter != wdL.end();iter++) {
    //         int l = *iter;
    //         string tmp = s.substr(0, l);
    //         if (wd.count(tmp)) pq.push(tmp);
    //     }

    //     string result = "";
    //     while (!pq.empty())
    //     {
    //         string t = pq.top();
    //         // cout << t << endl;
    //         pq.pop();
    //         int L = t.length();
    //         if (L == s.length()) return true;

    //         for (auto iter = wdL.begin();iter != wdL.end();iter++) {
    //             int l = *iter;
    //             if (L + l > s.length()) continue;
                
    //             string tmp = s.substr(L, l);
    //             if (wd.count(tmp)) pq.push(t+tmp);
    //         }
    //     }

    //     return false;
    // }
};