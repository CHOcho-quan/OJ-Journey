//
//  SJTU1001_二哥苹果.cpp
//  
//
//  Created by 铨 on 2019/1/17.
//
//

#include <iostream>

using namespace std;

int main()
{
    int heightEr, heightChair, apples;
    cin >> heightEr >> heightChair >> apples;
    int *tree;
    tree = new int[apples];
    for (int i = 0;i < apples;i++) cin >> tree[i];
    int height = heightEr + heightChair;
    int result = 0;
    for (int i = 0;i < apples;i++) {
        if (tree[i] <= height) result++;
    }
    cout << result;
}
