#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

int mySqrt(int x) {
    int l = 0, h = x;
    int mid = (l + h) / 2;
    bool flag = true;
    
    if (x == 1 || x == 0) return x;
    
    while (mid != x / mid && flag)
    {
        if (mid > x / mid) {
            if ((mid-1) < double(x) / double(mid-1)) {
                flag = false;
                mid -= 1;
            }
            h = mid;
        }
        else {
            if ((mid+1) > double(x) / double(mid+1)) flag = false;
            l = mid;
        }
        
        if (flag) mid = (l + h) / 2;
    }
    
    return mid;
}

int mySqrt2(int x)
{
    if (x == 0) return 0;
    
    double cur = 2, pre;
    while (true)
    {
        pre = cur;
        cur = (cur + x / cur) / 2;
        if (abs(pre - cur) < 0.00006) return int(cur);
    }
}

int main() {
    int a = 8;
    cout << mySqrt(a);
}
