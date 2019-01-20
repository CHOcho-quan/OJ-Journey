//
//  Leetcode1_TwoSum.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result,a;
        a = nums;
        sort(nums.begin(),nums.end());
        
        int front = 0,back = nums.size()-1;
        while (front < back)
        {
            if (nums[front] + nums[back] == target) break;
            if (nums[front] + nums[back] < target) front++;
            else back--;
            
            //while (front < back && nums[front]==temp_f) front++;
            //while (front < back && nums[back]==temp_b) back--;
        }
        
        bool flag1 = true,flag2 = true;
        for (int i = 0;i < a.size();i++)
        {
            if (nums[front]==a[i] && flag1) {result.push_back(i);flag1 = false;}
            else if (nums[back]==a[i] && flag2) {result.push_back(i);flag2 = false;}
            if (!flag1 && !flag2) break;
        }
        
        return result;    
    }
};
