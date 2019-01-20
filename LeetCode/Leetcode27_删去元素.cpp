//
//  Leetcode27_删去元素.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        for (int i = 0;i < nums.size();i++)
        {
            if (nums[i]==val)
            {
                nums.erase(nums.begin()+i);
                i--;
                len--;
            }
        }
        return len;
    }
};
