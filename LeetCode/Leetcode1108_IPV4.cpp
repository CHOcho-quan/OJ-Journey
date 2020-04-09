#include <iostream>
#include <string>

using namespace std;

string defangIPaddr(string address) {
    string result = "";
    for (int i = 0;i < address.length();i++) {
        if (address[i] != '.') result += address[i];
        else
        {
            result += '[';
            result += '.';
            result += ']';
        }
    }

    return result;
}