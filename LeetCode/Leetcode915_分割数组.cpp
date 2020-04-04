//
//  Leetcode915_分割数组.cpp
//  
//
//  Created by 铨 on 2020/3/28.
//

#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <numeric>

using namespace std;

int partitionDisjoint(vector<int>& A) {
    map<int,int> m1, m2;
    for (int i = 0;i < A.size();i++) {
        if (i == 0) {
            m1[i] = A[i];
            continue;
        }
        m1[i] = max(A[i], m1[i-1]);
    }
    
    for (int i = A.size()-1;i >= 0;i--) {
        if (i == A.size()-1) {
            m2[i] = 2147483647;
            continue;
        }
        m2[i] = min(A[i+1], m2[i+1]);
    }
    
    int result = 0;
    for (int i = 0;i < A.size();i++) {
        if (m2[i] > m1[i]) {
            result = i;
            break;
        }
    }
    
    for (int i = 0;i < A.size();i++) cout << m1[i] << ' ' << m2[i] << endl;
    
    return result + 1;
}

int main() {
    vector<int> A = {5,0,3,8,6};
    cout << partitionDisjoint(A);
}
