//
//  Leetcode46_全排列.cpp
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

vector<vector<int>> re;
vector<int> tmp;
bool permuting(vector<int> &nums, int num) {
    if (0 == nums.size()) {
        re.push_back(tmp);
        return 1;
    }
    
    for (int i = 0;i < nums.size();i++) {
        vector<int> cur(nums);
        tmp.push_back(nums[i]);
        cur.erase(cur.begin() + i);
        permuting(cur, num+1);
        tmp.pop_back();
    }
}
vector<vector<int>> permute(vector<int>& nums)
{
    permuting(nums, 0);
    return re;
}

int main() {
    vector<int> A = {5,0, 3, 4};
    vector<vector<int>> result = permute(A);
    for (auto r : result) {
        for (auto rr :r) {
            cout << rr << ' ';
        }
        cout << endl;
    }
}
