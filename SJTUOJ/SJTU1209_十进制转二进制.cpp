//
//  SJTU1209_十进制转二进制.cpp
//  
//
//  Created by 铨 on 2019/3/5.
//
//

#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <stack>
#include <iomanip>

using namespace std;

int main() {
    int n,tmp,sum=0;
    cin >> n;
    for (int i = 0;i < n;i++)
    {
        cin >> tmp;
        
        while (tmp >= 1)
        {
            if (tmp == 1) {
                sum+=1;
                break;
            }
            
            int t = tmp % 2;
            tmp = tmp / 2;
            if (t == 1) sum+=1;
        }
    }
    cout << sum;
}


