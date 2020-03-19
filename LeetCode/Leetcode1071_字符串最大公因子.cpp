#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>

using namespace std;

int gcd(int a, int b)
    {
        if (a%b==0) return b;
        return gcd(b, a%b);
    }
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) return "";

        return str1.substr(0, gcd(max(str1.length(), str2.length()), min(str1.length(), str2.length())));
    }

int main()
{
    string s = "ABCABCABC", p = "ABC";
    cout <<gcdOfStrings(s, p);
}
