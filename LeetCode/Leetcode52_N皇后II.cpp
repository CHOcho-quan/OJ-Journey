#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> arr;

bool judge(int i) {
    for (int j = 0;j < i;j++) {
        if (arr[j] == arr[i]) return false;
        if (abs(arr[i] - arr[j]) == abs(i - j)) return false;
    }

    return true;
}

int re;
void solve(int n, int i) {
    // solving i-th row of the n queens
    if (i >= n) {
        re++;
    }
    else {
        for (int j = 0;j < n;j++) {
            arr[i] = j;
            if (judge(i)) solve(n, i+1);
            arr[i] = -1;
        }
    }
}

int totalNQueens(int n) {
    re = 0;
    arr = vector<int>(n, 0);
    solve(n, 0);
    return re;       
}

int main() {
    vector<vector<string>> r = solveNQueens(4);
    for (auto i:r) {
        for (auto j:i) cout << j << endl;
        cout << "----------------" << endl;
    }
}