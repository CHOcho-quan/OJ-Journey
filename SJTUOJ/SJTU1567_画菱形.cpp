//
//  SJTU1567_画菱形.cpp
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
    string tmp;
    int n;
    cin >> tmp >> n;
    for (int i = 1;i < n+1;i++) {
        if (i <= n / 2 + 1){
            for (int j = 0;j < (n - 2*i+1) / 2;j++) cout << ' ';
            for (int j = 0;j < 2*i-1;j++) cout << tmp;
        }
        else {
            for (int j = 0;j < (2 * i - n - 1) / 2;j++) cout << ' ';
            for (int j = 0;j < 2*(n+1 - i)-1;j++) cout << tmp;
        }
        cout << endl;
    }
}

