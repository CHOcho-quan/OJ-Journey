#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> pq;
    int max1, max2;
    for (int i = 0;i < stones.size();i++) pq.push(stones[i]);
    
    while (!pq.empty())
    {
        if (!pq.empty()) max1 = pq.top();
        else return 0;
        pq.pop();
        if (!pq.empty()) max2 = pq.top();
        else return max1;
        pq.pop();
        
        if (max1 == max2) continue;
        else pq.push(abs(max1 - max2));
    }
    
    return 0;
}

int main() {
    vector<int> st = {1, 9, 8, 7};
    cout << lastStoneWeight(st);
}
