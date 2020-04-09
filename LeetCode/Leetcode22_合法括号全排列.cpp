#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<string> result;
string t;
int cur_state;
bool parenthesis(int num, int n) {
    if (n == num)
    {
        // Get result done
        if (cur_state != 0) return 0;
        result.push_back(t);
        return 1;
    }
    vector<string> parenthes = {"(", ")"};
    for (int i = 0;i < 2;i++) {
        if (i) cur_state--;
        else cur_state++;
        if (cur_state < 0) {
            cur_state += 1;
            continue;
        }

        t += parenthes[i];
        parenthesis(num+1, n);
        t.pop_back();
        if (i) cur_state++;
        else cur_state--;
    }

    return 0;
}

vector<string> generateParenthesis(int n) {
    cur_state = 0;
    t = "";
    parenthesis(0, 2 * n);
    return result;
}