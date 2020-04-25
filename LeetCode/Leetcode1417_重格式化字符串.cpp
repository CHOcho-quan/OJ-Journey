#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

string reformat(string s) {
    string result = "", num = "", word = "";
    int n_num = 0, n_word = 0;
    for (int i = 0;i < s.length();i++)
    {
        if (s[i] >= '0' && s[i] <= '9') {
            word += s[i];
            n_word += 1;
        }
        else {
            n_num += 1;
            num += s[i];
        }
    }
    cout << word << ' ' << num << endl;

    if (n_num > n_word + 1 || n_word > n_num + 1) return result;

    result = string(s.length(), 'a');
    cout << result << endl;
    for (int i = 0;i < s.length();i+=2) result[i] = (n_num > n_word) ? num[i/2] : word[i/2];
    for (int i = 1;i < s.length();i+=2) result[i] = (n_num <= n_word) ? num[i/2] : word[i/2];

    return result;
}