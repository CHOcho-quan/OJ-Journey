//
//  SJTU1239_欢总工作.cpp
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
    int A, reminder, sum = 0;
    cin >> A;
    A = A - 3500;
    if (A <= 0) sum+=0;
    else {
        if (A <= 1500) sum+=A * 0.03;
        else {
            if (A <= 4500) sum += (45+(A- 1500)*0.1);
            else {
                if (A <= 9000) sum += (45 + 300 + (A - 4500)*0.2);
                else {
                    if (A <= 35000) sum += (45 + 300 + 900 + (A - 9000)*0.25);
                    else {
                        if (A <= 55000) sum += (1245 + 6500 + (A - 35000)*0.3);
                        else {
                            if (A <= 80000) sum += (7745 + 6000 + (A - 55000)*0.35);
                            else {
                                sum += (13745 + 8750 + (A - 80000)*0.45);
                            }
                        }
                    }
                }
            }
        }
    }
    
    cout << sum;
}

