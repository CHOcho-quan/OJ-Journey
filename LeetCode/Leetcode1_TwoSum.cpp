//
//  Leetcode1_TwoSum.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> twoSum2(vector<int>& nums, int target) {
    vector<int> result, tmp;
    
    for (int i = 0;i < nums.size();i++) tmp.push_back(nums[i]);
    
    sort(tmp.begin(), tmp.end());
    int f = 0, l = nums.size() - 1;
    
    while (true)
    {
        if (tmp[f] + tmp[l] == target) break;
        
        if (tmp[f] + tmp[l] > target) {
            l--;
            continue;
        }
        
        if (tmp[f] + tmp[l] < target) {
            f++;
            continue;
        }
    }
    
    for (int i = 0;i < nums.size();i++)
    {
        if (tmp[f] == nums[i])
        {
            result.push_back(i);
            continue;
        }
        if (tmp[l] == nums[i])
        {
            result.push_back(i);
            continue;
        }
    }
    
    sort(result.begin(), result.end());
    
    return result;
}

vector<int> twoSum1(vector<int>& nums, int target) {
    vector<int> result;
    bool flag = false;
    
    for (int i = 0;i < nums.size();i++)
    {
        for (int j = 0;j < nums.size();j++)
        {
            if (i != j && nums[i] + nums[j] == target)
            {
                result.push_back(i);
                result.push_back(j);
                flag = true;
                break;
            }
        }
        
        if (flag) break;
    }
    
    return result;
}

int main() {
    vector<int> a = {3, 2, 4};
    int target = 6;
    
    vector<int> r = twoSum2(a, target);
    cout << r[0] << ' ' << r[1];
}
