//
//  Leetcode189_翻转数组.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        int times = k%len;
        for (int i = 0;i < times;i++)
        {
            nums.insert(nums.begin(),nums[nums.size()-1-i]);
        }
        nums.erase(nums.end()-times,nums.end());
    }
};
