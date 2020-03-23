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

vector<vector<string>> re;
void solve(int n, int i) {
    // solving i-th row of the n queens
    if (i >= n) {
        cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << ' ' << arr[3] << endl;
        // 1 Result get 
        vector<string> re1;
        for (int j = 0;j < n;j++) {
            string tmp = "";
            for (int k = 0;k < arr[j];k++) tmp += ".";
            tmp += "Q";
            for (int k = arr[j]+1;k < n;k++) tmp += ".";

            re1.push_back(tmp);
        }
        re.push_back(re1);
        // arr = vector<int>(n, -1);
    }
    else {
        for (int j = 0;j < n;j++) {
            arr[i] = j;
            if (judge(i)) solve(n, i+1);
            arr[i] = -1;
        }
    }
}

vector<vector<string>> solveNQueens(int n) 
{
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