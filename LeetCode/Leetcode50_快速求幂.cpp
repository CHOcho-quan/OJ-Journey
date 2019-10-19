#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

double myPow1(double x, int n) {
    double re = 1;
    bool flag = false;
    if (n < 0) {
        flag = true;
        n = -n;
    }
    
    for (int i = 0;i < n;i++)
    {
        re *= x;
    }
    
    return flag ? 1/re:re;
}

double myPow(double x, int n) {
    if (n == 0) return 1;
    if (n == 1) return x;
    if (n == -1) return 1/x;
    
    double half = myPow(x, n / 2), rest = myPow(x, n % 2);
    
    return half * half * rest;
}

double myPow2(double x, int n) {
    double cp = x, ans = 1;
    
    for (long long i = abs(n);i > 0;i /= 2)
    {
        if (i % 2) ans *= cp;
        cp *= cp;
    }
    
    if (n < 0) ans = 1/ans;
    
    return ans;
}

int main() {
    double x = 2.00000;
    int n = -3;
    cout << myPow(x, n);
}
