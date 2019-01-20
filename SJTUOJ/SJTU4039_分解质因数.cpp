//
//  SJTU4039_分解质因数.cpp
//  
//
//  Created by 铨 on 2019/1/17.
//
//

#include <iostream>
#include <cmath>

using namespace std;

void PrimeDivider(int n)
{
    int *c;
    c = new int[n - 2];
    for (int i = 0;i < n - 2;i++) {
        c[i] = i + 2;
    }
    
    for (int i = 0;i <= int(sqrt(n));i++) {
        if (c[i] != 0) {
            int p = c[i],j = c[i] * 2;
            while (j <= n) {
                c[j - 2] = 0;
                j = j + p;
            }
        }
    }
    
    //    for (int i = 0;i < n - 2;i++) cout << c[i] << ' ';
    //    cout << endl;
    
    for (int i = 0;i < n - 2;i++) {
        if (c[i] == 0) continue;
        else {
            while (n % c[i] == 0) {
                n = n / c[i];
                cout << c[i] << ' ';
            }
        }
    }
    if (n != 1) cout << n;
}

int main()
{
    int n;
    cin >> n;
    PrimeDivider(n);
}
