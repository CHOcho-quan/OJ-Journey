//
//  SJTU1335_优先队列应用.cpp
//  
//
//  Created by 铨 on 2019/3/11.
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
    int n, sum = 0, tmp;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> t;
    for (int i = 0;i < n;i++) {
        cin >> tmp;
        t.push(tmp);
    }
    
    int min1 = -1, min2 = -1;
    for (int i = 0;i < n-1;i++)
    {
        min1 = t.top();
        //        cout << min1 <<endl;
        t.pop();
        if (t.empty()) break;
        min2 = t.top();
        //        cout << min2 <<endl;
        t.pop();
        sum += min1 + min2;
        t.push(min1 + min2);
    }
    
    cout << sum;
}


