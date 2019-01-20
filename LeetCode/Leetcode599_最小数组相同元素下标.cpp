//
//  Leetcode599_最小数组相同元素下标.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int sum = 2000;
        vector<string> result;
        for (int i = 0;i < list1.size();i++)
        {
            for (int j = 0;j < list2.size();j++)
            {
                if (list1[i]==list2[j])
                {
                    if (i+j <= sum) {
                        result.push_back(list1[i]);
                        sum = i + j;
                    }
                }
            }
        }
        
        return result;
    }
};
