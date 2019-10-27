#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int twoCitySchedCost(vector<vector<int>>& costs) {
    vector<int> comp;
    int result = 0;
    
    for (int i = 0;i < costs.size();i++) {
        comp.push_back(costs[i][0] - costs[i][1]);
        result += costs[i][1];
    }
    
    sort(comp.begin(), comp.end());
    for (int i = 0;i < costs.size() / 2;i++) result += comp[i];
    
    return result;
}

int main() {
    vector<int> ct1 = {10, 20}, ct2 = {30, 200}, ct3 = {400, 50}, ct4 = {30, 500};
    vector<vector<int>> cts = {ct1, ct2, ct3, ct4};
    
    cout << twoCitySchedCost(cts);
}
