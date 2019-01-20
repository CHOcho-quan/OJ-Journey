//
//  Leetcode414_第三小的数.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

bool Comp(int a,int b)
{
    return a>b;
}

void DeleteTheSame(vector<int> &nums)
{
    for (int i = 0;i < nums.size();i++)
    {
        if (i==nums.size()-1) break;
        if (nums[i]==nums[i+1])
        {
            nums.erase(nums.begin()+i);
            i--;
        }
    }
}

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end(),Comp);
        DeleteTheSame(nums);
        if (nums.size()==1) return nums[0];
        if (nums.size()==2) return nums[0] > nums[1] ? nums[0]:nums[1];
        return nums[2];    
    }
};
