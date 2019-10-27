#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

int maxProfit(vector<int>& prices) {
    int maxi = 0, ind = 0, cur = 2147483647;
    
    for (int i = 0;i < prices.size();i++)
    {
        if (prices[i] < cur) cur = prices[i];
        else {
            maxi += prices[i] - cur;
            cur = prices[i];
        }
    }
    
    return maxi;
}

int main() {
    vector<int> p = {7,1,5,3,6,4};
    cout << maxProfit(p);
}
