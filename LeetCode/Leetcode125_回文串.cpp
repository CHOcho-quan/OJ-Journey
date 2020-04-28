#include <string>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool check(char s)
    {
        return ((s <= 'Z' && s >= 'A') || (s <= 'z' && s >= 'a') || (s <= '9' && s >= '0'));
    }

    bool isPalindrome(string s) {
        if (s.length() == 0) return 1;

        // std::transform(s.begin(), s.end(), s.begin(),
        //     [](unsigned char c){ return std::tolower(c); });
        int i = 0, j = s.length()-1;
        while (j >= i)
        {
            while (i < s.length() && !check(s[i])) i++;
            while (j < s.length() && !check(s[j])) j--;
            if (i >= s.length() || j >= s.length()) return 1;
            // cout << s[i] << ' ' << s[j] << endl;
            if (s[i] != s[j] && ((s[i] <= '9' && s[i] >= '0') || s[i] - 'A' + 'a' != s[j]) && (s[i] != s[j] - 'A' + 'a' || (s[j] <= '9' && s[j] >= '0'))) return 0;
            i++;
            j--;
        }

        return 1;
    }
};