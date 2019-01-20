//
//  SJTU1242_找素数.cpp
//  
//
//  Created by 铨 on 2019/1/17.
//
//

#include <iostream>
#include <cmath>

using namespace std;

void findPrime(int a,int b)
{
    int *c;
    c = new int[b - 2];
    for (int i = 0;i < b - 2;i++) {
        c[i] = i + 2;
    }
    
    for (int i = 0;i <= int(sqrt(b));i++) {
        if (c[i] != 0) {
            int p = c[i],j = c[i] * 2;
            while (j <= b) {
                c[j - 2] = 0;
                j = j + p;
            }
        }
    }
    
    //    for (int i = 0;i < b - 2;i++) cout << c[i] << ' ';
    
    int count = 0;
    for (int i = a - 2;i < b - 2;i++) {
        if (c[i] != 0) count++;
    }
    
    cout << count;
}

int main()
{
    int a,b;
    cin >> a >> b;
    findPrime(a,b);
}
