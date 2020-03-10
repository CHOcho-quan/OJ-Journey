#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>

using namespace std;

inline int gcd(int a, int b) {return b == 0? a : gcd(b , a % b);}

string gcdOfStrings(string str1, string str2) {
    if (str1 + str2 != str2 + str1) return "";
    return str1.substr(0, gcd(str1.size(), str2.size()));
}

int main()
{
    string s = "ABCABCABC", p = "ABC";
    cout <<gcdOfStrings(s, p);
}