//
//  SJTU2109_一元二次方程.cpp
//  
//
//  Created by 铨 on 2019/3/19.
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
    int n, k, a, b, c, sum = 0;
    int *aa;
    cin >> n;
    aa = new int[n];
    for (int i = 0;i < n;i++) {
        cin >> aa[i];
    }
    cin >> k;
    for (int i = 0;i < k;i++)
    {
        cin >> b >> c;
        for (int j = 0;j < n;j++) {
            if (b*b - 4 * aa[j] * c >= 0) sum++;
            else break;
        }
        cout << sum << endl;
        sum = 0;
    }
}

