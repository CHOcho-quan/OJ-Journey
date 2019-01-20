//
//  SJTU1240_欢总的兔子.cpp
//  
//
//  Created by 铨 on 2019/1/19.
//
//

#include <iostream>
#include <set>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;
    int rabbits = 1, able = 0;
    
    for (int i = 0;i < n;i++)
    {
        int tmp1 = able;
        able += rabbits;
        rabbits = tmp1;
    }
    
    cout << rabbits + able;
}
