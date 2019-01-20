//
//  Leetcode283_移动0.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int sum = 0,d = 0;
        for (int i = 0;i - d < nums.size();i++)
        {
            if (nums[i-d]==0)
            {
                sum++;
                nums.erase(nums.begin()+i-d);
                d++;
            }
        }  
        
        for (int j = 0;j < sum;j++) nums.push_back(0);      
    }
};
