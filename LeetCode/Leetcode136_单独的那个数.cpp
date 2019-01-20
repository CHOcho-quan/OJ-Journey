//
//  Leetcode136_单独的那个数.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = nums[0];
        for (int i = 1;i < nums.size();i++)
        {
            result = result^nums[i];
        }
        return result;
    }
};
