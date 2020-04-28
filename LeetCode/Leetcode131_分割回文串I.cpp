#include <string>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkPalindrome(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        return (s == t);
    }

    vector<vector<string>> vec_s;
    vector<string> tmpt;

    bool partitionPart(string s, int start) {
        if (s.length() == start) {
            vec_s.push_back(tmpt);
            return 1;
        }
        // cout << start << endl;
        for (int i = 1;i < s.length() - start + 1;i++) {
            string t1 = s.substr(start, i);
            if (checkPalindrome(t1)) {
                tmpt.push_back(t1);
                partitionPart(s, start + i);
                tmpt.pop_back();
            }
        }

        return 0;
    }

    vector<vector<string>> partition(string s) {
        if (s.length()==0) return vec_s;
        partitionPart(s, 0);
        // cout << s.substr(2, 1);
        
        return vec_s;
    }
};