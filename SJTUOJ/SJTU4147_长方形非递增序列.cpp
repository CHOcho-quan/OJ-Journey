//
//  SJTU4147_长方形非递增序列.cpp
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
    int n, wi, hi, tmp;
    bool flag = true;
    cin >> n;
    
    for (int i = 0;i < n;i++)
    {
        cin >> wi >> hi;
        if (!flag) continue;
        if (i == 0){
            tmp = max(wi, hi);
            continue;
        }
        if (tmp < min(wi, hi))
        {
            flag = false;
        }
        else {
            if (wi > tmp) tmp = hi;
            else {
                if (hi > tmp) tmp = wi;
                else
                {
                    tmp = max(hi, wi);
                }
            }
        }
    }
    
    if (flag) cout << "YES";
    else cout << "NO";
}

