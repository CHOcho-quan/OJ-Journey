#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
#include <cmath>

using namespace std;

int balancedStringSplit(string s) {
    int l = 0, r = 0, re = 0;
    
    for (int i = 0;i < s.length();i++)
    {
        if (s[i] == 'L') l++;
        if (s[i] == 'R') r++;
        
        if (l == r && l != 0) {
            re++;
            l = 0;
            r = 0;
        }
    }
    return re;
}

int main() {
    string s = "RLRRLLRLRL";
    cout << balancedStringSplit(s);
}
