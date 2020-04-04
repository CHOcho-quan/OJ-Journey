//
//  Leetcode43_可重复的全排列.cpp
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

vector<vector<int>> res;
vector<int> tmp2;
bool permuting2(vector<int>& nums,int num) {
    if (0 == nums.size()) {
        res.push_back(tmp2);
        return 1;
    }
    
    for (int i = 0;i < nums.size();i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue;
        vector<int> cur(nums);
        tmp2.push_back(nums[i]);
        cur.erase(cur.begin() + i);
        permuting2(cur, num+1);
        tmp2.pop_back();
    }
    return 1;
}

vector<vector<int>> permuteUnique2(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    permuting2(nums, 0);
    return res;
}

set<vector<int>> red;
vector<int> tmp;
bool permuting(vector<int> &nums, int num) {
    if (0 == nums.size()) {
        red.insert(tmp);
        return 1;
    }
    
    for (int i = 0;i < nums.size();i++) {
        vector<int> cur(nums);
        tmp.push_back(nums[i]);
        cur.erase(cur.begin() + i);
        permuting(cur, num+1);
        tmp.pop_back();
    }
    return 1;
}
vector<vector<int>> permuteUnique(vector<int>& nums)
{
    permuting(nums, 0);
    vector<vector<int>> re;
    for (auto i = red.begin();i != red.end();i++) {
        re.push_back(*i);
    }
    return re;
}

int main() {
    vector<int> A = {1,1,1,2,2};
    vector<vector<int>> result = permuteUnique2(A);
    for (auto r : result) {
        for (auto rr :r) {
            cout << rr << ' ';
        }
        cout << endl;
    }
}
