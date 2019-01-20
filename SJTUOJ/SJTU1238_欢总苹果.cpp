//
//  SJTU1238_欢总苹果.cpp
//  
//
//  Created by 铨 on 2019/1/17.
//
//
#include <iostream>

using namespace std;

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    if (a>b && a>c) cout << a;
    if (b>a && b>c) cout << b;
    if (c>a && c>b) cout << c;
}
