//
//  Leetcode458_连续的1.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if (nums.size()==0) return 0;
        int ans = 0,sum = 0;
        bool flag;
        
        for (int i = 0;i < nums.size();i++)
        {
            if (nums[i]) sum++;
            else
            {
                ans = max(ans,sum);
                sum = 0;
            }
        }
        ans = max(ans,sum);
        
        return ans;    
    }
};
