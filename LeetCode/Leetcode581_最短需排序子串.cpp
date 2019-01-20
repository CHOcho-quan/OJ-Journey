//
//  Leetcode581_最短需排序子串.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

bool IfMin(vector<int> &nums,int a)
{
    for (int i = 0;i < nums.size();i++)
    {
        if (nums[i] < nums[a]) return false;
    }
    return true;
}


bool IfMax(vector<int> &nums,int a)
{
    for (int i = 0;i < nums.size();i++)
    {
        if (nums[i] > nums[a]) return false;
    }
    return true;
}

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int left = nums[0],len = nums.size(),right = nums[len-1],l=0,r=len-1;
        if (left > right) return len;
        else
        {
            int result = len;
            cout << len <<endl;
            bool flag1 = true,flag2 = true;
            while (l < nums.size() && (flag1||flag2))
            {
                flag1 = false;
                flag2 = false;
                if (nums.size()==0) break;
                if (IfMin(nums,l))
                {
                    result--;
                    nums.erase(nums.begin());
                    flag1 = true;
                }
                if (nums.size()==0) break;
                if (IfMax(nums,nums.size()-1))
                {
                    result--;
                    nums.erase(nums.end()-1);
                    flag2 = true;
                }
            }
            return result;
        }
    }
};
