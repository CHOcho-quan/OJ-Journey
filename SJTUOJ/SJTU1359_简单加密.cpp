//
//  SJTU1359_简单加密.cpp
//  
//
//  Created by 铨 on 2019/3/18.
//
//

#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <stack>
#include <iomanip>
#include <cmath>
#include <queue>

using namespace std;

int main() {
    string t;
    int mima = 0, cnt = 1;
    //    cout << 'A' - 'Z';
    int c = 3;
    while (cin >> t)
    {
        for (int i = 0;i < t.length();i++)
        {
            int tmp = t[i] - 'A' + 1;
            if (tmp > 26) tmp -= 6;
            mima += cnt * tmp;
            cnt++;
        }
        cnt++;
    }
    cout << mima;
}

