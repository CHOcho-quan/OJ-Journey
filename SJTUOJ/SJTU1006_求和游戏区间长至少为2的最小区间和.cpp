//
//  SJTU1006_求和游戏区间长至少为2的最小区间和.cpp
//  
//
//  Created by 铨 on 2019/1/17.
//
//

#include <iostream>

using namespace std;

int main()
{
    int n;
    int *tmp;
    
    cin >> n;
    tmp = new int[n];
    for (int i = 0;i < n;i++) cin >> tmp[i];
    
    int sum = 0, cnt = 0, maxi = -2147483647;
    for (int i = 0;i < n;i++) {
        if (sum + tmp[i] >= 0) {
            sum += tmp[i];
            cnt += 1;
        }
        else {
            sum = 0;
            cnt = 0;
        }
        if (cnt > 1) maxi = max(sum, maxi);
    }
    //    cout << maxi;
    
    cnt = 0;
    sum = 0;
    for (int i = n-1;i >= 0;i--) {
        if (sum + tmp[i] >= 0) {
            sum += tmp[i];
            cnt += 1;
        }
        else {
            sum = 0;
            cnt = 0;
        }
        if (cnt > 1) maxi = max(sum, maxi);
    }
    if (maxi > 0) cout << maxi;
    else cout << "Game Over";
}
