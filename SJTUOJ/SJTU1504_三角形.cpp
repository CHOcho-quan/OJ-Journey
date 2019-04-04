//
//  SJTU1504_三角形.cpp
//  
//
//  Created by 铨 on 2019/4/2.
//
//

#include <iostream>
#include <iomanip>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a+b <= c || a+c <=b || b+c <= a) cout << "not triangle";
    else {
        if (a*a+b*b==c*c) cout << "right-angled triangle";
        else cout << "triangle";
    }
}
