//
//  Leetcode575_分糖果.cpp
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

int distributeCandies(vector<int>& candies) {
    int sum = candies.size(), categories = 0;
    set<int> m;
    for (int i = 0;i < sum;i++) m.insert(candies[i]);
    
    if (m.size() >= sum / 2) return sum / 2;
    else return m.size();
}

int main() {
    vector<int> candies = {1,1,2,2,3,3};
    cout << distributeCandies(candies) << endl;
}
