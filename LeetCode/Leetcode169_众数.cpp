//
//  Leetcode169_众数.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> r;
        int len = nums.size();
        for (int i = 0;i < len;i++)
        {
            r[nums[i]]++;
            if (r[nums[i]]>len/2) return nums[i];
        }   
    }
};
