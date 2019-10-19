#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int ans = 0, rem = 0, cur = 0;
    bool flag = true;
    
    for (int i = 0;i < s.size();i++)
    {
        flag = true;
        
        for (int j = rem;j < i;j++)
        {
            if (s[j] == s[i])
            {
                //cout << "Same";
                flag = false;
                cur = max(1, cur - j + rem);
                rem = j + 1;
                break;
            }
        }
        
        //cout << cur << endl;
        
        if (flag) {
            cur++;
        }
        ans = max(ans, cur);
    }
    
    return ans;
}

int main() {
    string s = "pwwkew";
    int r = lengthOfLongestSubstring(s);
    cout << r;
}
