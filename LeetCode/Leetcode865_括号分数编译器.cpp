#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <cmath>

using namespace std;

int scoreOfParentheses(string S) 
{
    if (S.length()==0) return 0;
    vector<char> v;
    int result = 0, num_of_left = 0;

    for (auto s : S)
    {
        if (s == '(') {
            num_of_left++;
            v.push_back('(');
        }
        else {
            if (v.back() == '(') result += pow(2, --num_of_left);
            else --num_of_left;
            v.push_back(')');
        }
    }

    return result;
}

int main()
{
    string s = "(()(()))";
    cout << scoreOfParentheses(s);
}