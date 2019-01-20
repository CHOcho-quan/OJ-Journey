//
//  Leetcode575_分糖果最大种类.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int sum = 0;
        map<int,int> a;
        
        for (int i = 0;i < candies.size();i++)
        {
            a[candies[i]]++;
        }
        
        if (a.size() > candies.size()/2) return candies.size()/2;
        else return a.size();    
    }
};
