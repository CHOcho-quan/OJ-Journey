#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
#include <cmath>

using namespace std;

bool isValid(string s) {
    stack<char> st1;
    
    for (int i = 0;i < s.length();i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') st1.push(s[i]);
        else{
            if (i == 0) return false;
            
            if (st1.empty()) return false;
            char tmp = st1.top();
            st1.pop();
            
            if (tmp == '(' && s[i] == ')') continue;
            if (tmp == '[' && s[i] == ']') continue;
            if (tmp == '{' && s[i] == '}') continue;
            
            return false;
        }
    }
    
    return st1.empty();
}

int main() {
    string t = "[])";
    cout << isValid(t);
}
