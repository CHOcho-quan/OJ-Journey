#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int reverse(int x) {
    int rev = 0;
    while (x != 0) {
        int pop = x % 10;
        x /= 10;
        if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
        if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
        rev = rev * 10 + pop;
    }
    return rev;
}

bool isPalindrome(int x) {
    if (reverse(x) == x and x >= 0) return true;
    else return false;
}

int main() {
    int x = -321;
    cout << reverse(x);
}
