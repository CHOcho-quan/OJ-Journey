//
//  Leetcode349_数组交.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector <int> result;
        vector<int>::iterator it1,it2;
        
        for (int i = 0;i < nums2.size();i++)
        {
            if (find(nums1.begin(),nums1.end(),nums2[i])!=nums1.end())
            {
                if (find(result.begin(),result.end(),nums2[i])==result.end()) result.push_back(nums2[i]);
            }
        }
        
        return result;
    }
};
