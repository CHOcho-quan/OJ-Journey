#include <iostream>
#include <string>

using namespace std;

string reverseWords(string s) {
    if (s.length()==0) return s;
    string tmp = "", result = "";
    int i = 0;
    while (i < s.length()) {
        if (s[i] == ' ') {i++;continue;}
        tmp = "";
        int j = i;
        while (j < s.length() && s[j] != ' ')
        {
            tmp += s[j];
            j++;
        }

        tmp += " ";
        i = j + 1;
        result = tmp + result;
    }

    if (result.length() != 0)result = string(result.begin(), result.end() - 1);
    return result;
}