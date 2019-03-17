//
//  SJTU1208_大圣切蛋糕.cpp
//  
//
//  Created by 铨 on 2019/3/5.
//
//

#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <stack>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double r, a;
    double S = -1;
    while (cin >> r >> a)
    {
        //        cin >> r >> a;
        double d = sqrt(r*r - a*a);
        double Striangle = a * d;
        //        cout << Striangle;
        double Shu = r * r * acos(a / r);
        //        cout << ' ' << acos(a / r) << ' ' << Shu << ' ';
        S = max(Shu - Striangle, S);
    }
    cout << setiosflags(ios::fixed) << setprecision(2) << S;
}


