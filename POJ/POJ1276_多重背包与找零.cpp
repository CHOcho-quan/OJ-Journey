//
//  POJ1276_多重背包与找零.cpp
//  
//
//  Created by 铨 on 2018/10/21.
//
//

#include<iostream>

using namespace std;
/*
 * Cash Withdrawal & DP
 * Inputs : C, the expected change
 * N, total kinds of demonstration that has in the machine
 * ni, di, meaning there are ni bills with value di
 * */

int main()
{
    int C, N, ni, di, *OPT, *D, *bills;
    D = new int[1001];
    
    bills = new int[10001];
    OPT = new int[100001];
    
    while (cin >> C >> N) {
        if (C==0) {
            cout << 0 << endl;
            continue;
        }
        if (N==0) {
            cout << 0 << endl;
            continue;
        }
        
        // Initializing the D array for all kinds of bills
        int count = 1;
        for (int i = 0;i < N;i++) {
            cin >> ni >> di;
            for (int j = 1;j <= ni;j++) bills[count++] = j*di;
        }
        
        OPT[0] = 0;
        for (int i = 1;i < count;i++) {
            for (int j = C;j >= bills[i];j--) {
                OPT[j] = max(OPT[j], OPT[j-bills[i]] + bills[i]);
            }
        }
        
        cout << OPT[C] << endl;
    }
}
