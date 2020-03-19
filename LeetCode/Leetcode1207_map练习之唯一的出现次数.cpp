#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <cmath>

using namespace std;

bool uniqueOccurrences(vector<int>& arr) {
    map<int, int> arr_occ, val_occ;
    for (auto p:arr)
    {
        if (arr_occ.count(p)) arr_occ[p] += 1;
        else arr_occ[p] = 1;
    }

    for (auto p = arr_occ.begin();p != arr_occ.end();p++)
    {
        cout << p->first << ' ' << p->second << endl;
        if (val_occ.count(p->second)) return false;
        else val_occ[p->second] = 1;
    }

    return true;
}

int main()
{
    vector<int> arr = {-3,0,1,-3,1,1,1,-3,10,0};
    cout << uniqueOccurrences(arr);
}