//
//  SJTU1014_大位数加法.cpp
//  
//
//  Created by 铨 on 2019/1/18.
//
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a, b, r, tmp, m, n;
    cin >> a >> b;
    r = "";
    int on = 0, temp1, temp2, sum = 0;
    
    if (a.length() > b.length()) {
        m = a;
        n = b;
    }
    else {
        m = b;
        n = a;
    }
    
    for (int i = 1;i <= n.length();i++) {
        temp1 = m[m.length() - i] - '0';
        temp2 = n[n.length() - i] - '0';
        //        cout << temp1 << ' ' << temp2 << ' ' << (temp1 + temp2) % 10 + on << endl;
        sum = temp1 + temp2 + on;
        tmp = (((sum) % 10) + '0');
        //        cout << tmp << endl;
        r = tmp + r;
        on = sum / 10;
    }
    
    if (m.length() == n.length() && on == 1) sum = 0;
    else {
        if (on == 0) {
            for (int i = m.length() - n.length() - 1;i >= 0;i--) {
                r = m[i] + r;
            }
        }
        else {
            for (int i = m.length() - n.length() - 1;i >= 0;i--) {
                temp1 = m[i] - '0' + on;
                on = temp1 / 10;
                temp1 = temp1 % 10;
                tmp = temp1 + '0';
                r = tmp + r;
            }
        }
    }
    if (on == 1) r = '1' + r;
    cout << r;
}
