//
//  SJTU1010_二哥储蓄.cpp
//  
//
//  Created by 铨 on 2019/1/18.
//
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int tmp, temp;
    int restMoney = 0, motherMoney = 0;
    for (int i = 0;i < 12;i++) {
        cin >> tmp;
        restMoney += (300 - tmp);
        motherMoney += (restMoney / 100) * 100;
        restMoney -= (restMoney / 100) * 100;
        //        cout << restMoney << endl;
        if (restMoney < 0) {
            cout << -(i+1);
            break;
        }
    }
    if (restMoney > 0) cout << restMoney + motherMoney * 1.2;
}
