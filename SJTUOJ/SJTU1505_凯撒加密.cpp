//
//  SJTU1505_凯撒加密.cpp
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
    char a;
    cin >> a;
    if (a == 'z') cout << 'c';
    else{
        if (a == 'y') cout << 'b';
        else {
            if (a == 'x') cout << 'a';
            else cout << char(a+3);
        }
    }
}
