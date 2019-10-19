#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() == 0) return "";
    if (strs.size() == 1) return strs[0];
    string comp = strs[0];
    string result = "";
    bool flag;
    
    for (int i = 0;i < comp.size();i++)
    {
        flag = true;
        for (int j = 1;j < strs.size();j++)
        {
            if (i >= strs[j].size()) return result;
            if (strs[j][i] != comp[i]) {
                flag = false;
                break;
            }
            if (i < strs[j].size() && strs[j][i] == comp[i]) continue;
        }
        
        if (flag) result += comp[i];
        else break;
    }
    
    return result;
}

int main() {
    vector<string> s = {"aca","cba"};
    cout << longestCommonPrefix(s);
}
