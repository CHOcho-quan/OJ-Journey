//
//  Leetcode594_最长和谐子串.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

int maxi(int a,int b)
{
    if (a > b) return a;
    else return b;
}

class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int> nums_n;
        map<int,int>::iterator it;
        vector<int> n;
        int map_size = 0;
        
        for (int i = 0;i < nums.size();i++)
        {
            it = nums_n.find(nums[i]);
            if (it==nums_n.end())
            {
                n.push_back(nums[i]);
                nums_n[nums[i]] = 1;
                map_size++;
            }
            else nums_n[nums[i]]++;
        }
        //cout << map_size;
        
        it = nums_n.begin();
        //cout << (*it).second << endl;
        int temp_max = 0,temp,calu = 0;
        //cout << temp_max << endl;
        for (it;calu < n.size();it++,calu++)
        {
            //cout << (*it).first << endl;
            //cout << 111;
            temp = maxi(nums_n[n[calu]]+nums_n[n[calu]-1],nums_n[n[calu]+1]);
            if (temp == nums_n[n[calu]]) continue;
            if (temp > temp_max) temp_max = temp;
        }
        return temp_max;    
    }
};
