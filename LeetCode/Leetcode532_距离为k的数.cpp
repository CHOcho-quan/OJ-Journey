//
//  Leetcode532_距离为k的数.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

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
    int findPairs(vector<int>& nums, int k) {
        int sum = 0,temp;
        bool flag = true,flag2 = false;
        sort(nums.begin(),nums.end());
        if (k==0)
        {
            for (int i = 0;i < nums.size();i++)
            {
                if (i==nums.size()-1) break;
                if (nums[i]==nums[i+1] && flag)
                {
                    temp = nums[i];
                    sum++;
                    flag2 = true;
                }
                if (flag2)
                {
                    if (temp==nums[i+1]) flag = false;
                    else flag = true;
                }
            }
        }
        else
        {
            DeleteTheSame(nums);
            for (int i = 0;i < nums.size();i++)
            {
                for (int j = 0;j < nums.size();j++)
                {
                    if (j==i) continue;
                    else if (abs(nums[i]-nums[j])==k) sum++;
                }
            }	
            sum/=2;
        } 
        return sum;
    }
};
