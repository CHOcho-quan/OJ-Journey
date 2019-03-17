//
//  SJTU1307_放球.cpp
//  
//
//  Created by 铨 on 2019/3/11.
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

bool isSquare(int n)
{
    return (int(sqrt(n)) * int(sqrt(n)) == n);
}

int main() {
    int n, now = 1;
    cin >> n;
    int *t;
    t = new int[n];
    for (int i = 0;i < n;i++) t[i] = -1;
    bool flag = true;
    
    while (flag)
    {
        flag = false;
        for (int i = 0;i < n;i++)
        {
            if (t[i] == -1) {
                t[i] = now;
                now++;
                flag = true;
                break;
            }
            if (isSquare(t[i] + now)) {
                t[i] = now;
                now++;
                flag = true;
                break;
            }
        }
    }
    
    cout << now-1;
}


