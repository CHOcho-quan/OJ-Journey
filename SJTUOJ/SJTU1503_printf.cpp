//
//  SJTU1503_printf.cpp
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
    double a,b,c,d;
    cin >> a >> b >> c >> d;
    printf("%g", sqrt((a - c)*(a - c) + (b - d)*(b - d)));
}
