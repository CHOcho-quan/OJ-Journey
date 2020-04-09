#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

string convertToBase7(int num) {
    string result = "", sign = "";
    if (num < 0) {
        sign = "-";
        num = -num;
    }

    while (num / 7 != 0) {
        int tmp = num % 7;
        num /= 7;
        result += (tmp + '0');
        cout << result << endl;
    }
    result += (num % 7 + '0');
    reverse(result.begin(), result.end());
    return sign + result;
}
