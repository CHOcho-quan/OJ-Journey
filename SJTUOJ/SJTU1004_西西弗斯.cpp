//
//  SJTU1004_西西弗斯.cpp
//  
//
//  Created by 铨 on 2019/1/17.
//
//

#include <iostream>

using namespace std;

int main()
{
    int M, T, U, F, D;
    cin >> M >> T >> U >> F >> D;
    int * road = new int[T];
    char tmp;
    for (int i = 0;i < T;i++) {
        cin >> tmp;
        if (tmp == 'u') road[i] = U + D;
        if (tmp == 'f') road[i] = 2 * F;
        if (tmp == 'd') road[i] = U + D;
    }
    
    int sum = 0, result = 0;
    for (int i = 0;i < T;i++) {
        if (sum + road[i] < M) {
            sum += road[i];
            result++;
        }
        else break;
    }
    cout << result;
}
