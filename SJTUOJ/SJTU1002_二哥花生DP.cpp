//
//  SJTU1002_二哥花生DP.cpp
//  
//
//  Created by 铨 on 2019/1/17.
//
//

#include <iostream>

using namespace std;

int getPeanut(int a, int b, int ** peanuts, int L, int W)
{
    for (int i = W-1;i >= a;i--) {
        for (int j = 0;j < L;j++) {
            peanuts[i][j] -= peanuts[i-a][j];
        }
    }
    //
    //    for (int i = 0;i < W;i++) {
    //        for (int j = 0;j < L;j++) {
    //            cout << peanuts[i][j] << ' ';
    //        }
    //        cout << endl;
    //    }
    
    int max = -1, sum = 0;
    for (int i = a-1;i < W;i++) {
        for (int j = 0;j < L - b + 1;j++) {
            for (int m = 0;m < b;m++) {
                sum += peanuts[i][j+m];
            }
            if (sum > max) max = sum;
            sum = 0;
        }
    }
    //    cout << max;
    return max;
}

int main()
{
    int L, W;
    cin >> W >> L;
    int **peanuts;
    peanuts = new int*[W];
    for (int i = 0;i < W;i++) peanuts[i] = new int[L];
    int a, b, tmp;
    for (int i = 0;i < W;i++)
    {
        for (int j = 0;j < L;j++)
        {
            cin >> tmp;
            if (i != 0) peanuts[i][j] = peanuts[i-1][j] + tmp;
            else peanuts[i][j] = tmp;
        }
    }
    //    for (int i = 0;i < W;i++) {
    //        for (int j = 0;j < L;j++) {
    //            cout << peanuts[i][j] << ' ';
    //        }
    //        cout << endl;
    //    }
    cin >> a >> b;
    
    int result = getPeanut(a, b, peanuts, L, W);
    cout << result;
}
