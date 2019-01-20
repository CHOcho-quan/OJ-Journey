//
//  POJ1018_动态规划与通信公司带宽.cpp
//  
//
//  Created by 铨 on 2018/10/21.
//
//

#include<iostream>
#include<iomanip>
using namespace std;
// satisfy the condition that all the bandwidth is less than 1001
int company[101][1001];
/*
 * Communication Inc. Devices & DP Problem
 * Inputs : t, number of test cases
 * n, total devices needed
 * m, m (b, p) pairs, m manufacturers developing bandwidth b and price p devices
 * Outputs : e, the maximum B / P in the whole question
 * */
int main() {
    int t;
    cin >> t;
    while (t--) {
        for (auto &i : company) {
            for (int &j : i) {
                j = 2147483647;
            }
        }
        // DP to get the whole company array of (i, j) meaning the ith group with bandwidth j
        for (int i = 0; i < 1001; i++)
            company[0][i] = 0;
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int m;
            cin >> m;
            while (m--) {
                int b;
                int p;
                cin >> b >> p;
                for (int j = 1; j <= b; j++)
                    if (company[i - 1][j] + p < company[i][j])
                        company[i][j] = company[i - 1][j] + p;
            }
        }
        
        // Find the maximum B/P in the whole array company
        double e = 0.0;
        for (int i = 0; i < 1001; i++)
            if (1.0 * i / company[n][i] > e)
                e = 1.0 * i / company[n][i];
        cout << fixed << setprecision(3) << e << endl;
    }
}
