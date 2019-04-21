//
//  SJTU1015_高精度乘法.cpp
//  
//
//  Created by 铨 on 2019/4/17.
//
//

#include <iostream>
#include <string>

using namespace std;

string Add(string a, string b)
{
    string r, tmp, m, n;
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
    return r;
}

string Time(string a, string b)
{
    string result, tmp1, tmp2;
    tmp1 = tmp2 = "";
    result = "0";
    int adder = 0;
    int round = 1, product;
    for (int i = a.length()-1;i >= 0;i--)
    {
        for (int j = b.length()-1;j >= 0;j--)
        {
            product = (a[i]-'0')*(b[j] - '0') + adder;
            //            cout << product << ' ' << to_string(product) << endl;
            tmp1 = to_string((product % 10)) + tmp1;
            //            cout << tmp1 << endl;
            adder = product / 10;
        }
        if (adder != 0)
        {
            tmp1 = to_string(adder) + tmp1;
            adder = 0;
        }
        //        cout << tmp1 << endl;
        result = Add(result, tmp1);
        tmp1 = "";
        for (int j = 0;j < round;j++) tmp1 += '0';
        round++;
    }
    return result;
}

int main()
{
    string a, b;
    cin >> a >> b;
    cout << Time(a, b);
}
