//
//  Leetcode16_最近3Sum.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest = 2147483647,result;
        bool flag = true;
        
        for (int i = 0; i < nums.size(); i++) {
            
            int target1 = target - nums[i];
            int front = i + 1;
            int back = nums.size() - 1;
            
            while (front < back) {
                
                int sum = nums[front] + nums[back];
                int temp_f = nums[front],temp_b = nums[back];
                
                //targe1-sum最接近0的，为closest
                if (abs(target1-sum) < closest)
                {
                    closest = abs(target1-sum);
                    result = target - target1 + sum;
                }
                
                if (front < back && target1 - sum > 0) front++;
                if (front < back && target1 - sum < 0) back--;
                if (target1 - sum==0) {flag = false;break;}
            }
            if (!flag) break;
        }
        return result;
    }
};
