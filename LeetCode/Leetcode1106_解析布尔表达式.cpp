#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>

using namespace std;

bool operate(vector<bool> exp, int oper)
{
    // 0 - |
    // 1 - !
    // 2 - &
    if (oper == 0) {
        bool re = false;
        for (int i = 0;i < exp.size();i++) re = re || exp[i];
        return re;
    }
    if (oper == 1) return !exp[0];
    if (oper == 2) {
        bool re = true;
        for (int i = 0;i < exp.size();i++) re = re && exp[i];
        return re;
    }

    return false;
}

bool parseBoolExpr(string expression) {
    stack<char> st;
    for (int i = 0;i < expression.length();i++) {
        if (expression[i] != ')') st.push(expression[i]);
        else
        {
            vector<bool> exp;
            while (true)
            {
                char tmp = st.top();
                st.pop();
                if (tmp == 't') exp.push_back(true);
                if (tmp == 'f') exp.push_back(false);
                if (tmp == '|')
                {
                    bool re = operate(exp, 0);
                    if (re) st.push('t');
                    else st.push('f');
                    break;
                }
                if (tmp == '!')
                {
                    bool re = operate(exp, 1);
                    if (re) st.push('t');
                    else st.push('f');
                    break;
                }
                if (tmp == '&')
                {
                    bool re = operate(exp, 2);
                    if (re) st.push('t');
                    else st.push('f');
                    break;
                }
            }
        }
    }

    char result = st.top();
    // cout << result;
    if (result == 't') return true;
    return false;
}