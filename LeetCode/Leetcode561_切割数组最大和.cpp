//
//  Leetcode561_切割数组最大和.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

void sorting(vector<int> &a)
{
    int now = 0,temp_min = a[0],temp;
    
    for (int i = 0;i < a.size();i++)
    {
        for (int j = i;j < a.size();j++)
        {
            if (a[j] < temp_min)
            {
                temp = a[now];
                a[now] = a[j];
                a[j] = temp;
                temp_min = a[j];
            }
        }
        now++;
        temp_min = a[now];
    }
}

int minimum(const int a,const int b)
{
    if (a > b) return b;
    else return a;
}

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum = 0;
        for (int i = 0;i < nums.size();i+=2)
        {
            sum+=minimum(nums[i],nums[i+1]);
        }
        
        return sum;
    }
};
