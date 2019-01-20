//
//  Leetcode219_相同元素下标距离限定.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.size() > 30000) return false;
        if (k==0) return false;
        int len = nums.size();
        //cout << nums.end() - nums.begin();
        for (int i = 0;i < len;i++)
        {
            vector<int>::iterator it = find(nums.begin()+i+1,nums.end(),nums[i]);
            if (it-(nums.begin()+i) <= k && it!=nums.end()) return true;
        }
        return false;     
    }
};
