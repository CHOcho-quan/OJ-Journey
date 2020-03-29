//
//  Leetcode268_缺失数字.cpp
//  
//
//  Created by 铨 on 2020/3/27.
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

int missingNumber(vector<int>& nums) {
    int sum = (1 + nums.size()) * nums.size() / 2;
    //    cout <<sum << endl;
    return (sum - accumulate(nums.begin(), nums.end(), 0));
}


int main() {
    vector<int> nums = {9,6,4,2,3,5,7,0,1};
    cout << missingNumber(nums);
}
