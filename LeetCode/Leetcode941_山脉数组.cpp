#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>

using namespace std;

bool validMountainArray(vector<int>& A) {
    if (A.size()==0 || A.size()==1 || A.size()==2) return false;
    int cnt = 0;

    for (int i = 1;i < A.size()-1;i++) {
        if (A[i] == A[i-1] || A[i] == A[i+1]) return false;
        if (A[i] > A[i-1] && A[i] > A[i+1]) cnt++;
    }

    return cnt==1 && A[0] < A[1] && A[A.size()-2] > A[A.size()-1];
}